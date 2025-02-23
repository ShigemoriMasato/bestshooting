#pragma once
#include "Object.h"

class Player : public Object {
public:
    Player();

    void Update(const char* keys, Camera& camera); // keysを引数として受け取る

private:
    float speed_;
};
