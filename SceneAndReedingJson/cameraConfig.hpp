#pragma once
//#include "Vec3.hpp o .cpp"
namespace scn {
    class CameraConfig {
        private:
        vec3 posicion;
        vec3 mira_a;
        int fov; 
        public:
        CameraConfig( const Vec3& posicion, const Vec3& mira_a, double fov); 
           
    };
}