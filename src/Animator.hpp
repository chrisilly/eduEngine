#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <entt/entt.hpp>
#include "Log.hpp"
#include "Components.h"
#include "InputManager.hpp"

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
        using Key = eeng::InputManager::Key;

        if(input.IsKeyPressed(Key::Space)) // if velocity.y > 0 ?
            SetState(AnimationState::Jump);
        
        bool W = input.IsKeyPressed(Key::W);
        bool A = input.IsKeyPressed(Key::A);
        bool S = input.IsKeyPressed(Key::S);
        bool D = input.IsKeyPressed(Key::D);

        if(W || A || S || D) // if velocity.x != 0 ?
            SetState(AnimationState::Walk);
    }

    void Jump()
    {
        // if 0.5s passed
        state = previousState;
    }

    void Walk()
    {
        using Key = eeng::InputManager::Key;

        if(input.IsKeyPressed(Key::Space)) // if velocity.y > 0 ?
            SetState(AnimationState::Jump);

        bool W = input.IsKeyPressed(Key::W);
        bool A = input.IsKeyPressed(Key::A);
        bool S = input.IsKeyPressed(Key::S);
        bool D = input.IsKeyPressed(Key::D);

        if(!W && !A && !S && !D) // if velocity.x = 0 ?
            SetState(AnimationState::Idle);
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

    void Update()
    {
        switch (state)
        {
        case AnimationState::Jump:
            // animate blend from previous state to new state
            Jump();
            break;
            case AnimationState::Walk:
            // animate blend from previous state to new state
            Walk();
            break;
            case AnimationState::Idle:
            // animate blend from previous state to new state
            Idle();
            break;
        default:
            break;
        }
    }
};

#endif