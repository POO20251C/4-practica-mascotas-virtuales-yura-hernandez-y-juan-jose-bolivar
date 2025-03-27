//
// Created by Yura on 26/03/2025.
//

#include "Habilidad.h"


Habilidad::Habilidad(std::string nombre, int daño) {
    this->nombre = nombre;
    this->daño = daño;
}

std::string Habilidad::getNombre() {
    return nombre;
}

int Habilidad::getDano() {
    return daño;
}

void Habilidad::setDano(int dano) {
    dano = daño;
}

void Habilidad::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Habilidad::infoHabilidad() {
    std::string ans;

    ans += "Nombre: " + this->nombre + "\n";
    ans += "Daño: " + std::to_string(this->daño) + "\n";

    return ans;
}
