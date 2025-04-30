#ifndef ENTITY_RENDERER_H
#define ENTITY_RENDERER_H

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "ForwardRenderer.hpp"
#include "Components.h"
#include "ShapeRenderer.hpp"

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

    void renderBones(entt::registry& registry, ShapeRendering::ShapeRenderer& shapeRenderer)
    {
        float axisLength = 25.0f;

        auto view = registry.view<Transform, Mesh>();
        for(auto [entity, transform, mesh] : view.each())
        {
            for(int i = 0; i < mesh.mesh->boneMatrices.size(); ++i)
            {
                auto IBinverse = glm::inverse(mesh.mesh->m_bones[i].inversebind_tfm);
                glm::mat4 global = transform.transform * mesh.mesh->boneMatrices[i] * IBinverse;
                glm::vec3 position = glm::vec3(global[3]);
    
                glm::vec3 right     = glm::vec3(global[0]); // X
                glm::vec3 up        = glm::vec3(global[1]); // Y
                glm::vec3 forward   = glm::vec3(global[2]); // Z
    
                shapeRenderer.push_states(ShapeRendering::Color4u::Red);
                shapeRenderer.push_line(position, position + axisLength * right);
    
                shapeRenderer.push_states(ShapeRendering::Color4u::Green);
                shapeRenderer.push_line(position, position + axisLength * up);
    
                shapeRenderer.push_states(ShapeRendering::Color4u::Blue);
                shapeRenderer.push_line(position, position + axisLength * forward);
    
                shapeRenderer.pop_states<ShapeRendering::Color4u>();
                shapeRenderer.pop_states<ShapeRendering::Color4u>();
                shapeRenderer.pop_states<ShapeRendering::Color4u>();
            }
        }
    }
};

#endif