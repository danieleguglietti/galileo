#include <raylib.h>

int main() {
    InitWindow(1280, 720, "Galileo");

    while (!WindowShouldClose()) {
        BeginDrawing(); {
            ClearBackground(Color { 110, 37, 206, 255 });
            DrawText("skaman insegna Vulkan", 550, 360, 16, Color { 255, 255, 255, 255 });
        } EndDrawing();
    }

    CloseWindow();

    return 0;
}
