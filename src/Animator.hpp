#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <entt/entt.hpp>
#include "Log.hpp"
#include "Components.h"
#include "InputManager.hpp"
#include "PlayerController.hpp"
#include "NonPlayerController.hpp"

enum AnimationState { Idle, Walk, Jump };

class AnimationStateMachine
{
    entt::entity entity;
    
    /// @brief Use SetState() to change the value of this
    AnimationState state = AnimationState::Idle;
    AnimationState previousState = state;
    eeng::InputManager input;

    void Idle()
    {

    }

    void HandleJump()
    {

    }

    void Walk()
    {

    }

    /// @brief Use this so that we Log changes and keep track of `previousState`
    void SetState(AnimationState newState)
    {
        previousState = state;
        state = newState;
        eeng::Log("Animation state changed from %s to %s", previousState, state);
    }

public:
    AnimationStateMachine(entt::entity& entity, eeng::InputManager& input) : entity(entity), input(input) {}

    void Update(entt::registry& registry)
    {
        auto view = registry.view<Mesh, PlayerController>();
        for(auto [entity, mesh, playerController] : view.each())
        {
            switch (state)
            {
            case AnimationState::Jump:
                // animate blend from previous state to new state
                HandleJump();

                // if(0.5s passed) state = previousState;
                break;
                case AnimationState::Walk:
                // animate blend from previous state to new state
                Walk();

                if(playerController.pressingJump(input)) state = AnimationState::Jump;
                if(!playerController.pressingWalk(input)) state = AnimationState::Idle;
                break;
                case AnimationState::Idle:
                // animate blend from previous state to new state
                Idle();

                if(playerController.pressingJump(input)) state = AnimationState::Jump;
                if(playerController.pressingWalk(input)) state = AnimationState::Walk;
                break;
            default:
                break;
            }
        }
    }
};

#endif