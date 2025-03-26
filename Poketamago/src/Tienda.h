//
// Created by juanj on 26/03/2025.
//

#ifndef TIENDA_H
#define TIENDA_H
#include "Objeto.h"
#include <string>

class Tienda{
  private:
     std::string nombre;
     std::vector <Objeto*> disponibles;

  public:
    Tienda(std::string nombre);

    std::string getNombre() ;
    void setNombre(std::string nombre);

    std::vector <Objeto*> getDisponibles();
    void setDisponibles(Objeto* disponibles);
    void setDisponibles(nombre* disponibles);

    void agregarObjeto(Objeto* objeto);
    void comprarObjeto(std::string nombre, int cantidad);

};


#endif //TIENDA_H
