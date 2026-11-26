
#include "Camera.h"

#include <cmath>
#include <stdexcept>

/**
 * Construye una cámara a partir de su configuración
 * y las dimensiones de la imagen.
 */
Camera::Camera(const scn::CameraConfig& config,
               const scn::ImageConfig& imagen) {

    /* Obtenemos la posición y el punto al que mira la cámara. */
    posicion = config.getPosicion();
    Vector miraA = config.getMira_a();

    /* Calculamos la dirección hacia la que mira la cámara. */
    Vector direccion = miraA.restaVectores(posicion);

    /* Verificamos que la posición y el punto al que mira sean distintos. */
    if (direccion.norma() == 0.0) {
        throw std::invalid_argument(
            "La posicion y el punto al que mira la camara deben ser distintos."
        );
    }

    /* Normalizamos la dirección frontal. */
    forward = direccion.normalizacion();

    /* Definimos el vector vertical de referencia. */
    Vector referencia(0, 1, 0);

    /*
     * Si la cámara mira casi paralelamente al eje Y,
     * utilizamos otro vector de referencia.
     */
    if (std::abs(forward.productoPunto(referencia)) > 0.999) {
        referencia = Vector(1, 0, 0);
    }

    /* Construimos la base ortonormal de la cámara. */
    right = forward.productoCruz(referencia).normalizacion();
    up = right.productoCruz(forward);

    /* Obtenemos y validamos el FOV horizontal. */
    double fov = config.getFov();

    if (!std::isfinite(fov) || fov <= 0.0 || fov >= 180.0) {
        throw std::invalid_argument(
            "El FOV debe estar entre 0 y 180 grados."
        );
    }

    /* Convertimos el FOV de grados a radianes. */
    const double pi = std::acos(-1.0);
    double fovRad = fov * pi / 180.0;

    /*
     * Calculamos las dimensiones del viewport,
     * considerando una distancia de 1 a la cámara.
     */
    anchoViewport = 2.0 * std::tan(fovRad / 2.0);

    altoViewport = anchoViewport *
                   static_cast<double>(imagen.getAlto()) /
                   imagen.getAncho();
}

/**
 * Genera un rayo a partir de las coordenadas normalizadas
 * de un punto del viewport.
 */
Rayo Camera::generarRayo(double u, double v) const {

    /* Verificamos que las coordenadas sean válidas. */
    if (!std::isfinite(u) || !std::isfinite(v) ||
        u < 0.0 || u > 1.0 ||
        v < 0.0 || v > 1.0) {
        throw std::invalid_argument(
            "Las coordenadas normalizadas deben estar entre 0 y 1."
        );
    }

    /* Calculamos los desplazamientos dentro del viewport. */
    double x = (2.0 * u - 1.0) * anchoViewport / 2.0;
    double y = (1.0 - 2.0 * v) * altoViewport / 2.0;

    /* Calculamos la dirección del rayo. */
    Vector direccion = forward
        .sumaVectores(right.multEscalar(x))
        .sumaVectores(up.multEscalar(y));

    /* Construimos y devolvemos el rayo correspondiente. */
    return Rayo(posicion, direccion);
}
