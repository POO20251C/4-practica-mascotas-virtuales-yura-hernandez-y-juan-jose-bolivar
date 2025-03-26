//
// Created by juanj on 26/03/2025.
//

#include "Objeto.h"
#include <string>


Objeto::Objeto(std::string nombre, int precio, int saciedad, int xp, int stock) {
    this->nombre = nombre;
    this->precio = precio;
    this->saciedad = saciedad;
    this->xp = xp;
    this->stock = stock;
}
std::string Objeto::getNombre()  {
    return nombre;
}

int Objeto::getPrecio()  {
    return precio;
}

int Objeto::getSaciedad()  {
    return saciedad;
}

int Objeto::getXp()  {
    return xp;
}

int Objeto::getStock()  {
    return stock;
}


void Objeto::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Objeto::setPrecio(int precio) {
    this->precio = precio;
}

void Objeto::setSaciedad(int saciedad) {
    this->saciedad = saciedad;
}

void Objeto::setXp(int xp) {
    this->xp = xp;
}

void Objeto::setStock(int stock) {
    this->stock = stock;
}
