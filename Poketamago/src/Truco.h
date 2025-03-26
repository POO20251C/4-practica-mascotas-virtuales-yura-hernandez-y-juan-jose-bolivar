//
// Created by juanj on 26/03/2025.
//

#ifndef TRUCO_H
#define TRUCO_H
#include "Pokemon.h"
#include <string>

class Truco{

  private:
    std::string nombre;
    int xp;
    int animo;

  public:
    Truco(std::string nombre, int xp, int animo);
    std::string getNombre();

    int getXp();
    int getAnimo();

    void setNombre(std::string nombre);
    void setXp(int xp);
    void setAnimo(int animo);


};


#endif //TRUCO_H
