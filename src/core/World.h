#pragma once

#include <cstdint>
#include <random>
#include <vector>

#include "core/Enemy.h"
#include "core/InputState.h"
#include "core/Player.h"
#include "core/Vec2.h"

// 소유자: main()의 지역 변수. 해제: main() 종료 시
class World {
public:
    // TODO: JSON 로딩 단계에서 data/*.json으로 이동
    static constexpr float kSpawnInterval = 0.1f;   // 초
    static constexpr std::size_t kMaxEnemies = 500;
    // 플레이어 중심 생성 반지름(픽셀). 800x600 화면의 대각선 절반(500)보다 커서 화면 밖에서 생성됨
    static constexpr float kSpawnDistance = 550.0f;
    // 고정 시드: 전수 비교/공간 분할 성능 비교 시 같은 적 배치를 재현하기 위함
    static constexpr std::uint32_t kRngSeed = 12345u;

    explicit World(Vec2 playerStart);

    void update(const InputState& input, float dt);

    const Player& player() const { return player_; }
    const std::vector<Enemy>& enemies() const { return enemies_; }

private:
    void updateSpawning(float dt);
    void spawnEnemy();

    Player player_;               // 값으로 소유
    std::vector<Enemy> enemies_;  // 값으로 소유. 생성자에서 kMaxEnemies만큼 reserve
    float spawnTimer_ = 0.0f;
    std::mt19937 rng_;
};
