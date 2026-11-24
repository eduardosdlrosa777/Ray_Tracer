#pragma once

namespace scn {
    class ImageConfig{
        private:
        int ancho;
        int alto;
        public:
        ImageConfig(int ancho, int alto);
        //getters
        int getAncho() const;
        int getAlto() const;
        //getters
        void setAncho(int anchoNuevo);
        void setAlto(int altoNuevo);
    };
}