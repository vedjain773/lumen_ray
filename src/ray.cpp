#include "ray.h"
#include "vec3.h"
#include "world.h"
#include <cmath>

LRay::LRay(Vec3 source, Vec3 direction): src(source), dir(direction) {}

Vec3 LRay::getSrc() const {
    return src;
}

Vec3 LRay::getDir() const {
    return dir;
}

Vec3 LRay::at(double t) {
    return (src + t*dir);
}

Vec3 trace(LRay& lr, World& world) {
    hit_info hi;
    Vec3 incoming_light = Vec3(0, 0, 0);
    Vec3 ray_color = Vec3(1, 1, 1);

    for (int i = 0; i < 5; i++) {
        if (world.hit(lr, 0.001, INFINITY, hi)) {
            Vec3 dir = hi.mat->scatter(lr, hi);
            lr.src = hi.point;
            lr.dir = dir;
            ray_color = hi.mat->get_ray_color(ray_color);
            incoming_light = hi.mat->get_incoming_light(incoming_light, ray_color);
        } else {
            // Vec3 unit_direction = unit_vec(lr.getDir());
            // double a = 0.5*(unit_direction.y() + 1.0);
            // Vec3 vec_col =  (1.0-a)*Vec3(1.0, 1.0, 1.0) + a*Vec3(0.5, 0.7, 1.0);

            // incoming_light = incoming_light + vec_col * ray_color;
            break;
        }
    }

    return incoming_light;
}
