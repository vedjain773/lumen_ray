#ifndef VECUTILS_H
#define VECUTILS_H

#include "raylib.h"
#include <iostream>

inline Vector3 new_vec(double x, double y, double z) {
    Vector3 nvec;

    nvec.x = x;
    nvec.y = y;
    nvec.z = z;

    return nvec;
}

inline Vector3 operator*(const double& a, const Vector3& vec) {
    Vector3 nvec;

    nvec.x = vec.x * a;
    nvec.y = vec.y * a;
    nvec.z = vec.z * a;

    return nvec;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

#endif
