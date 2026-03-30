#ifndef CAM_H
#define CAM_H

#include "hittable.h"
#include "raylib.h"
#include "ray.h"
#include "vec3.h"
#include "world.h"

Vec3 ray_color(LRay& lr, World& world);

class cam {
    public:
    double focal_length;
    double aspect_ratio;
    int image_params[2];
    double viewport_params[2];
    Vec3 viewport_vecs[2];
    Vec3 del_vec[2];
    Vec3 Q;
    Vec3 top_left_pixel;
    Vec3 cam_pos;

    Vec3 lookfrom;
    Vec3 lookat;
    Vec3 vup;
    double vfov = 90;
    Vec3 u, v, w;

    cam(double asp_ratio, double vw, int rays_pp);
    void init(int img_height, int img_width);

    void draw(World& world);

    int rays_per_pixel;
    double multi_factor;
    LRay get_ray(int i, int j);
    Vec3 get_sample();
};

inline double deg_to_rad(double angle) {
    double pi = 3.14159265359;
    return (angle * pi / 180.0);
}

#endif
