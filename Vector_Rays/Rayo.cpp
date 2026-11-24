#include <iostream>
#include "Vector.h"
#include "Rayo.h"

/*
Clase Rayo que se encarga de construir un rayo en base a los vectores
en el espacio
@autor Salvalover
@since November 2026
*/

    /* NOTA: Se normaliza la direccion para que al calcular intersecciones
    se obtenga un t separado de la cámara y no lleve al origen
    También para ahorrar el cálculo del choque con la esfera ya que los
    rayos valen 1 y no es necesario sacar el cuadrado de muchos valores xdxd
    También para reducir la fórmula de iluminación y sombras, reflexión y refracción, 
    */   

    //CONSTRUCTORES

    /* Constructor por defecto, un rayo que va desde (0,0,0) hasta (1,1,1) */

    Rayo::Rayo() 
    : origen(0, 0, 0), direccion(Vector(1, 1, 1).normalizacion()) {}

    /* Constructor con parámetros */
    Rayo::Rayo(const Vector& origen, const Vector& direccion) 
    : origen(origen), direccion(direccion.normalizacion()) {}

    //PROPIEDADES DEL RAYO

    /*
    Método que cambia el vector origen del rayo
    @param Vector origen nuevo
    */
    void Rayo::cambiaOrigen(const Vector& origen){
        this->origen = origen;
    }

    /*
    Método que cambia el vector direccion del rayo
    @param Vector direccion nuevo
    */
    void Rayo::cambiaDireccion(const Vector& direccion){
        this->direccion = direccion.normalizacion();
    }

    /*
    Método que devuelve el vector origen del rayo
    @return Vector origen
    */
    const Vector& Rayo::muestraOrigen() const{
        return origen;
    }

    /*
    Método que devuelve el vector direccion del rayo
    @return Vector direccion
    */
    const Vector& Rayo::muestraDireccion() const{
        return direccion;
    }

    //FÓRMULAS DEL RAYO

    /*
    Método que realiza la fórmula P(t) = O + t*D para generar el rayo
    @param double t, escalar con el cual se multiplicará la dirección
    @return Vector resultante el cual es el rayo
    */
    Vector Rayo::puntoEn(double t) const{
        return origen.sumaVectores(direccion.multEscalar(t));
    }
