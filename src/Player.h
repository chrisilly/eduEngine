#ifndef PLAYER_H
#define PLAYER_H

#include "Components.h"

class Player
{
    Transform transform;
    Velocity velocity;
    Mesh mesh;

public:
    Player();
    // ~Player();
};

#endif
