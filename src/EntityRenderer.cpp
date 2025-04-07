#include "EntityRenderer.h"
#include "ForwardRenderer.hpp"

#if NO_ENTITY_RENDERER == 0
// EntityRenderer::EntityRenderer()
//     : forwardRenderer(std::make_shared<eeng::ForwardRenderer>())
// {
//     forwardRenderer->init("shaders/phong_vert.glsl", "shaders/phong_frag.glsl");
// }

EntityRenderer::EntityRenderer(std::shared_ptr<eeng::ForwardRenderer> forwardRenderer)
    : forwardRenderer(forwardRenderer)
{
}

void EntityRenderer::render(std::shared_ptr<entt::registry> registry)
{
    auto view = registry->view<Transform, Mesh>();
    for (auto entity : view)
    {
        const auto &transform = view.get<Transform>(entity);
        const auto &mesh = view.get<Mesh>(entity);

        glm::mat4 entityWorldMatrix = glm::mat4(1.0f);
        entityWorldMatrix = glm::translate(entityWorldMatrix, transform.position);
        entityWorldMatrix = glm::scale(entityWorldMatrix, transform.scale);
        entityWorldMatrix = entityWorldMatrix * glm::mat4(transform.rotation); // Assuming rotation is a mat3

        forwardRenderer->renderMesh(mesh.mesh, entityWorldMatrix);
    }
}
#endif