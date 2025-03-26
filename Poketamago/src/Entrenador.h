//
// Created by Yura on 26/03/2025.
//

#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <map>
#include <string>

#include "Pokemon.h"
#include "Objeto.h"

class Entrenador {

  private:
    std::string nombre;
    int dinero;
    std::map<std::string, Pokemon* > pokemones;
    std::vector<std::pair<Objeto, int>> objetos;
    int trucosTotales;
    int objetosComprados;
    int batallas;

    public:
    Entrenador(std::string nombre);
    ~Entrenador();

    // setters
    void setNombre(std::string nombre);
    void setDinero(int dinero);

    // getters
    std::string getNombre();
    int getDinero();

    // metodos
    std::string verInformacionPokemon(std::string nombre);
    std::string verInformacionGeneral();
    std::string verObjetos();

    std::string agregarPokemon(std::string nombre);
    std::string agregarObjeto(int cantidad, Objeto objeto);







};



#endif //ENTRENADOR_H
