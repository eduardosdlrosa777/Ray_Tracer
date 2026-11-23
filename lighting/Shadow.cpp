#include "Shadow.h"
#include "Hittable.h"

bool shadow(
    const Ray &rayoHaciaLuz,
    double distanciaLuz,
    const std::vector<std::unique_ptr<Hittable>> &objetos)
{
    // Ignoramos los choques muy cercanos al origen para evitar que
    // el punto de la superficie proyecte una sombra sobre sí mismo.
    constexpr double distanciaMinima = 1e-6;

    if (distanciaLuz <= distanciaMinima)
    {
        return false;
    }

    HitRecord impacto;

    for (const auto &objeto : objetos)
    {
        // hit guarda en impacto.t la distancia al objeto que tocó el rayo.
        if (objeto->hit(rayoHaciaLuz, distanciaMinima, distanciaLuz, impacto) && impacto.t < distanciaLuz)
        {
            return true;
        }
    }

    return false;
}