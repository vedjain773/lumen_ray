#include "CamUtils.h"
#include "raylib.h"
#include <iostream>

Vector3 ray_color(Ray& ray) {

}

void draw(int screen_height, int screen_width) {
    Image img = GenImageColor(screen_width, screen_height, WHITE);

    for (int i = 0; i < screen_width; i++) {
        for (int j = 0; j < screen_height; j++) {
            std::cout << "\rCreating pixel " << i << " " << j << std::flush;

            ImageDrawPixel(&img, i, j, WHITE);
        }
    }

    InitWindow(screen_width, screen_height, "Window");
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {
        BeginDrawing();
            DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
}
