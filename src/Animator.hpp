#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include "Log.hpp"
#include "Components.h"
#include "InputManager.hpp"
#include "PlayerController.hpp"
#include "NonPlayerController.hpp"

enum AnimationState { Tpose, Idle, Walk, Jump };

class Animator
{
    float blendFactor = 1.0f;
    float blendTimer = 0.0f;
    float blendDuration = 0.3f;
    
    /// @brief Use SetState() to change the value of this
    AnimationState state = AnimationState::Idle;
    AnimationState previousState = state;

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
    void SetState(AnimationState newState, Mesh& mesh, float time)
    {
        previousState = state;
        state = newState;

        mesh.mesh->animateBlend(mesh.mesh->getNbrAnimations() < 3 ? previousState : 1, mesh.mesh->getNbrAnimations() < 3 ? state : 1, time, time, blendFactor); // This seems to do nothing?
        
        blendTimer = 0.0f;
    }

    void UpdateBlendTimer(float deltaTime)
    {
        blendTimer += deltaTime;
        blendFactor = glm::clamp(blendTimer / blendDuration, 0.0f, 1.0f);
    }

public:
    Animator() = default;

    void update(entt::registry& registry, eeng::InputManager& input, float time, float deltaTime)
    {
        UpdateBlendTimer(deltaTime);
        
        auto view = registry.view<Mesh, PlayerController>();
        for(auto [entity, mesh, playerController] : view.each())
        {
            switch (state)
            {
            case AnimationState::Jump:
                if(blendTimer >= blendDuration)
                {
                    SetState(previousState, mesh, time);
                }
                break;

            case AnimationState::Walk:
                if(playerController.pressingJump(input)) SetState(AnimationState::Jump, mesh, time);
                if(!playerController.pressingWalk(input)) SetState(AnimationState::Idle, mesh, time);
                break;

            case AnimationState::Idle:
                if(playerController.pressingJump(input)) SetState(AnimationState::Jump, mesh, time);
                if(playerController.pressingWalk(input)) SetState(AnimationState::Walk, mesh, time);
                break;

            default:
                SetState(AnimationState::Tpose, mesh, time);
                break;
            }

            mesh.mesh->animate(state, time);
            ImGui::Text(state == AnimationState::Idle ? "Idle" : state == AnimationState::Walk ? "Walking" : "Jumping");
        }
    }

    void RenderUI()
    {
        ImGui::SliderFloat("Animation BlendFactor", &blendFactor, 0.0f, 1.0f);
    }
};

#endif