#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <entt/fwd.hpp>
#include <glm/glm.hpp>
#include <string>
#include "RenderableMesh.hpp"

/// @brief Handles position, scale, and rotation
struct Transform
{
    glm::vec3 position;
    glm::vec3 scale;
    glm::mat3 rotation;

    glm::mat4 transform;

public:
    Transform() : position(0.0f), scale(1.0f), rotation(1.0f), transform(1.0f) {}
    Transform(const glm::vec3& position, const glm::vec3& scale, const glm::mat3& rotation)
        : position(position), scale(scale), rotation(rotation), transform(1.0f) { updateTransform(); }

    void updateTransform()
    {
        transform = glm::translate(glm::mat4(1.0f), position) *
                    glm::mat4(rotation) *
                    glm::scale(glm::mat4(1.0f), scale);
    }
};

/// @brief Handles linear velocity
struct Velocity
{
    glm::vec3 velocity;
};

/// @brief A reference to an existing RendeableMesh, a resource that can be shared/reused between entities
struct Mesh
{
    std::shared_ptr<eeng::RenderableMesh> mesh; // if you want to own the resource
    // std::weak_ptr<eeng::RenderableMesh> mesh; // if you want to reference an existing resource without owning it
};

#endif
