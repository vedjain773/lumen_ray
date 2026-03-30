#ifndef VEC3_H
#define VEC3_H

#include "rand.h"
#include <algorithm>
#include <cmath>

class Vec3 {
    public:
    double comps[3];

    Vec3();
    Vec3(double x, double y, double z);

    double x();
    double y();
    double z();

    double length() const;
    double length_sq();
};

inline Vec3 operator+(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.comps[0] + b.comps[0],
        a.comps[1] + b.comps[1],
        a.comps[2] + b.comps[2]
    );
}

inline Vec3 operator-(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.comps[0] - b.comps[0],
        a.comps[1] - b.comps[1],
        a.comps[2] - b.comps[2]
    );
}

inline Vec3 operator*(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.comps[0] * b.comps[0],
        a.comps[1] * b.comps[1],
        a.comps[2] * b.comps[2]
    );
}

inline Vec3 operator*(double scalar, const Vec3& a) {
    return Vec3(
        scalar * a.comps[0],
        scalar * a.comps[1],
        scalar * a.comps[2]
    );
}

inline Vec3 operator*(const Vec3& a, double scalar) {
    return Vec3(
        scalar * a.comps[0],
        scalar * a.comps[1],
        scalar * a.comps[2]
    );
}

inline Vec3 operator/(const Vec3& a, double scalar) {
    return (1 / scalar) * a;
}

inline double dot(const Vec3& a, const Vec3& b) {
    return (
        a.comps[0] * b.comps[0] + a.comps[1] * b.comps[1] + a.comps[2] * b.comps[2]
    );
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.comps[1] * b.comps[2] - a.comps[2] * b.comps[1],
        a.comps[2] * b.comps[0] - a.comps[0] * b.comps[2],
        a.comps[0] * b.comps[1] - a.comps[1] * b.comps[0]
    );
}

inline Vec3 unit_vec(const Vec3&a) {
    return a / a.length();
}

inline Vec3 getRGB(const Vec3&a) {
    return Vec3(
        255.0 * std::clamp(a.comps[0], 0.0, 0.999),
        255.0 * std::clamp(a.comps[1], 0.0, 0.999),
        255.0 * std::clamp(a.comps[2], 0.0, 0.999)
    );
}

inline Vec3 get_random_vec() {
    return Vec3(
        get_random_double(),
        get_random_double(),
        get_random_double()
    );
}

inline Vec3 get_random_vec(double min, double max) {
    return Vec3(
        get_random_double(min,max),
        get_random_double(min,max),
        get_random_double(min,max)
    );
}

inline Vec3 get_random_uv() {
    while (true) {
        Vec3 rad = get_random_vec(-1, 1);
        double l_2 = rad.length_sq();

        if (1e-160 < l_2 && l_2 <= 1) {
            return rad / (double) sqrt(l_2);
        }
    }
}

inline Vec3 get_random_uv_hemisphere(const Vec3& normal) {
    Vec3 uv1 = get_random_uv();

    if (dot(uv1, normal) > 0) {
        return uv1;
    } else {
        return (-1 * uv1);
    }
}

#endif
