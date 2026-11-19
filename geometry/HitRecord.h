#pragma once

#include "Vec3.h"

struct HitRecord{
            double t = 0.0;
            Vec3 punto = Vec3(0.0, 0.0, 0.0);
            Vec3 normal = Vec3(0.0, 0.0, 0.0);
            Vec3 color = Vec3(0.0, 0.0, 0.0);
            bool frontal = false;   

};