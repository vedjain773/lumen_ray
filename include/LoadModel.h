#ifndef LOADMODEL_H
#define LOADMODEL_H

#include "Triangle.h"
#include <vector>

std::vector<Triangle> get_triangles_from_model(const char* filename);

#endif
