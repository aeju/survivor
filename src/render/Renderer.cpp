#include "render/Renderer.h"

#include <cmath>

#include "raylib.h"

namespace {
// 표시용 값: 바꿔도 게임 결과에 영향 없음
constexpr float kGridSpacing = 64.0f;            // 픽셀
constexpr Color kGridColor = {220, 220, 220, 255};
constexpr Color kAxisColor = {170, 170, 170, 255};  // 월드 원점을 지나는 선
constexpr Color kEnemyColor = DARKBLUE;

// 카메라에 보이는 월드 영역에만 격자선을 그림
void drawGrid(const Camera2D& camera, int screenW, int screenH) {
    const float left = camera.target.x - camera.offset.x / camera.zoom;
    const float top = camera.target.y - camera.offset.y / camera.zoom;
    const float right = left + screenW / camera.zoom;
    const float bottom = top + screenH / camera.zoom;

    const float startX = std::floor(left / kGridSpacing) * kGridSpacing;
    const float startY = std::floor(top / kGridSpacing) * kGridSpacing;

    for (float x = startX; x <= right; x += kGridSpacing) {
        const Color c = (std::fabs(x) < 0.5f) ? kAxisColor : kGridColor;
        DrawLineV({x, top}, {x, bottom}, c);
    }
    for (float y = startY; y <= bottom; y += kGridSpacing) {
        const Color c = (std::fabs(y) < 0.5f) ? kAxisColor : kGridColor;
        DrawLineV({left, y}, {right, y}, c);
    }
}
}  // namespace

void Renderer::draw(const World& world) const {
    const Vec2 p = world.player().pos();

    // 플레이어를 화면 중앙에 고정하는 카메라 (매 프레임 새로 계산, 스무딩 없음)
    Camera2D camera{};
    camera.target = {p.x, p.y};
    camera.offset = {screenW_ / 2.0f, screenH_ / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);
    drawGrid(camera, screenW_, screenH_);
    // 적을 먼저 그려 플레이어가 위에 보이게 함
    for (const Enemy& e : world.enemies()) {
        const Vec2 ep = e.pos();
        DrawCircleV({ep.x, ep.y}, Enemy::kRadius, kEnemyColor);
    }
    DrawCircleV({p.x, p.y}, Player::kRadius, MAROON);
    EndMode2D();

    EndDrawing();
}
