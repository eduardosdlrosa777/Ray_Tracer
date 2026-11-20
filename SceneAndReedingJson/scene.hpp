#pragma once
#include <vector>
#include <memory>
#include "ImageConfig.hpp"
#include "CameraConfig.hpp"
//#include "Color"
//#include "abstr"



namespace scn {
    class Scene {
        private:
        //cada clase de aqui necesita su nombre real
        ImageConfig imagen;
        CameraConfig camara;
        Color fondo; //representada con color de fase 4
        double ligthAmb;

        std::vector<std::unique_ptr<Abstr>> objetos; //falta nombre de maik

        public:
        Scene( const ImageConfig& imagen, const CameraConfig& camara, 
        const Color& fondo,
        double lightAmb);
        //~Scene() = default;
    };

}