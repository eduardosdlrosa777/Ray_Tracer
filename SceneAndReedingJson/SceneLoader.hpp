#pragma once
#include "scene.hpp"
#include "json.hpp"
#include <string>

using json = nlohmann::json;

namespace scn {
    class SceneLoader{
        private:
        json datos;
        
        public:
        SceneLoader();
        Scene cargarEscena(const std::string& ruta);

    };
}