#ifndef CUBOID_H
#define CUBOID_H

#include "hittable.h"
#include "Quad.h"
#include <cmath>

class Cuboid: public Hittable {
    public:
    Vec3 A, B, C, D;
    Vec3 E, F, G, H;

    Cuboid(Vec3 f, double dx, double dy, double dz);
    void rot_y(double angle_deg);
    bool hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi);
    void set_emissive_props(Vec3 ecol);
    void set_material(material* matr);
};

inline Vec3 get_rotated(Vec3 vec, double angle_rad) {
    double cos_theta = cos(angle_rad);
    double sin_theta = sin(angle_rad);

    double x = vec.x();
    double y = vec.y();
    double z = vec.z();

    double x_dash = x * cos_theta + z * sin_theta;
    double y_dash = y;
    double z_dash = -x * sin_theta + z * cos_theta;

    return Vec3(x_dash, y_dash, z_dash);
}

#endif
