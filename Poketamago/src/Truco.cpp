//
// Created by juanj on 26/03/2025.
//

#include "Truco.h"

#include <charconv>

Truco::Truco(std::string nombre, int xp, int animo){
  this->nombre = nombre;
  this->xp = xp;
  this->animo = animo;
}

std::string Truco::getNombre() {
  return nombre;
}

int Truco::getAnimo() {
  return animo;
}

int Truco::getXp() {
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

std::string Truco::infoTruco() {
  std::string ans;

  ans += "Nombre: " + this->nombre + "\n";
  ans += "Animo: " + std::to_string(this->animo) + "\n";
  ans += "Xp: " + std::to_string(this->xp) + "\n";

  return ans;

}

