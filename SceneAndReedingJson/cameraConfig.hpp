#pragma once
//#include "Vec3.hpp o .cpp"
namespace scn {
    class CameraConfig {
        private:
        Vec3 posicion;
        Vec3 mira_a;
        int fov; 
        public:
        //constructor con parametros
        CameraConfig( const Vec3& posicion, const Vec3& mira_a, double fov);
        //setters
        void setPosicion(const Vec3& posicion);
        void setMira_a(const Vec3& mira_a);
        void setFov(int fov);
        //getters
        const Vec3& getPosicion() const;
        const Vec3& getMira_a() const;
        int getFov() const;


           
    };
}