#pragma once
#include "../Common/Object.h"

class Player : public Object {
public:
    Player();

    void Update(const char* keys, Camera& camera); // keysを引数として受け取る

private:
    float speed_ = 5.0f;
};
