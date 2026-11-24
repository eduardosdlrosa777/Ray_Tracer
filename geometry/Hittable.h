#pragma once
#include "HitRecord.h"
#include "Rayo.h"

class Hittable{
    public:

        virtual ~Hittable() = default; // Destructor virtual para evitar problemas de memmoria al eliminar objetos de un puntero a la clase base
        virtual bool hit(const Rayo& r, double t_min, double t_max, HitRecord& rec) const = 0;
};