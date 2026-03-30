#ifndef QUAD_H
#define QUAD_H

#include "hittable.h"

class Quad: public Hittable {
    public:
    Vec3 A;
    Vec3 B;
    Vec3 C;
    Vec3 D;

    Quad(Vec3 a, Vec3 b, Vec3 c, Vec3 d);
    bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vec3 ecol);
    void set_material(material* matr);
};

#endif
