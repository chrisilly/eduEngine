#ifndef PLAYERCONTROLLER_HPP
#define PLAYERCONTROLLER_HPP

#include <entt/entt.hpp>
#include "GameBase.h"
#include "Controller.hpp"

class PlayerController 
{

entt::entity player;

public:
    PlayerController(entt::entity player) : player(player) {}

    /// @brief Updates player velocity. Use Controller to update position
    void Update(eeng::InputManager& input, entt::registry& registry, float deltaTime)
    {
        using Key = eeng::InputManager::Key;
        const bool W = input.IsKeyPressed(Key::W);
        const bool A = input.IsKeyPressed(Key::A);
        const bool S = input.IsKeyPressed(Key::S);
        const bool D = input.IsKeyPressed(Key::D);

        auto& transform = registry.get<Transform>(player);
        auto& velocity = registry.get<Velocity>(player);
        
        if (W || A || S || D)
        {
            if(W) velocity.velocity += /* camera rotation matrix * */ transform.forward * deltaTime;
            if(A) velocity.velocity += /* camera rotation matrix * */ transform.right   * deltaTime;
            if(S) velocity.velocity -= /* camera rotation matrix * */ transform.forward * deltaTime;
            if(D) velocity.velocity -= /* camera rotation matrix * */ transform.right   * deltaTime;
        }

        glm::vec3 zStop = { 1.0f, 1.0f, 0.0f };
        glm::vec3 xStop = { 0.0f, 1.0f, 1.0f };
        // glm::vec3 yStop = { 1.0f, 0.0f, 1.0f };

        // We do this because we don't the player to keep moving when we stop pressing the keys
        if(!W && !S)
            velocity.velocity *= zStop;
        if(!A && !D)
            velocity.velocity *= xStop;
    }
};

#endif
