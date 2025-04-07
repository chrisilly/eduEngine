#ifndef Components
#define Components

/// @brief Handles position, scale, and rotation
class Transform
{
    // float x, y, z;

    glm::vec3 position;
    glm::vec3 scale;
    glm::mat3 rotation;

    void Rotate(float radians, auto axis);
};

/// @brief Handles linear velocity
class Velocity
{
    glm::vec3 velocity;
};

/// @brief A reference to an existing RendeableMesh, a resource that can be shared/reused between entities
class Mesh
{
    std::weak_ptr<eeng::RenderableMesh> mesh;
};

#endif
