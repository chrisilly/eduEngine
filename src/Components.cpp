#include "Components.h"

Mesh::Mesh()
{
    mesh = std::make_shared<eeng::RenderableMesh>();
    mesh->load("assets/Animals/Horse.fbx", false);
}

Velocity::Velocity()
{
    velocity = glm::vec3(0.0f, 0.0f, 0.0f);
}

/// @brief No scaling, no rotation, positioned in origo
Transform::Transform()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    rotation = glm::mat3(1.0f); // Identity matrix for no rotation
}