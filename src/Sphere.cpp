#include "Sphere.h"
#include "raylib.h"
#include "raymath.h"

Sphere::Sphere (double rad, Vector3 centre_pos): radius(rad), center(centre_pos) {};

bool Sphere::hit(Ray& ray, double ray_tmin, double ray_tmax, hit_info& hi) {
    RayCollision ray_col = GetRayCollisionSphere(ray, center, radius);

    if (!ray_col.hit) {
        return false;
    }

    double t = ray_col.distance;

    if (t <= ray_tmin || t >= ray_tmax) {
        return false;
    }

    Vector3 out_normal = ray_col.normal;

    if (Vector3DotProduct(out_normal, ray.direction) > 0) {
        ray_col.normal = -1 * out_normal;
        hi.front_face = false;
    } else {
        ray_col.normal = out_normal;
        hi.front_face = true;
    }

    hi.raycol = ray_col;
    hi.mat = mat;

    return true;
}

void Sphere::set_emissive_props(Vector3 ecol) {
    mat->color = ecol;
}

 void Sphere::set_material(material* matr) {
     mat = matr;
 }
