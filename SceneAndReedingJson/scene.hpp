#pragma once
#include <vector>
#include <memory>
#include "ImageConfig.hpp"
#include "CameraConfig.hpp"
#include "Color.h"
#include "Lighting.h"
#include "Hittable.h"



namespace scn {
    class Scene {
        private:
        //cada clase de aqui necesita su nombre real
        ImageConfig imagen;
        CameraConfig camara;
        Color fondo; //representada con color de fase 4
        double lightAmb;
        std::vector<Lighting> luces;
        std::vector<std::unique_ptr<Hittable>> figuras; //falta nombre de maik
        public:

        //constructor
        Scene( const ImageConfig& imagen, const CameraConfig& camara, 
        const Color& fondo,
        double lightAmb);
        //~Scene() = default;

        //getters
        const ImageConfig& getImagen() const;
        const CameraConfig& getCamara() const;
        const Color& getFondo() const;
        double getLightAmb() const;
        const std::vector<std::unique_ptr<Hittable>>& getFiguras() const;
        // Setters
        void setCamara(const CameraConfig& camara);
        void setFondo(const Color& fondo);
        void setLightAmb(double lightAmb);

        // Metodos
        void agregarLuz(const Lighting& luz);
        void agregarFigura(std::unique_ptr<Hittable> figura);
    };

}