#pragma once

#include "Hittable.h"
#include "Color.h"

class Sphere : public Hittable {
    private:
        Vector centro;
        double radio;
        Color color;

    public:
        Sphere(const Vector &c, double r, const Color &col);
        // Declaramos la función hit heredada de Hittable pero aun no la implementamos
        bool hit(const Rayo& r, double t_min, double t_max, HitRecord& rec) const override;


};