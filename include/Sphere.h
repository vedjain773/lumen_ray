#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class Sphere: public Hittable {
    public:
    Vec3 centre;
    double radius;

    Sphere(double rad, Vec3 centre_pos);
    bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vec3 ecol);
    void set_material(material* matr);
};

#endif
