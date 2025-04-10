#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <entt/entt.hpp>
#include "Components.h"

class Controller
{
    public:
        void updateEntity(entt::registry& registry, entt::entity& entity)
        {
            registry.get<Transform>(entity).position += registry.get<Velocity>(entity).velocity /** deltaTime*/;
            registry.get<Transform>(entity).updateTransform();
        }

        void update(entt::registry& registry)
        {
            auto view = registry.view<Transform, Velocity>();
            for (auto entity : view)
            {
                auto& transform = view.get<Transform>(entity);
                auto& velocity = view.get<Velocity>(entity);

                transform.position += velocity.velocity; // * deltaTime;
                transform.updateTransform();
            }
        }
};

#endif