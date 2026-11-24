#ifndef RAYO_H
#define RAYO_H

#include "Vector.h"
/*
"Interfaz" del rayo que se encarga de dar nombre a los métodos
del objeto y sus atributos
@autor Salvalovers
@since November 2026S
*/

class Rayo{

    //Atributos
    private:
        Vector origen;
        Vector direccion;
    
    public:
    //Constructores
        Rayo();
        Rayo(const Vector& origen, const Vector& direccion);

    //Propiedades
        void cambiaOrigen(const Vector& origen);
        void cambiaDireccion(const Vector& direccion);
        const Vector& muestraOrigen() const;
        const Vector& muestraDireccion() const;

    //Fórmulas
        Vector puntoEn(double t) const;

};

#endif