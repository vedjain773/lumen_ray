#ifndef HITTABLE_H
#define HITTABLE_H

#include "raylib.h"
#include "VecUtils.h"

class material;

struct hit_info {
    RayCollision raycol;
    material* mat;
    bool front_face;
};

class material {
    public:
    Vector3 color;

    virtual Vector3 emit() {
        return new_vec(0, 0, 0);
    }

    virtual Vector3 scatter(Ray& ray, hit_info& hi) = 0;
    virtual Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color) = 0;
    virtual Vector3 get_ray_color(Vector3& ray_color) = 0;
};

class Hittable {
    public:
    material* mat;
    virtual ~Hittable() = default;

    virtual bool hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi) = 0;
};

#endif
