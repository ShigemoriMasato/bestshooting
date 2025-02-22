#include "Player.h"

Player::Player()
    : Object(Vector2(32, 32), kFillModeSolid, ObjectType::kCircle, {}) {
    pos_ = { 640, 360 }; // 初期位置を画面中央に設定
}

void Player::Update(const char* keys, Camera& camera) {
    if (keys[DIK_W]) { pos_.y += speed_; }
    if (keys[DIK_S]) { pos_.y -= speed_; }
    if (keys[DIK_A]) { pos_.x -= speed_; }
    if (keys[DIK_D]) { pos_.x += speed_; }

	Ready(camera, 255);
}
