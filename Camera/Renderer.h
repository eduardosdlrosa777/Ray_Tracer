
#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "Camera.h"
#include "Scene.hpp"
#include "Color.h"

class Renderer {
private:

    /* Escena que se va a renderizar. */
    const scn::Scene& escena;

    /* Cámara utilizada para generar los rayos. */
    Camera camara;

    /* Calcula el color correspondiente a un rayo. */
    Color calcularColor(const Rayo& rayo) const;

public:

    /* Construye un renderizador para una escena. */
    explicit Renderer(const scn::Scene& escena);

    /* Genera la imagen recorriendo todos sus píxeles. */
    std::vector<Color> renderizar() const;
};

#endif
