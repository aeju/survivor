#include "core/Player.h"

void Player::update(const InputState& input, float dt) {
    Vec2 dir;
    if (input.up)    dir.y -= 1.0f;
    if (input.down)  dir.y += 1.0f;
    if (input.left)  dir.x -= 1.0f;
    if (input.right) dir.x += 1.0f;

    // 대각선 이동이 빨라지지 않도록 정규화
    pos_ += dir.normalized() * (kSpeed * dt);
}
