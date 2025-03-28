//
// Created by juanj on 26/03/2025.
//

#ifndef TIENDA_H
#define TIENDA_H


#include "Objeto.h"
#include <string>
#include <vector>

class Tienda {
  private:
     std::string nombre;
     std::vector <Objeto*> disponibles;

  public:
    Tienda(std::string nombre);

    std::string getNombre();
    void setNombre(std::string nombre);

    void setVectorObjetos(std::vector<Objeto*> nuevosObjetos);

    void agregarObjeto(Objeto* objeto);
    void comprarObjeto(std::string nombre, int cantidad);
    vector<Objeto*>* getDisponibles();



    string mostrarObjetos();

};
#endif //TIENDA_H