#pragma once

#include "core/Vec2.h"

// 소유자: World::enemies_ (std::vector 원소, 값). 해제: World 소멸 시
class Enemy {
public:
    // TODO: JSON 로딩 단계에서 data/*.json으로 이동
    static constexpr float kSpeed = 80.0f;   // 픽셀/초 (플레이어보다 느리게)
    static constexpr float kRadius = 10.0f;  // 픽셀 (나중에 충돌 판정에도 사용)

    explicit Enemy(Vec2 startPos) : pos_(startPos) {}

    // target 방향으로 kSpeed만큼 이동. target과 같은 위치면 제자리
    void update(Vec2 target, float dt);

    Vec2 pos() const { return pos_; }

private:
    Vec2 pos_;
};
