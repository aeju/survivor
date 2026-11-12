#include "core/Enemy.h"

void Enemy::update(Vec2 target, float dt) {
    pos_ += (target - pos_).normalized() * (kSpeed * dt);
}
