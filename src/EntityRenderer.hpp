#ifndef ENTITY_RENDERER_H
#define ENTITY_RENDERER_H

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "ForwardRenderer.hpp"
#include "Components.h"

class EntityRenderer
{
public:
    void renderEntities(entt::registry& registry, eeng::ForwardRenderer& forwardRenderer)
    {
        auto view = registry.view<Mesh, Transform>();
        for (auto entity : view)
        {
            const auto& mesh = view.get<Mesh>(entity);
            const auto& transform = view.get<Transform>(entity);

            forwardRenderer.renderMesh(mesh.mesh, transform.transform);
            // I'm not rendering AABB
        }
    }
};

#endif