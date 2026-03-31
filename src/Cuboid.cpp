#include "Cuboid.h"

Cuboid::Cuboid(Vec3 f, double dx, double dy, double dz) {
    F = f;
    E = F + Vec3(0, 0, dz);
    G = F + Vec3(dx, 0, 0);
    H = F + Vec3(dx, 0, dz);

    B = F + Vec3(0, dy, 0);
    A = B + Vec3(0, 0, dz);
    C = B + Vec3(dx, 0, 0);
    D = B + Vec3(dx, 0, dz);
}

void Cuboid::rot_y(double angle_deg) {
    double pi = 3.14159265359;
    double angle_rad = angle_deg * pi / 180.0;

    A = get_rotated(A, angle_rad);
    B = get_rotated(B, angle_rad);
    C = get_rotated(C, angle_rad);
    D = get_rotated(D, angle_rad);

    E = get_rotated(E, angle_rad);
    F = get_rotated(F, angle_rad);
    G = get_rotated(G, angle_rad);
    H = get_rotated(H, angle_rad);
}

bool Cuboid::hit(LRay& lr, double ray_tmin, double ray_tmax, hit_info& hi) {
    Quad q1(F, G, C, B);
    Quad q2(E, H, D, A);
    Quad q3(F, B, A, E);
    Quad q4(G, H, D, C);
    Quad q5(F, E, H, G);
    Quad q6(B, C, D, A);

    std::vector<Quad> qv;
    qv.push_back(q1);
    qv.push_back(q2);
    qv.push_back(q3);
    qv.push_back(q4);
    qv.push_back(q5);
    qv.push_back(q6);

    for (auto& q: qv) {
        q.set_material(mat);
        q.set_emissive_props(mat->color);
    }

    hit_info h1;
    bool alr_hit = false;

    for (auto& q: qv) {
        if (q.hit(lr, ray_tmin, ray_tmax, h1)) {
            if (!alr_hit) {
                hi = h1;
                alr_hit = true;
            } else {
                if (hi.t > h1.t) {
                    hi = h1;
                }
            }
        }
    }

    return alr_hit;
}

void Cuboid::set_emissive_props(Vec3 ecol) {
    mat->color = ecol;
}

void Cuboid::set_material(material* matr) {
    mat = matr;
}
