//
// Created by juanj on 26/03/2025.
//

#ifndef OBJETO_H
#define OBJETO_H
#include <string>

using namespace std;

class Objeto {

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

  void setNombre(string nombre);
  void setPrecio(int precio);
  void setSaciedad(int saciedad);
  void setXp(int xp);
  void setStock(int stock);
};


#endif //OBJETO_H
