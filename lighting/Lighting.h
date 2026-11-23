#pragma once

#include "Color.h"

struct HitRecord;

namespace scn
{
    class Scene;
}

// Calcula el color en el punto de impacto a partir de la luz ambiental
// y del aporte difuso de cada luz visible desde ese punto.
Color ComputeLighting(const HitRecord &impacto, const scn::Scene &escena);