#ifndef CAMUTILS_H
#define CAMUTILS_H

#include "World.h"
#include "raylib.h"

struct CamParams {
    int screen_width;
    int screen_height;
    int rays_per_pixel;
    Camera3D cam3d;
};

void draw(CamParams& camparams, World& world);

Ray get_ray(int i, int j, Camera3D cam3d);
Vector3 get_sample();

#endif
