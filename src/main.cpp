#include <iostream>
#include <raylib.h>
#include <format>

#include "vector.h"

constexpr auto WIDTH = 1280;
constexpr auto HEIGHT = 720;

using galileo::vec2i;
using galileo::vec3i;

int main() {
    InitWindow(1280, 720, "Galileo");

    // Base Canonica :)
    static const vec3i i{1, 0, 0};
    static const vec3i j{0, 1, 0};
    static const vec3i k{0, 0, 1};

    // Origine
    static const vec2i o{WIDTH/2, HEIGHT/2};

    // Vettore
    vec3i v = i * 10 + j * 5 + k * 2;

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(WHITE);

            DrawLineEx(
                    static_cast<Vector2>(o),
                    static_cast<Vector2>(i * 50 + o),
                    2.f,
                    RED
            );

            DrawLineEx(
                    static_cast<Vector2>(o),
                    static_cast<Vector2>(j * 50 + o),
                    2.f,
                    BLUE
            );

            DrawLineEx(
                    static_cast<Vector2>(o),
                    static_cast<Vector2>(v * 50 + o),
                    2.f,
                    BLACK
            );
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
