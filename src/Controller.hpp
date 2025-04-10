#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <entt/entt.hpp>
#include "Components.h"

class Controller
{
    public:
        void update(entt::registry& registry, entt::entity& entity)
        {
            registry.get<Transform>(entity).position += registry.get<Velocity>(entity).velocity /** deltaTime*/;
            registry.get<Transform>(entity).updateTransform();
        }
};

#endif