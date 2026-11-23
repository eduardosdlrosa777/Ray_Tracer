#ifndef VECTOR_H
#define VECTOR_H
/*
"Interfaz" del vector que se encarga de dar nombre a los métodos
del objeto y sus atributos
@autor Salvalovers
@since November 2026S
*/
class Vector{

        //Atributos
    private:
        double x;
        double y;
        double z;

    public:
        //Constructores
        Vector();
        Vector(double x, double y, double z);

        //Métodos
        double mostrarEjeX() const;
        double mostrarEjeY() const;
        double mostrarEjeZ() const;

        void cambiaEjeX(double nuevaX);
        void cambiaEjeY(double nuevaY);
        void cambiaEjeZ(double nuevaZ);


        double norma() const;
        Vector normalizacion() const;

        Vector sumaVectores(const Vector& otro) const;
        Vector restaVectores(const Vector& otro) const;
        Vector multEscalar(double r) const;
        double productoPunto(const Vector& otro) const;
        Vector productoCruz(const Vector& otro) const;
};

#endif