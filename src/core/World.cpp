#include "core/World.h"

#include <cmath>

World::World(Vec2 playerStart) : player_(playerStart), rng_(kRngSeed) {
    enemies_.reserve(kMaxEnemies);
}

void World::update(const InputState& input, float dt) {
    player_.update(input, dt);
    updateSpawning(dt);

    const Vec2 target = player_.pos();
    for (Enemy& e : enemies_) {
        e.update(target, dt);
    }
}

void World::updateSpawning(float dt) {
    if (enemies_.size() >= kMaxEnemies) {
        return;  // 최대 수 도달: 생성 중단, 타이머도 쌓지 않음
    }
    spawnTimer_ += dt;
    // 프레임이 늦어져도 생성 속도가 유지되도록 쌓인 만큼 생성
    while (spawnTimer_ >= kSpawnInterval && enemies_.size() < kMaxEnemies) {
        spawnTimer_ -= kSpawnInterval;
        spawnEnemy();
    }
}

void World::spawnEnemy() {
    constexpr float kTwoPi = 6.28318530718f;
    std::uniform_real_distribution<float> angleDist(0.0f, kTwoPi);
    const float angle = angleDist(rng_);
    const Vec2 offset{std::cos(angle) * kSpawnDistance, std::sin(angle) * kSpawnDistance};
    enemies_.emplace_back(player_.pos() + offset);
}
