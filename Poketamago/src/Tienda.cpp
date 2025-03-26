//
// Created by Yura on 26/03/2025.
//

#include "Tienda.h"

Tienda::Tienda(std::string nombre) {
    this->nombre = nombre;
}

std::string Tienda::getNombre() {
    return this->nombre;
}

void Tienda::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Tienda::comprarObjeto(std::string nombre, int cantidad) {

}

void Tienda::agregarObjeto(Objeto *objeto) {
    this->disponibles.push_back(objeto);
}

void Tienda::setVectorObjetos(std::vector<Objeto *> nuevosObjetos) {
    // Funciona para cargar archivos de guardado.
    this->disponibles = nuevosObjetos;
}