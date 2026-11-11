#include "raylib.h"

#include "core/InputState.h"
#include "core/World.h"
#include "render/Renderer.h"

namespace {
constexpr int kScreenWidth = 800;
constexpr int kScreenHeight = 600;

InputState readInput() {
    InputState input;
    input.up = IsKeyDown(KEY_W);
    input.down = IsKeyDown(KEY_S);
    input.left = IsKeyDown(KEY_A);
    input.right = IsKeyDown(KEY_D);
    return input;
}
}  // namespace

int main() {
    InitWindow(kScreenWidth, kScreenHeight, "survivor");
    SetTargetFPS(60);

    World world({0.0f, 0.0f});
    Renderer renderer(kScreenWidth, kScreenHeight);

    while (!WindowShouldClose()) {
        const InputState input = readInput();
        world.update(input, GetFrameTime());
        renderer.draw(world);
    }

    CloseWindow();
    return 0;
}
