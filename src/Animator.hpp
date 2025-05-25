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

    /// @brief Use this so that we Log changes and keep track of `previousState`
    void SetState(AnimationState newState, Mesh& mesh, float time)
    {
        previousState = state;
        state = newState;
                
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
        auto view = registry.view<Mesh, PlayerController>();
        for(auto [entity, mesh, playerController] : view.each())
        {
            switch (state)
            {
            case AnimationState::Jump:
                if(!Transitioning())
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
                SetState(AnimationState::Idle, mesh, time);
                break;
            }
            
            if(Transitioning()) UpdateBlendTimer(deltaTime);

            mesh.mesh->animateBlend(
                previousState,
                state,
                time,
                time,
                blendFactor
            );
            
            ImGui::Text(state == AnimationState::Idle ? "Idle" : state == AnimationState::Walk ? "Walking" : "Jumping");
            ImGui::Text("Blend Factor: %f", blendFactor);
        }
    }

    bool Transitioning()
    {
        return blendTimer < blendDuration;
    }

    void RenderUI()
    {
        ImGui::SliderFloat("Animation BlendFactor", &blendFactor, 0.0f, 1.0f);
    }
};

#endif