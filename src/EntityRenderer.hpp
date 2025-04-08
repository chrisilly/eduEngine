#ifndef ENTITY_RENDERER_HPP
#define ENTITY_RENDERER_HPP

#include <entt/entt.hpp>
#include "ForwardRenderer.hpp"

class EntityRenderer 
{

public:
    void renderEntities(entt::registry& registry, eeng::ForwardRenderer forwardRenderer);
};

#endif