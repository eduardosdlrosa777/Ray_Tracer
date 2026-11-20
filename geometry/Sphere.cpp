#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vec3& c, double r, const Color& col)
    : centro(c) , radio(r), color(col)
    {}


bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const{
    //Obtenemos el valor V = O - C, O es el origen del rayo y C es el centro de la esfera
    Vec3 V = r.restarVectores(r.origen(), centro); //Suponiendo que el método restarVectores devuelve un Vec3 que es la resta de dos vectores
    //Obtenemos a,b,c
    double a = r.productoPunto(r.direccion(), r.direccion());
    double b = 2.0 * r.productoPunto(V, r.direccion());
    double c = r.productoPunto(V, V) - (radio * radio);

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
    rec.punto = r.puntoEnTiempo(rec.t); //Suponiendo que el método puntoEnTiempo devuelve el punto en el rayo en el tiempo t

    //Falta obtener la normal, pero vamos a esperar a que nos indiquen si algún método de Vec3 o Ray nos puede ayudar a calcular la normal
}