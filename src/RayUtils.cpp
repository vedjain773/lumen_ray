#include "RayUtils.h"
#include "Hittable.h"
#include "VecUtils.h"
#include "raymath.h"

Vector3 trace(Ray& ray, World& world) {
    hit_info hi;
    Vector3 incoming_light = new_vec(0.0, 0.0, 0.0);
    Vector3 ray_color = new_vec(1.0, 1.0, 1.0);

    for (int i = 0; i < 5; i++) {
        if (world.hit(ray, 0.001, INFINITY, hi)) {
            Vector3 dir = hi.mat->scatter(ray, hi);
            ray.position = hi.raycol.point;
            ray.direction = dir;
            ray_color = hi.mat->get_ray_color(ray_color);
            incoming_light = hi.mat->get_incoming_light(incoming_light, ray_color);
        } else {
            Vector3 unit_direction = Vector3Normalize(ray.direction);
            double a = 0.5*(unit_direction.y + 1.0);
            Vector3 vec_col =  (1.0-a) * new_vec(1.0, 1.0, 1.0) + a * new_vec(0.5, 0.7, 1.0);

            incoming_light = incoming_light + vec_col * ray_color;
            break;
        }
    }

    return incoming_light;
}
