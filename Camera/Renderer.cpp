
#include "Renderer.h"

#include "Hittable.h"
#include "HitRecord.h"
#include "Lighting.h"

#include <limits>
#include <stdexcept>

/**
 * Construye el renderizador utilizando la escena recibida.
 */
Renderer::Renderer(const scn::Scene& escena)
    : escena(escena),
      camara(escena.getCamara(), escena.getImagen()) {}


/**
 * Calcula el color correspondiente a un rayo.
 */
Color Renderer::calcularColor(const Rayo& rayo) const {

    /* Distancia mínima para considerar una intersección. */
    constexpr double tMin = 1e-6;

    /* Inicialmente no tenemos ninguna intersección. */
    double masCercano = std::numeric_limits<double>::infinity();

    HitRecord impacto;
    HitRecord temporal;

    bool encontrado = false;

    /* Recorremos todas las figuras de la escena. */
    for (const auto& figura : escena.getFiguras()) {

        if (figura->hit(rayo, tMin, masCercano, temporal)) {

            encontrado = true;

            /* Guardamos la intersección más cercana. */
            masCercano = temporal.t;
            impacto = temporal;
        }
    }

    /* Si no encontramos ningún objeto, devolvemos el fondo. */
    if (!encontrado) {
        return escena.getFondo();
    }

    /* Si hubo intersección, calculamos la iluminación. */
    return ComputeLighting(impacto, escena);
}


/**
 * Renderiza la escena de manera secuencial.
 */
std::vector<Color> Renderer::renderizar() const {

    int ancho = escena.getImagen().getAncho();
    int alto = escena.getImagen().getAlto();

    /* Reservamos espacio para todos los píxeles. */
    std::vector<Color> imagen(ancho * alto);

    /* Recorremos las filas. */
    for (int j = 0; j < alto; j++) {

        /* Recorremos las columnas. */
        for (int i = 0; i < ancho; i++) {

            /* Coordenadas normalizadas del centro del píxel. */
            double u = (i + 0.5) / ancho;
            double v = (j + 0.5) / alto;

            /* Generamos el rayo correspondiente. */
            Rayo rayo = camara.generarRayo(u, v);

            /* Calculamos y almacenamos su color. */
            imagen[j * ancho + i] = calcularColor(rayo);
        }
    }

    return imagen;
}
