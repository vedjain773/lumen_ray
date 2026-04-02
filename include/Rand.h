#ifndef RAND_H
#define RAND_H

#include "VecUtils.h"
#include "raylib.h"
#include <random>
#include "raymath.h"

inline double get_random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double get_random_double(double min, double max) {
    return min + (max-min)*get_random_double();
}

inline Vector3 get_random_vec() {
    return new_vec(get_random_double(), get_random_double(), get_random_double());
}

inline Vector3 get_random_vec(double min, double max) {
    return new_vec(
        get_random_double(min, max),
        get_random_double(min, max),
        get_random_double(min, max)
    );
}

inline Vector3 get_random_uv() {
    while (true) {
        Vector3 rad = get_random_vec(-1, 1);
        double l_2 = Vector3LengthSqr(rad);

        if (1e-160 < l_2 && l_2 <= 1) {
            return rad / (double) sqrt(l_2);
        }
    }
}

inline Vector3 get_random_uv_hemisphere(const Vector3& normal) {
    Vector3 uv1 = get_random_uv();

    if (Vector3DotProduct(uv1, normal) > 0) {
        return uv1;
    } else {
        return (-1 * uv1);
    }
}
#endif
