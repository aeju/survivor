#pragma once

#include "core/World.h"

// 소유자: main()의 지역 변수. 해제: main() 종료 시
class Renderer {
public:
    Renderer(int screenW, int screenH) : screenW_(screenW), screenH_(screenH) {}

    // 한 프레임 전체를 그림 (BeginDrawing ~ EndDrawing). World는 읽기만 함
    void draw(const World& world) const;

private:
    int screenW_;
    int screenH_;
};
