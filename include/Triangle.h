#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "vec3.h"

class Triangle: public Hittable {
    public:
    Vec3 A;
    Vec3 B;
    Vec3 C;

    Triangle(Vec3 a, Vec3 b, Vec3 c);
    bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vec3 ecol);
    void set_material(material* matr);

    bool isInside(Vec3 point, Vec3 normal, Vec3 w);
};

#endif
