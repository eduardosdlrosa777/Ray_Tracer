#pragma once
#include "../Vector_Rays/Vector.h"
#include "../Vector_Rays/Rayo.h"
#include "../lighting/Color.h"
#include "Hittable.h"

class Plane : public Hittable {
    private :
        Vector punto;
        Vector normal;
        Color color;
    
    public :
        Plane(const Vector& punto, const Vector& normal, const Color& color);

        bool hit(const Rayo& ray, double t_min, double t_max, HitRecord& rec) const override;
};
