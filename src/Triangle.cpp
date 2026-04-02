#include "Triangle.h"

Triangle::Triangle(Vec3 a, Vec3 b, Vec3 c) {
    A = a;
    B = b;
    C = c;
}

bool Triangle::hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) {
    Vec3 ray_dir = lr.getDir();
    Vec3 ray_src = lr.getSrc();

    Vec3 edge1 = B - A;
    Vec3 edge2 = C - A;
    Vec3 out_normal = cross(edge1, edge2);

    double D = dot(out_normal, A);

    Vec3 w = out_normal / dot(out_normal, out_normal);

    Vec3 normal;
    bool is_front;
    if (dot(out_normal, ray_dir) > 0) {
        normal = -1 * out_normal;
        is_front = false;
    } else {
        normal = out_normal;
        is_front = true;
    }

    if (std::abs(dot(normal, ray_dir)) < 1e-8)
        return false;

    double t = (D - dot(normal, ray_src)) / dot(normal, ray_dir);

    if (t > ray_tmax || t < ray_tmin)
        return false;

    Vec3 P = lr.at(t);

    if (isInside(P, normal, w)) {
        hi.t = t;
        hi.point = P;
        hi.normal = normal;
        hi.mat = mat;
        hi.front_face = is_front;

        return true;
    } else {
        return false;
    }
}

void Triangle::set_emissive_props(Vec3 ecol) {
    mat->color = ecol;
}

void Triangle::set_material(material* matr) {
    mat = matr;
}

bool Triangle::isInside(Vec3 point, Vec3 normal, Vec3 w) {
    Vec3 u = B - A;
    Vec3 v = C - A;
    Vec3 p = point - A;

    double alpha = dot(w, cross(p, v));
    double beta = dot(w, cross(u, p));

    if (alpha >= 1e-8 && beta >= 1e-8 && alpha + beta <= 1 + 1e-8)
        return true;
    else
        return false;
}
