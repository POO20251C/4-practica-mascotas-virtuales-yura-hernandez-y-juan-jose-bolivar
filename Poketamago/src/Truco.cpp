//
// Created by juanj on 26/03/2025.
//

#include "Truco.h"
#include <string>



Truco::Truco(std::string nombre, int xp, std::string animo) {

  this->setNombre(nombre);
  this->setXp(xp);
  this->setAnimo(animo);

}

std::string Truco::getNombre() {
  return nombre;
}

std::string Truco::getAnimo() {
  return animo;
}

string Truco::getXp(int xp) {
  return xp;
}

void Truco::setNombre(std::string nombre) {
  this ->nombre = nombre;
}

void Truco::setAnimo(int animo) {
  this->animo = animo;
}

void Truco::setXp(int xp) {
  this->xp = xp;
}


