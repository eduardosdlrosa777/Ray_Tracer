#include "Plane.h"

Plane :: Plane(const Vector& punto, const Vector& normal, const Color& color)
    : punto(punto), normal(normal), color(color)
{}

bool Plane :: hit(const Rayo& ray, double t_min, double t_max, HitRecord& rec) const{
    //Calculamos el valor de "t"
    //Calculamos el numerador
    Vector vec1 = punto.restaVectores(ray.muestraOrigen());
    double numerador = vec1.productoPunto(normal);
    //Calculamos el denominador
    double denominador = ray.muestraDireccion().productoPunto(normal);
    if(denominador == 0) {
        return false;
    }
    //Calculamos "t"
    double t = numerador / denominador;
    //Verificamos rango de t
    if(t < t_min || t > t_max){
        return false;
    }
    rec.t = t;
    rec.punto = ray.puntoEn(t);
    //Sacamos frontal y normal
    rec.frontal = denominador < 0;
    if(rec.frontal){
        rec.normal = normal;
    }else{
        rec.normal = normal.multEscalar(-1);
    }

    rec.color = color;
    return true;

}