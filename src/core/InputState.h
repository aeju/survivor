#pragma once

// 값 타입. 매 프레임 main 루프가 스택에 만들고 프레임 끝에 사라짐
struct InputState {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
};
