#include "Scene.hpp"
#include <utility>
namespace scn {

    Scene::Scene( const ImageConfig& imagen, const CameraConfig& camara,const Color& fondo, double lightAmb)
    : imagen(imagen),
    camara(camara),
    fondo(fondo),
    lightAmb(lightAmb){}
    //Considerar una excepcion si la escena requiere
    // al menos una luz y una figura o aspectos con luz ambiental o fondo.
    const ImageConfig& Scene::getImagen() const{
        return this->imagen;
    }
    const CameraConfig& Scene::getCamara() const{
        return this->camara;
    }
    const Color& Scene::getFondo() const{
        return this->fondo;
    }
    double Scene::getLightAmb() const{
        return this->lightAmb;
    }
    const std::vector<Lighting>& Scene::getLuces() const{
        return this->luces;
    }
    const std::vector<std::unique_ptr<Hittable>>& Scene::getFiguras() const{
        return this->figuras;
    }
    void Scene::setCamara(const CameraConfig& camara){
        this->camara = camara;
    }
    void Scene::setFondo(const Color& fondo){
        this->fondo = fondo;
    }
    void Scene::setLightAmb(double lightAmb){
        this->lightAmb = lightAmb;
    }
    void Scene::agregarLuz(const Lighting& luz){
        luces.push_back(luz);
    }
    void Scene::agregarFigura(std::unique_ptr<Hittable> figura){
        figuras.push_back(std::move(figura));
    }
    //falta checar para ambos casos de figuras y luces si es posbile que en 
    //una escena existan dos luces o dos figuras iguales


}