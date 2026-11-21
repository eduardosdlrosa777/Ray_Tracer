#pragma once

#include <memory>
#include <vector>

class Ray;
class Hittable;

// El rayo parte del punto iluminado y tiene dirección unitaria hacia la luz.
// Devuelve true si algún objeto bloquea el trayecto hasta esa luz.
bool shadow(
    const Ray& rayoHaciaLuz,
    double distanciaLuz,
    const std::vector<std::unique_ptr<Hittable>>& objetos);