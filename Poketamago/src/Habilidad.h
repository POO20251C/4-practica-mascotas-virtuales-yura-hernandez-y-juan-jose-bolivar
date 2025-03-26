//
// Created by Yura on 26/03/2025.
//

#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>

class Habilidad {

    private:
    std::string nombre;
    int daño;


    public:
    Habilidad(std::string nombre, int daño);
    std::string getNombre();
    int getDano();

    void setDano(int dano);
    void setNombre(std::string nombre);
};



#endif //HABILIDAD_H
