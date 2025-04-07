#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

// #include <entt/entt.hpp>
// #include <glm/glm.hpp>
#include "ForwardRenderer.hpp"

#if NO_ENTITY_RENDERER == 0
class EntityRenderer
{
    std::shared_ptr<eeng::ForwardRenderer> forwardRenderer;

    public:
    // EntityRenderer();
    // EntityRenderer(std::shared_ptr<entt::registry> registry);
    EntityRenderer(std::shared_ptr<eeng::ForwardRenderer> forwardRenderer);
    
    void render(std::shared_ptr<entt::registry> registry);
};
#endif

#endif