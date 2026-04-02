#include "CamUtils.h"
#include "raylib.h"
#include "raymath.h"
#include "VecUtils.h"
#include "ColUtils.h"
#include "RayUtils.h"
#include "World.h"
#include "Rand.h"
#include <iostream>

Vector3 ray_color(Ray& ray, World& world) {
    return trace(ray, world);
}

void draw(CamParams& camparams, World& world) {

    int screen_width = camparams.screen_width;
    int screen_height = camparams.screen_height;
    int rays_pp = camparams.rays_per_pixel;
    Camera3D cam3d = camparams.cam3d;

    Image img = GenImageColor(screen_width, screen_height, WHITE);

    InitWindow(screen_width, screen_height, "Window");

    for (int i = 0; i < screen_width; i++) {
        for (int j = 0; j < screen_height; j++) {
            std::cout << "\rCreating pixel " << i << " " << j << std::flush;

            Vector3 init_color = new_vec(0.0, 0.0, 0.0);
            for (int c = 0; c < rays_pp; c++) {
                Ray ray = get_ray(i, j, cam3d);
                init_color = init_color + ray_color(ray, world);
            }

            Color color = create_color(init_color / rays_pp);
            ImageDrawPixel(&img, i, j, color);
        }
    }

    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {
        BeginDrawing();
            DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
}

Ray get_ray(int i, int j, Camera3D cam3d) {
    Vector3 offset = get_sample();

    Vector2 pos = (Vector2){(float)i + offset.x, (float)j + offset.y};

    Ray ray = GetScreenToWorldRay(pos, cam3d);

    return ray;
}

Vector3 get_sample() {
    return new_vec(
        get_random_double() - 0.5,
        get_random_double() - 0.5,
        0
    );
}
