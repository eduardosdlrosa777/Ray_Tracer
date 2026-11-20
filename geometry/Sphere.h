#pragma once

#include "Hittable.h"
#include "Color.h"

class Sphere : public Hittable {
    private:
        Vec3 centro;
        double radio;
        Color color;

    public:
        //Declaramos la función hit heredada de Hittable pero aun no la implementamos
        bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;


};