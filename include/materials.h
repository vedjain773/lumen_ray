#ifndef MATERIALS_H
#define MATERIALS_H

#include "hittable.h"
#include "ray.h"
#include "vec3.h"

class Diffused: public material {
    Vec3 scatter(LRay& lr, hit_info& hi);
    Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color);
    Vec3 get_ray_color(Vec3& ray_color);
};

class Diffused_Light: public material {
    Vec3 scatter(LRay& lr, hit_info& hi);
    Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color);
    Vec3 get_ray_color(Vec3& ray_color);
    Vec3 emit();
};

class Lambertian: public material {
    Vec3 scatter(LRay& lr, hit_info& hi);
    Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color);
    Vec3 get_ray_color(Vec3& ray_color);
};

class Metal: public material {
    Vec3 scatter(LRay& lr, hit_info& hi);
    Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color);
    Vec3 get_ray_color(Vec3& ray_color);
};

class Glass: public material {
    double refr_index = 1.5;

    Vec3 scatter(LRay& lr, hit_info& hi);
    Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color);
    Vec3 get_ray_color(Vec3& ray_color);
};

#endif
