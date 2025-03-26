//
// Created by juanj on 26/03/2025.
//

#ifndef TRUCO_H
#define TRUCO_H
#include "Pokemon.h"
#include <string>

class Truco{

  private:

    string nombre;
    int xp;
    int animo;

  public:
    truco(string nombre, int xp, int animo);
    string getNombre();
    int getXp();
    int getAnimo();

    string setNombre(string nombre);
    void setXp(int xp);
    void setAnimo(int animo);


}


#endif //TRUCO_H
