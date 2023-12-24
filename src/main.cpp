#include <format>
#include <iostream>

#include <raylib.h>

#include "vector.h"

constexpr auto WIDTH = 1280;
constexpr auto HEIGHT = 720;

using galileo::vec2f;
using galileo::vec3f;

Camera3D init_camera(Vector3 o, Vector3 target);

int main() {
    InitWindow(1280, 720, "Galileo");

    // Base Canonica :)
    static const vec3f i{1.f, 0.f, 0.f};
    static const vec3f j{0.f, 1.f, 0.f};
    static const vec3f k{0.f, 0.f, 1.f};

    // Origine
    static const vec3f o{0.f, 0.f, 0.f};

    // Vettore
    static const auto v = i * 2 + j * 3 + k * 5;
    static const auto w = i * 3 + j * 2 + k * 1;

    static const auto d = w - v;

    // Camera
    Camera3D camera = init_camera(static_cast<Vector3>(o + vec3f{10.f}), static_cast<Vector3>(o));

    DisableCursor();

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
            {
                DrawGrid(100, 1.0f);

                DrawLine3D(static_cast<Vector3>(o), static_cast<Vector3>(o + v), BLACK);
                DrawLine3D(static_cast<Vector3>(o), static_cast<Vector3>(o + w), BLACK);

                DrawLine3D(static_cast<Vector3>(o + v), static_cast<Vector3>(v + d), RED);

                DrawLine3D(static_cast<Vector3>(o), static_cast<Vector3>(o + i), RED);
                DrawLine3D(static_cast<Vector3>(o), static_cast<Vector3>(o + j), GREEN);
                DrawLine3D(static_cast<Vector3>(o), static_cast<Vector3>(o + k), BLUE);
            }
            EndMode3D();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

Camera3D init_camera(Vector3 o, Vector3 target) {
    Camera3D camera = { 0 };

    camera.position = o;
    camera.target = target;

    camera.up = {0.f, 1.f, 0.f};
    camera.fovy = 45.f;

    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}
