#include "CameraConfig.hpp"
#include <stdexcept>
namespace scn{

    CameraConfig::CameraConfig(const Vec3& posicion, const Vec3& mira_a, int fov)
    : posicion(posicion),
      mira_a(mira_a),
    fov(fov) {}

    //implementacion de setters
    void CameraConfig::setPosicion(const Vec3& posicion){
        this->posicion = posicion;
    }
    void CameraConfig::setMira_a(const Vec3& mira_a){
        this->mira_a = mira_a;
    }
    // igual que fov, ver si es valido que sea un vector 0 la relacion
    // entre la posicion de la camara y a donde mira
    
    void CameraConfig::setFov(int nuevoFov){
    //    if(nuevoFov <= 0 || nuevoFov >= 180) {
    //        throw std::invalid_argument("FOV invalido");
    //   }
    // falta saber el rango de restriccion del fov 

       fov= nuevoFov;
    }
    //implementacion de getters
    const Vec3& CameraConfig::getPosicion() const {
        return this->posicion;
    }
    const Vec3& CameraConfig::getMira_a() const{
        return this->mira_a;
    }
    int CameraConfig::getFov() const{
        return this->fov;
    }

}