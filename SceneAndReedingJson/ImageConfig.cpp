#include "ImageConfig.hpp"
#include <stdexcept>
namespace scn{

    ImageConfig::ImageConfig(int ancho, int alto)
    : ancho(ancho), alto(alto) {
        if (ancho <= 0 || alto <= 0) {
            throw std::invalid_argument("Las dimensiones deben ser positivas");
        }
    }
    int ImageConfig::getAncho() const{
        return this->ancho;
    }
    int ImageConfig::getAlto() const{
        return this->alto;
    }
    void ImageConfig::setAncho(int anchoNuevo){
        if (anchoNuevo <= 0) {
            throw std::invalid_argument("El ancho debe ser positivo");
        }
        ancho = anchoNuevo;
    }
    void ImageConfig::setAlto(int altoNuevo){
        if (altoNuevo <= 0) {
            throw std::invalid_argument("El alto debe ser positivo");
        }
        alto = altoNuevo;
    }

}