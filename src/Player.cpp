#include "Player.h"

Player::Player()
{
    // Initialize core components (position, shape, etc.)
    mesh = Mesh();
    transform = Transform();

	// mesh->load("assets/Animals/Horse.fbx");
	// transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	// transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	// transform.rotation = glm::mat3();
}