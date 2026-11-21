#include <iostream>
#include "Vector.h"

/*
Clase Rayo que se encarga de construir un rayo en base a los vectores
en el espacio
@autor Salvalover
@since November 2026
*/
class Rayo{

    public:
    Vector origen;
    Vector direccion;

    /* NOTA: Se normaliza la direccion para que al calcular intersecciones
    se obtenga un t separado de la cámara y no lleve al origen
    También para ahorrar el cálculo del choque con la esfera ya que los
    rayos valen 1 y no es necesario sacar el cuadrado de muchos valores xdxd
    También para reducir la fórmula de iluminación y sombras, reflexión y refracción, 
    */


    

    //CONSTRUCTORES

    /* Constructor por defecto, un rayo que va desde (0,0,0) hasta (1,1,1) */

    Rayo(){
        origen = Vector(0,0,0);
        direccion = Vector(1,1,1).normalizacion();
    }

    /* Constructor con parámetros */
    Rayo(const Vector& origen, const Vector& direccion){
        this->origen = origen;
        this->direccion = direccion.normalizacion();
    }

    //PROPIEDADES DEL RAYO

    /*
    Método que cambia el vector origen del rayo
    @param Vector origen nuevo
    */
    void cambiaOrigen(const Vector& origen){
        this->origen = origen;
    }

    /*
    Método que cambia el vector direccion del rayo
    @param Vector direccion nuevo
    */
    void cambiaDireccion(const Vector& direccion){
        this->direccion = direccion.normalizacion();
    }

    /*
    Método que devuelve el vector origen del rayo
    @return Vector origen
    */
    Vector muestraOrigen() const{
        return origen;
    }

    /*
    Método que devuelve el vector direccion del rayo
    @return Vector direccion
    */
    Vector muestraDireccion() const{
        return direccion;
    }

    //FÓRMULAS DEL RAYO

    /*
    Método que realiza la fórmula P(t) = O + t*D para generar el rayo
    @param double t, escalar con el cual se multiplicará la dirección
    @return Vector resultante el cual es el rayo
    */
    Vector puntoEn(double t) const{
        return origen.sumaVectores(direccion.multEscalar(t));
    }
    /* ¿Choca con esfera o con el plano? que lo muestre ifs y elses xdxd*/
    Vector choqueEn()

    /* Luz */


};