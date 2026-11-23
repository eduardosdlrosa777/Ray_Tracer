#include <iostream>
#include "Vector.h"
#include <cmath>

using namespace std;

/*
Clase vector que se encarga de implementar y desarrollar las
herramientas para los cálculos necesarios de los 
rayos dentro de la escena a leer. 
@autor Salvalovers
@since November 2026

NOTA: si no se pone Vector:: antes del nombre del método
el compilador piensa que se escribe otra función independiente
a la de la "interfaz" del Vector.
*/
    //CONSTRUCTORES DEL VECTOR

    /* Constructor por defecto en las coordenadas (0,0,0)*/
    Vector::Vector(){
        x = 0;
        y = 0;
        z = 0;
    }
    /* Constructor con parámetros */
    Vector::Vector(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }



    //OPERACIONES DEL MISMO VECTOR

    /*NOTA: Se usa const al final del método para asegurarle al compilador
    que no se hará ningún cambio al vector del cual se obtienen sus valores*/

    /*
    Método que devuelve las coordenadas en el eje X del vector
    @return double coordenadas X
    */
    double Vector::mostrarEjeX() const{
        return x;
    }

    /*
    Método que devuelve las coordenadas en el eje Y del vector
    @return double coordenadas Y
    */
    double Vector::mostrarEjeY() const{
        return y;
    }

    /*
    Método que devuelve las coordenadas en el eje Z del vector
    @return double coordenadas Z
    */
    double Vector::mostrarEjeZ() const{
        return z;
    }

    /*
    Método que modifica coordenadas X del vector
    @param nuevas coordenadas X
    */
    void Vector::cambiaEjeX(double nuevaX){
        x = nuevaX;
    }

    /*
    Método que modifica coordenadas Y del vector
    @param nuevas coordenadas Y
    */
    void Vector::cambiaEjeY(double nuevaY){
        y = nuevaY;
    }

    /*
    Método que modifica coordenadas Z del vector
    @param nuevas coordenadas Z
    */
    void Vector::cambiaEjeZ(double nuevaZ){
        z = nuevaZ;
    }

    /*
    Método que calcula la norma del vector
    @return double resultado de la norma
    */
    double Vector::norma() const{
        double suma = (x*x) + (y*y) + (z*z);
        return sqrt(suma);
    }

    /* NOTA: Se utiliza const al final del método para asegurarle al compilador de C
    que no se cambia el valor del vector original*/

    /*
    Método que normaliza un vector
    @return Vector normalizado
    */
     Vector Vector::normalizacion() const{
        double n = norma();
        if(n == 0) return Vector(0,0,0);

        return Vector(x/n, y/n, z/n);
    }





    //OPERACIONES ENTRE VECTORES

    /*NOTA: Se coloca una constante en los parámetros del método para
    asegurarle al compilador de C que es un Vector al cual no se le
    modifica nada durante el uso del método*/

    /*
    Método que suma dos vectores, creando otro vector resultante con
    las nuevas coordenadas x, y, z
    @param Vector otro vector con el cual se le sumará al vector que llama el método
    @return Vector vector resultante de la suma
    */
    Vector Vector::sumaVectores(const Vector& otro) const{
        return Vector(x + otro.x, y + otro.y, z + otro.z);
    }

    /*
    Método que resta dos vectores, creando otro vector resultante con
    las nuevas coordenadas x, y, z
    @param Vector otro vector con el cual se le restará al vector que llama el método
    @return Vector vector resultante de la resta
    */
    Vector Vector::restaVectores(const Vector& otro) const{
        return Vector(x - otro.x, y - otro.y, z - otro.z);
    }

    /*
    Método que multiplica un escalar por un vector
    @param double r con el cual se multiplicará el vector
    @return Vector vector resultante de la multiplicación
    */
    Vector Vector::multEscalar(double r) const{
        return Vector(x*r, y*r, z*r);
    }

    /*
    Método que realiza el producto punto entre dos vectores
    @param Vector otro con el cual se hará la operación
    @return double resultado de la operación
    */
    double Vector::productoPunto(const Vector& otro) const{
        return (x*otro.x) + (y*otro.y) + (z*otro.z);
    }

    /*
    Método que realiza el producto cruz entre dos vectores
    @param Vector otro con el cual se hará la operación
    @return Vector resultante de la operación
    */
    Vector Vector::productoCruz(const Vector& otro) const{
        return Vector(
            y*otro.z - z*otro.y,
            z*otro.x - x*otro.z, 
            x*otro.y - y*otro.x
        );
    }
