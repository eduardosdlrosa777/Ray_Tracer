#include <gtest/gtest.h>
#include "Vector.h"
#include <cmath>

/*
Archivo que se encarga de realizar las pruebas de cada método del
objeto Vector
@autor Salvalovers
@since November 2026
*/

/*
EXPECT_DOUBLE_EQ(valor1, valor2) es una función de Google Test 
diseñada específicamente para comparar dos números decimales
de tipo double teniendo en cuenta los pequeños errores de 
redondeo de la computadora.
*/


//Constructores y getters
TEST(VectorTest, ConstructoresYGetters){
    Vector porDefecto;
    EXPECT_DOUBLE_EQ(porDefecto.muestraX(), 0.0);
    EXPECT_DOUBLE_EQ(porDefecto.muestraY(), 0.0);
    EXPECT_DOUBLE_EQ(porDefecto.muestraZ(), 0.0);

    Vector v(4.6, 1.3, 2.9);
    EXPECT_DOUBLE_EQ(v.muestraX(), 4.6);
    EXPECT_DOUBLE_EQ(v.muestraY(), 1.3);
    EXPECT_DOUBLE_EQ(v.muestraZ(), 2.9);
}

//Setters
TEST(VectorTest, Setters){
    Vector v(3.4, 2.1, 0.0);
    EXPECT_DOUBLE_EQ(v.muestraX(), 3.4);
    EXPECT_DOUBLE_EQ(v.muestraY(), 2.1);
    EXPECT_DOUBLE_EQ(v.muestraZ(), 0.0);

    v.cambiaEjeX(3.3);
    v.cambiaEjeY(2.3);
    v.cambiaEjeZ(0.9);

    EXPECT_DOUBLE_EQ(v.muestraX(), 3.3);
    EXPECT_DOUBLE_EQ(v.muestraY(), 2.3);
    EXPECT_DOUBLE_EQ(v.muestraZ(), 0.9);

}

//Norma
TEST(VectorTest, Norma){
    Vector v(3.0, 4.0, 0.0);
    double res = v.norma();
    EXPECT_DOUBLE_EQ(res, 5);;
}

//Normalización
TEST(VectorTest, Normalizacion){
    Vector vPorDefecto;
    Vector vCompr = vPorDefecto.normalizacion();
    EXPECT_DOUBLE_EQ(vCompr.muestraX(), 0.0);
    EXPECT_DOUBLE_EQ(vCompr.muestraY(), 0.0);
    EXPECT_DOUBLE_EQ(vCompr.muestraZ(), 0.0);

    Vector v(3.0, 4.0, 0.0);
    Vector vNormalizado = v.normalizacion();
    EXPECT_DOUBLE_EQ(vNormalizado.muestraX(), 0.6);
    EXPECT_DOUBLE_EQ(vNormalizado.muestraY(), 0.8);
    EXPECT_DOUBLE_EQ(vNormalizado.muestraZ(), 0.0);
    
}


//Suma entre vectores
TEST(VectorTest, Suma){
    Vector v1;
    Vector v2(3.4, 5.6, 7.8);
    Vector vRes = v1.sumaVectores(v2);
    EXPECT_DOUBLE_EQ(vRes.muestraX(), 3.4);
    EXPECT_DOUBLE_EQ(vRes.muestraY(), 5.6);
    EXPECT_DOUBLE_EQ(vRes.muestraZ(), 7.8);

    Vector v3(3.0, 2.5, -1.3);
    Vector v4(-3.0, -7.4, 5.7);
    Vector vRes2 = v3.sumaVectores(v4);
    EXPECT_DOUBLE_EQ(vRes2.muestraX(), 0.0);
    EXPECT_DOUBLE_EQ(vRes2.muestraY(), -4.9);
    EXPECT_DOUBLE_EQ(vRes2.muestraZ(), 4.4);

}

TEST(VectorTest, Resta){
    Vector v1;
    Vector v2(-4.0, 1.3, -5.2);
    Vector vRes = v1.restaVectores(v2);
    EXPECT_DOUBLE_EQ(vRes.muestraX(), 4.0);
    EXPECT_DOUBLE_EQ(vRes.muestraY(), -1.3);
    EXPECT_DOUBLE_EQ(vRes.muestraZ(), 5.2); //Se supone que cambia el signo

    Vector vRes2 = v2.restaVectores(v1);
    EXPECT_DOUBLE_EQ(vRes2.muestraX(), -4.0);
    EXPECT_DOUBLE_EQ(vRes2.muestraY(), 1.3);
    EXPECT_DOUBLE_EQ(vRes2.muestraZ(), -5.2); //No cambia nada

    Vector v3(1.2, -5.6, 2.9);
    Vector vRes3 = v2.restaVectores(v3);
    EXPECT_DOUBLE_EQ(vRes3.muestraX(), -5.2);
    EXPECT_DOUBLE_EQ(vRes3.muestraY(), 6.9);
    EXPECT_DOUBLE_EQ(vRes3.muestraZ(), -8.1);

    Vector vRes4 = v3.restaVectores(v2);
    EXPECT_DOUBLE_EQ(vRes4.muestraX(), 5.2);
    EXPECT_DOUBLE_EQ(vRes4.muestraY(), -6.9);
    EXPECT_DOUBLE_EQ(vRes4.muestraZ(), 8.1);
}

//Multiplicar por escalar
TEST(VectorTest, multEscalar){
    Vector v1;
    Vector vRes = v1.multEscalar(2.0);
    EXPECT_DOUBLE_EQ(vRes.muestraX(), 0.0);
    EXPECT_DOUBLE_EQ(vRes.muestraY(), 0.0);
    EXPECT_DOUBLE_EQ(vRes.muestraZ(), 0.0);

    Vector v2(3.4, -0.7, 2.1);
    Vector vRes2 = v2.multEscalar(2.0);
    EXPECT_DOUBLE_EQ(vRes2.muestraX(), 6.8);
    EXPECT_DOUBLE_EQ(vRes2.muestraY(), -1.4);
    EXPECT_DOUBLE_EQ(vRes2.muestraZ(), 4.2);

    Vector vRes3 = v2.multEscalar(-3.7);
    EXPECT_DOUBLE_EQ(vRes3.muestraX(), -12.58);
    EXPECT_DOUBLE_EQ(vRes3.muestraY(), 2.59);
    EXPECT_DOUBLE_EQ(vRes3.muestraZ(), -7.77);
}

//Producto punto
Test(VectorTest, productoPunto){
    Vector v1;
    Vector v2(3.4, -4.6, 2.9);
    double res = v1.productoPunto(v2);
    EXPECT_DOUBLE_EQ(res, 0.0); 

    Vector v3(2.1, 0.7, -8.5);
    double res2 = v2.productoPunto(v3);
    EXPECT_DOUBLE_EQ(res2, -20.73);
}

//Producto cruz
Test(VectorTest, productoCruz){
    Vector v1;
    Vector v2(-6.7, 2.8, 9.1);
    Vector vRes = v1.productoCruz(v2);
    EXPECT_DOUBLE_EQ(vRes.muestraX(), 0.0);
    EXPECT_DOUBLE_EQ(vRes.muestraY(), 0.0);
    EXPECT_DOUBLE_EQ(vRes.muestraZ(), 0.0);

    Vector v3(7.2, -3.1, -6.7);
    Vector vRes2 = v3.productoCruz(v2);
    EXPECT_DOUBLE_EQ(vRes2.muestraX(), -9.45);
    EXPECT_DOUBLE_EQ(vRes2.muestraY(), -20.63);
    EXPECT_DOUBLE_EQ(vRes2.muestraZ(), -0.61);

    Vector vRes3 = v2.productoCruz(v3);
    EXPECT_DOUBLE_EQ(vRes3.muestraX(), 9.45);
    EXPECT_DOUBLE_EQ(vRes3.muestraY(), 20.63);
    EXPECT_DOUBLE_EQ(vRes3.muestraZ(), 0.61);

}






