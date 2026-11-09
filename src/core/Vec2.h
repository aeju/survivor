#pragma once

#include <cmath>

// 값 타입. 소유·해제 개념 없음 (스택/멤버로 복사되어 쓰임)
struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;

    constexpr Vec2() = default;
    constexpr Vec2(float x_, float y_) : x(x_), y(y_) {}

    constexpr Vec2 operator+(Vec2 o) const { return {x + o.x, y + o.y}; }
    constexpr Vec2 operator-(Vec2 o) const { return {x - o.x, y - o.y}; }
    constexpr Vec2 operator*(float s) const { return {x * s, y * s}; }
    Vec2& operator+=(Vec2 o) { x += o.x; y += o.y; return *this; }

    float length() const { return std::sqrt(x * x + y * y); }

    // 길이 0이면 영벡터 반환
    Vec2 normalized() const {
        const float len = length();
        return len > 0.0f ? Vec2{x / len, y / len} : Vec2{};
    }
};
