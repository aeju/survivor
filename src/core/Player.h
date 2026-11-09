#pragma once

#include "core/InputState.h"
#include "core/Vec2.h"

// 소유자: main()의 지역 변수. 해제: main() 종료 시
class Player {
public:
    // TODO: JSON 로딩 단계에서 data/*.json으로 이동
    static constexpr float kSpeed = 200.0f;  // 픽셀/초
    static constexpr float kRadius = 16.0f;  // 픽셀

    explicit Player(Vec2 startPos) : pos_(startPos) {}

    void update(const InputState& input, float dt);

    Vec2 pos() const { return pos_; }

private:
    Vec2 pos_;
};
