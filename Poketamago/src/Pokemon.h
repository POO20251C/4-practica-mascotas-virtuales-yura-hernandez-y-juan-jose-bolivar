//
// Created by Yura on 26/03/2025.
//

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

#include "Habilidad.h"

class Pokemon {

  private:
  std::string nombre;
  std::string entrenador;
  std::string estadoDeAnimo;
  int barraDeAnimo;
  int hambre;
  int lvl;
  int xp;
  int salud;

  std::vector<Habilidad*> habilidades;
  std::vector<Truco*> trucos;

  public:
  Pokemon(std::string name, std::string entrenador);
  ~Pokemon();

  // getters
  std::string getName();
  std::string getEntrenador();
  int getBarraDeAnimo();
  int getHambre();
  int getLvl();
  int getXp();
  int getSalud();
  std::string mostrarHabilidades();
  std::string mostrarTrucos();

  // setters
  void setBarraDeAnimo(int barraDeAnimo);
  void setHambre(int hambre);
  void setLvl(int lvl);
  void setXp(int xp);
  void setSalud(int salud);


  // metodos
  std::string hacerTruco(std::string nombre);
  int usarHabilidad();
  std::string obtenerHabilidad(std::string nombre);

  bool evolucionar();
};



#endif //POKEMON_H
