#include <format>
#include <raylib.h>

#include "vector.h"

constexpr auto WIDTH = 1280;
constexpr auto HEIGHT = 720;

int main() {
    InitWindow(WIDTH, HEIGHT, "Galileo");

    galileo::vector<int, 2> v(2, 1);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);


        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
