//
// Created by juanj on 26/03/2025.
//

#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <string>
#include "Entrenador.h"

using namespace std;

class Objeto{

  private:

    string nombre;
    int precio;
    int saciedad;
    int xp;
    int stock;

  public:

    Objeto(string nombre, int precio, int saciedad, int xp, int stock);
    string getNombre();
    int getPrecio();
    int getSaciedad();
    int getXp();
    int getStock();

    int setNombre(string nombre);
    int setPrecio(int precio);
    int setSaciedad(int saciedad);
    int setXp(int xp);
    int setStock(int stock);


#endif //OBJETO_H
