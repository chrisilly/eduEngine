#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <entt/fwd.hpp>
#include <glm/glm.hpp>
#include <string>
#include "RenderableMesh.hpp"

/// @brief Handles position, scale, and rotation
struct Transform
{
    /// @brief Call updateTransform() after changing this. Do not use this for rendering an entity; use transform for that
    glm::vec3 position;
    /// @brief Call updateTransform() after changing this. Do not use this for rendering an entity; use transform for that
    glm::vec3 scale;
    /// @brief Call updateTransform() after changing this. Do not use this for rendering an entity; use transform for that
    glm::mat3 rotation;

    /// @brief Use this when rendering the entity
    glm::mat4 transform;

    const glm::vec3 forward = { 0.0f, 0.0f, -1.0f };
    const glm::vec3 right = { -1.0f, 0.0f, 0.0f };

public:
    Transform() : position(0.0f), scale(1.0f), rotation(1.0f), transform(1.0f) {}
    Transform(const glm::vec3& position, const glm::vec3& scale, const glm::mat3& rotation)
        : position(position), scale(scale), rotation(rotation), transform(1.0f) { updateTransform(); }

    /// @brief You have to call this after editing position, scale, or rotation if you want to see the changes reflected in the game
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
