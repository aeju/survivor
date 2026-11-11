#pragma once

#include "core/InputState.h"
#include "core/Player.h"
#include "core/Vec2.h"

// 소유자: main()의 지역 변수. 해제: main() 종료 시
class World {
public:
    explicit World(Vec2 playerStart) : player_(playerStart) {}

    void update(const InputState& input, float dt);

    const Player& player() const { return player_; }

private:
    Player player_;  // 값으로 소유
};
