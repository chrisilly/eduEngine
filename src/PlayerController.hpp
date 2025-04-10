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

        if (W || A || S || D)
        {
            auto& transform = registry.get<Transform>(player);
            auto& velocity = registry.get<Velocity>(player);

            if(W) velocity.velocity += /* camera rotation matrix * */ transform.forward * deltaTime;
            if(A) velocity.velocity += /* camera rotation matrix * */ transform.right   * deltaTime;
            if(S) velocity.velocity -= /* camera rotation matrix * */ transform.forward * deltaTime;
            if(D) velocity.velocity -= /* camera rotation matrix * */ transform.right   * deltaTime;
        }
    }
};

#endif
