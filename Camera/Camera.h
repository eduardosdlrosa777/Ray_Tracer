
#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Rayo.h"
#include "CameraConfig.hpp"
#include "ImageConfig.hpp"

/**
 * Representa una cámara de perspectiva que genera
 * rayos hacia los puntos del plano de imagen.
 */
class Camera {
private:

    /* Posición de la cámara. */
    Vector posicion;

    /* Vectores de orientación de la cámara. */
    Vector forward;
    Vector right;
    Vector up;

    /* Dimensiones del viewport. */
    double anchoViewport;
    double altoViewport;

public:

    /**
     * Construye la cámara utilizando su configuración
     * y las dimensiones de la imagen.
     */
    Camera(const scn::CameraConfig& config,
           const scn::ImageConfig& imagen);

    /**
     * Genera un rayo a partir de coordenadas
     * normalizadas del viewport.
     *
     * @param u Coordenada horizontal normalizada.
     * @param v Coordenada vertical normalizada.
     * @return Rayo correspondiente al punto indicado.
     */
    Rayo generarRayo(double u, double v) const;
};

#endif
