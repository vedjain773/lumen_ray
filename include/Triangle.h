#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Hittable.h"

class Triangle: public Hittable {
    public:
    Vector3 A;
    Vector3 B;
    Vector3 C;

    Triangle(Vector3 a, Vector3 b, Vector3 c);
    bool hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vector3 ecol);
    void set_material(material* matr);
};

#endif
