#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <entt/fwd.hpp>
#include <glm/glm.hpp>
#include <string>
#include "RenderableMesh.hpp"

/// @brief Handles position, scale, and rotation
class Transform
{
    // float x, y, z;

    glm::vec3 position;
    glm::vec3 scale;
    glm::mat3 rotation;

public:
    Transform();
    // Transform(float x, float y, float z) : {}
    // void Rotate(float radians, auto axis);
};

/// @brief Handles linear velocity
class Velocity
{
    // glm::vec3 velocity;
};

/// @brief A reference to an existing RendeableMesh, a resource that can be shared/reused between entities
class Mesh
{
    std::shared_ptr<eeng::RenderableMesh> mesh; // if you want to own the resource
    // std::weak_ptr<eeng::RenderableMesh> mesh; // if you want to reference an existing resource without owning it
    
public:
    Mesh();
    // ~Mesh() { mesh.reset(); } // Destructor to release the weak pointer
};

#endif
