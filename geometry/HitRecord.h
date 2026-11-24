#pragma once

#include "Vector.h"

struct HitRecord{
            double t = 0.0;
            Vector punto = Vec3(0.0, 0.0, 0.0);
            Vector normal = Vec3(0.0, 0.0, 0.0);
            Vector color = Vec3(0.0, 0.0, 0.0);
            bool frontal = false;   

};