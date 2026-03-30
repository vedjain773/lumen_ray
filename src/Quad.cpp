#include "Quad.h"
#include "Triangle.h"

Quad::Quad(Vec3 a, Vec3 b, Vec3 c, Vec3 d) {
    A = a;
    B = b;
    C = c;
    D = d;
}

bool Quad::hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) {
    Triangle tri_1(A, B, C);
    Triangle tri_2(A, C, D);

    tri_1.set_material(mat);
    tri_1.set_emissive_props(mat->color);

    tri_2.set_material(mat);
    tri_2.set_emissive_props(mat->color);

    hit_info h1;
    hit_info h2;

    bool didhit1 = tri_1.hit(lr, ray_tmin, ray_tmax, h1);
    bool didhit2 = tri_2.hit(lr, ray_tmin, ray_tmax, h2);

    if (didhit1 && didhit2) {
        hi = h1.t > h2.t ? h2 : h1;
    } else if (didhit1) {
        hi = h1;
    } else if (didhit2) {
        hi = h2;
    }

    return didhit1 || didhit2;
}

void Quad::set_emissive_props(Vec3 ecol) {
    mat->color = ecol;
}

void Quad::set_material(material* matr) {
    mat = matr;
}
