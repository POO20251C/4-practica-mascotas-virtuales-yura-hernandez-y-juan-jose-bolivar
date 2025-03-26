#include <iostream>
#include <vector>
#include <map>
#include <fstream>

#include "src/Entrenador.h"
#include "src/Pokemon.h"
#include "src/Objeto.h"

using namespace std;

string stringToLower(string s) {
    string ans;
    for (int i = 0; i < s.length(); i++) {
        ans += tolower(s[i]);
    }
    return ans;
}

int main() {

    map<string,Entrenador*> entrenadoresEnJuego;

    bool entrenadores = true;
    string menu1;
    while (entrenadores) {
        cout << "1. Agregar un entrenador\n 2. Usar entrenador\n 3. Listar entrenadores\n Agregue un comando: ";
        cin >> menu1;

        if (menu1 == "1") {
            string nombre;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            if (entrenadoresEnJuego.find(nombre) != entrenadoresEnJuego.end()) {
                entrenadoresEnJuego[nombre] = new Entrenador(nombre);
                cout << "Se creo el entrenador: " + nombre << endl;
            }
            else {
                bool validOption = true;
                while (validOption) {
                    string sobreEscribir;
                    cout << "Desea sobre escribir el entrenador " + nombre + " ?\n" << endl;
                    cout << "S/N: " << endl;
                    cin >> sobreEscribir;
                    if (stringToLower(sobreEscribir) == "s" ) {
                        delete entrenadoresEnJuego[nombre];
                        entrenadoresEnJuego[nombre] = new Entrenador(nombre);
                        cout << "Se sobre escribio el entrenador: " + nombre << endl;
                        validOption = false;
                    }
                    else if (stringToLower(sobreEscribir) == "n") {
                        cout << "Volviendo al menu principal....\n";
                        validOption = false;
                    }
                    else {
                        cout << "Opcion no valida";
                    }
                }

            }

        }

        else if (menu1 == "2") {
            string nombre;
            cout << "Ingrese el nombre del entrenador: ";
            cin >> nombre;
            for (int i = 0; i < entrenadoresEnJuego.size(); i++) {
                if (entrenadoresEnJuego[nombre] != nullptr) {

                    // Menu entrenador








                }
                else {
                    cout << "No se encontro el entrenador " + nombre << endl;
                    cout << "Volviendo al menu principal....\n";
                }
            }
        }
        else if (menu1 == "3") {
            for (const auto &i : entrenadoresEnJuego) {
                cout << i.first << endl;
            }
        }

    }


    return 0;
}