#include <iostream>
#include <cmath>
#include "cam.h"
#include "color.h"
#include "hittable.h"
#include "Sphere.h"
#include "raylib.h"

Vec3 ray_color(LRay& lr, World& world) {
    return trace(lr, world);
}

cam::cam(double asp_ratio, double vh, int rays_pp) {
    lookfrom = Vec3(0, 0, 0);
    lookat = Vec3(0, 0, -1);
    vup = Vec3(0, 1, 0);

    focal_length = (lookfrom - lookat).length();
    aspect_ratio = asp_ratio;

    w = unit_vec(lookfrom - lookat);
    u = unit_vec(cross(vup, w));
    v = cross(w, u);

    double theta = deg_to_rad(vfov);
    double h = tan(theta / 2);

    viewport_params[1] = 2 * h * focal_length;
    viewport_params[0] = viewport_params[1] * asp_ratio;

    viewport_vecs[0] = Vec3(viewport_params[0], 0, 0);
    viewport_vecs[1] = Vec3(0, -viewport_params[1], 0);

    viewport_vecs[0] = viewport_params[0] * u;
    viewport_vecs[1] = viewport_params[1] * (-1 * v);
    rays_per_pixel = rays_pp;

    multi_factor = 1.0 / (double) rays_per_pixel;
}

void cam::init(int image_height, int image_width) {
    cam_pos = lookfrom;
    image_params[0] = image_width;
    image_params[1] = image_height;

    del_vec[0] = viewport_vecs[0] / (double) image_width;
    del_vec[1] = viewport_vecs[1] / (double) image_height;

    Q = cam_pos - (focal_length * w) - viewport_vecs[0] / 2 - viewport_vecs[1] / 2;
    top_left_pixel = Q + del_vec[0] * 0.5 + del_vec[1] * 0.5;
}

void cam::draw(World& world) {
    Image img = GenImageColor(image_params[0], image_params[1], WHITE);

    for (int i = 0; i < image_params[0]; i++) {
        for (int j = 0; j < image_params[1]; j++) {
            std::cout << "\rCreating pixel " << i << " " << j << std::flush;
            Vec3 init_color = Vec3(0, 0, 0);
            for (int c = 0; c < rays_per_pixel; c++) {
                LRay lr = get_ray(i, j);
                Vec3 curr_col = ray_color(lr, world);
                init_color = init_color + curr_col;
            }

            Color color = createColor(init_color * multi_factor);
            ImageDrawPixel(&img, i, j, color);
        }
    }

    InitWindow(image_params[0], image_params[1], "Window");
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {
        BeginDrawing();
            DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();
}

LRay cam::get_ray(int i, int j) {
    Vec3 offset = get_sample();

    Vec3 vec_head = top_left_pixel + (i + offset.x()) * del_vec[0] + (j + offset.y()) * del_vec[1];
    Vec3 direc = vec_head - cam_pos;

    LRay lr(cam_pos, direc);

    return lr;
}

Vec3 cam::get_sample() {
    return Vec3(
        get_random_double() - 0.5,
        get_random_double() - 0.5,
        0
    );
}
