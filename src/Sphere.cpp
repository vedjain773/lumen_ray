#include "Sphere.h"
#include "color.h"
#include "math.h"

Sphere::Sphere (double rad, Vec3 centre_pos): radius(rad), centre(centre_pos) {};

bool Sphere::hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) {
    Vec3 dir = lr.getDir();
    Vec3 q = lr.getSrc();
    double a = dot(dir, dir);
    double b = -2 * dot(dir, centre - q);
    double c = dot(centre - q, centre - q) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return false;

    double sqrt_d = sqrt(discriminant);

    double t = (-b - sqrt_d) / (2*a);

    if (t <= ray_tmin || t >= ray_tmax) {
        t = (-b + sqrt_d) / (2*a);

        if (t <= ray_tmin || t >= ray_tmax)
            return false;
    }

    Vec3 point = lr.at(t);
    Vec3 out_normal = (point - centre) / radius;
    Vec3 normal;

    if (dot(out_normal, dir) > 0) {
        normal = -1 * out_normal;
        hi.front_face = false;
    } else {
        normal = out_normal;
        hi.front_face = true;
    }

    hi.t = t;
    hi.point = point;
    hi.normal = normal;
    hi.mat = mat;

    return true;
}

void Sphere::set_emissive_props(Vec3 ecol) {
    mat->color = ecol;
}

 void Sphere::set_material(material* matr) {
     mat = matr;
 }
