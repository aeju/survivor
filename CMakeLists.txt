cmake_minimum_required(VERSION 3.20)
project(survivor C CXX)  # raylib이 C로 빌드되므로 C도 활성화

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- raylib 5.5 ---
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(raylib)

# --- game_core: raylib 의존 없음 ---
add_library(game_core STATIC
    src/core/Player.cpp
    src/core/Enemy.cpp
    src/core/World.cpp
)
target_include_directories(game_core PUBLIC src)

# --- survivor 실행 파일 ---
add_executable(survivor
    src/main.cpp
    src/render/Renderer.cpp
)
target_link_libraries(survivor PRIVATE game_core raylib)

if(MSVC)
    # /utf-8: 소스(한글 주석)를 CP949가 아닌 UTF-8로 해석
    target_compile_options(game_core PRIVATE /W4 /utf-8)
    target_compile_options(survivor PRIVATE /W4 /utf-8)
endif()
