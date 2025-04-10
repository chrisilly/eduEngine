#ifndef NON_PLAYER_CONTROLLER_HPP
#define NON_PLAYER_CONTROLLER_HPP

#include <entt/entt.hpp>
#include "Components.h"

class NonPlayerController
{

entt::entity character;
float speed = 1.0f;
std::list<glm::vec3> path;
bool loop;

bool isCloseToTarget(entt::registry& registry, glm::vec3 target, float threshold = 1.5f)
{
    auto& transform = registry.get<Transform>(character);
    return glm::length(target - transform.position) < threshold;
}

public:
    NonPlayerController(entt::entity& character, bool loop = false) : character(character), loop(loop) {}

    void MoveTo(glm::vec3 location)
    {
        path.push_back(location);
    }

    void Update(entt::registry& registry, float deltaTime)
    {
        if(path.empty()) return;

        auto& transform = registry.get<Transform>(character);
        auto& velocity = registry.get<Velocity>(character);

        glm::vec3 target = path.front();
        glm::vec3 direction = glm::normalize(target - transform.position);

        velocity.velocity = direction * speed * deltaTime;

        if(isCloseToTarget(registry, target))
        {
            velocity.velocity = glm::vec3(0.0f);
            if(loop) { path.push_back(path.front()); }
            path.pop_front();
        }
    }
};

#endif