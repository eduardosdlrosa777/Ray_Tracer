#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector& c, double r, const Color& col)
    : centro(c) , radio(r), color(col)
    {}


bool Sphere::hit(const Rayo& r, double t_min, double t_max, HitRecord& rec) const{
    //Obtenemos el valor V = O - C, O es el origen del rayo y C es el centro de la esfera
    Vector V = r.muestraOrigen().restaVectores(centro);
    //Obtnemos Direeción del rayo
    Vector D = r.muestraDireccion();
    //Obtenemos a,b,c
    double a = D.productoPunto(D);
    double b = 2.0 * (V.productoPunto(D));
    double c = V.productoPunto(V) - (radio * radio);

    //Comprobar el discriminante
    double discriminante = (b*b) - (4*a*c);
    if(discriminante < 0){
        return false; //No hay solución, el rayo no intersecta la esfera
    }
    //Calculamos las dos posibles soluciones para t
    double raiz_discriminante = sqrt(discriminante);
    double t1 = (-b - raiz_discriminante) / (2.0 * a);
    double t2 = (-b + raiz_discriminante) / (2.0 * a);

    //Verificamos si t1 está dentro del rango permitido
    if(t1 < t_min || t1 > t_max){
        //Entonces t1 no es válido, verificamos t2
        if(t2 < t_min || t2 > t_max){
            return false; //Ninguna de las soluciones es válida
        } else {
            rec.t = t2;
        }
    } else {
        rec.t = t1;
    }

    //Calculamos el punto de intersección
    rec.punto = r.puntoEn(rec.t); //Suponiendo que el método puntoEnTiempo devuelve el punto en el rayo en el tiempo t
    
    //Calculamos la normal
    Vector normal = rec.punto.restaVectores(centro).normalizacion();
    // Determinamos si el rayo está entrando o saliendo de la esfera
    rec.frontal = (D.productoPunto(normal) < 0);
    // Ajustamos la normal para que apunte al rayo incidente si es necesario
    rec.normal = rec.frontal ? normal : normal.multEscalar(-1);
    //Asignamos el color de la esfera al registro de impacto
    rec.color = color;
    return true; //El rayo intersecta la esfera
}