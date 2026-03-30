#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "raylib.h"
#include "vec3.h"
#include <cstdint>

class material;

struct hit_info {
    Vec3 point;
    Vec3 normal;
    double t;
    bool front_face;
    material* mat;
};

class material {
    public:
    Vec3 color;

    virtual Vec3 emit() {
        return Vec3(0, 0, 0);
    }

    virtual Vec3 scatter(LRay& lr, hit_info& hi) = 0;
    virtual Vec3 get_incoming_light(Vec3& incoming_light, Vec3& ray_color) = 0;
    virtual Vec3 get_ray_color(Vec3& ray_color) = 0;
};

class Hittable {
    public:
    material* mat;
    virtual ~Hittable() = default;
    virtual bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) = 0;
};

#endif
