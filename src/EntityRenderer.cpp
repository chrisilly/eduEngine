#include "EntityRenderer.hpp"
#include "Components.h"
#include "glmcommon.hpp"

void EntityRenderer::renderEntities(entt::registry& registry, eeng::ForwardRenderer forwardRenderer)
{
    // Go through all entities
    auto view = registry.view<Transform, Mesh>();
    for (auto entity : view)
    {
        auto& transform = view.get<Transform>(entity);
        auto& mesh = view.get<Mesh>(entity);

        glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), transform.position) *
            glm::mat4(transform.rotation) *
            glm::scale(glm::mat4(1.0f), transform.scale);

        // Render
        forwardRenderer.renderMesh(mesh.mesh, modelMatrix);
        // I'm not rendering AABB
    }
}