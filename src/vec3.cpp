#include "vec3.h"
#include <math.h>

Vec3::Vec3() {
    comps[0] = 0;
    comps[1] = 0;
    comps[2] = 0;
}

Vec3::Vec3(double x, double y, double z) {
    comps[0] = x;
    comps[1] = y;
    comps[2] = z;
}

double Vec3::x() {
    return comps[0];
}

double Vec3::y() {
    return comps[1];
}

double Vec3::z() {
    return comps[2];
}

double Vec3::length() const {
    return sqrt(comps[0] * comps[0] + comps[1] * comps[1] + comps[2] * comps[2]);
}

double Vec3::length_sq() {
    return (comps[0] * comps[0] + comps[1] * comps[1] + comps[2] * comps[2]);
}
