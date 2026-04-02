#ifndef MATERIALS_H
#define MATERIALS_H

#include "Hittable.h"

class Diffused: public material {
    Vector3 scatter(Ray& ray, hit_info& hi);
    Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color);
    Vector3 get_ray_color(Vector3& ray_color);
};

class Diffused_Light: public material {
    Vector3 emit();
    Vector3 scatter(Ray& ray, hit_info& hi);
    Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color);
    Vector3 get_ray_color(Vector3& ray_color);
};

class Metal: public material {
    Vector3 scatter(Ray& ray, hit_info& hi);
    Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color);
    Vector3 get_ray_color(Vector3& ray_color);
};

class Lambertian: public material {
    Vector3 scatter(Ray& ray, hit_info& hi);
    Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color);
    Vector3 get_ray_color(Vector3& ray_color);
};

class Glass: public material {
    double refr_index = 1.5;
    Vector3 scatter(Ray& ray, hit_info& hi);
    Vector3 get_incoming_light(Vector3& incoming_light, Vector3& ray_color);
    Vector3 get_ray_color(Vector3& ray_color);
};

#endif
