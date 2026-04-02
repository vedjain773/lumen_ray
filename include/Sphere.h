#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"
#include "raylib.h"

class Sphere: public Hittable {
    public:
    double radius;
    Vector3 center;

    Sphere(double radius, Vector3 center);
    bool hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_material(material* mat);
    void set_emissive_props(Vector3 color);
};

#endif
