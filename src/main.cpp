#include "raylib.h"

#include "core/InputState.h"
#include "core/Player.h"

namespace {
constexpr int kScreenWidth = 800;
constexpr int kScreenHeight = 600;
}

int main() {
    InitWindow(kScreenWidth, kScreenHeight, "survivor");
    SetTargetFPS(60);

    Player player({kScreenWidth / 2.0f, kScreenHeight / 2.0f});

    while (!WindowShouldClose()) {
        InputState input;
        input.up = IsKeyDown(KEY_W);
        input.down = IsKeyDown(KEY_S);
        input.left = IsKeyDown(KEY_A);
        input.right = IsKeyDown(KEY_D);

        player.update(input, GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);
        const Vec2 p = player.pos();
        DrawCircleV({p.x, p.y}, Player::kRadius, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
