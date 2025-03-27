#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <random>

#include "src/Entrenador.h"
#include "src/Pokemon.h"
#include "src/Objeto.h"
#include "src/Truco.h"
#include "src/Tienda.h"

using namespace std;

void quitarPokemonDeVector(std::vector<Pokemon*>& lista) {
    for (auto it = lista.begin(); it != lista.end(); ) {
        if (!(*it)->getVivo()) {
            delete *it;
            it = lista.erase(it);
        } else {
            ++it;
        }
    }
}

vector<Pokemon*> convertirAVector(map<string, Pokemon*> lista) {
    vector<Pokemon*> pokemones;
    for (const auto &pokemon : lista) {
        pokemones.push_back(pokemon.second);
    }
    return pokemones;
}

string stringToLower(string s) {
    string ans;
    for (int i = 0; i < s.length(); i++) {
        ans += tolower(s[i]);
    }
    return ans;
}

int main() {



    Tienda t1("Tienda");

    map<string,Entrenador*> entrenadoresEnJuego;

    bool entrenadores = true;
    string menu1;
    while (entrenadores) {
        cout << "1. Agregar un entrenador\n2. Usar entrenador\n3. Listar entrenadores\n4. Salir\nAgregue un comando: ";
        cin >> menu1;

        if (menu1 == "1") {
            string nombre;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            if (entrenadoresEnJuego[nombre] == nullptr) {
                entrenadoresEnJuego[nombre] = new Entrenador(nombre);
                cout << "Se creo el entrenador: " + nombre << endl;
                cout << endl;
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
                    bool menuEntrenador = true;
                    // Menu entrenador
                    while (menuEntrenador) {

                        for (const auto &i : entrenadoresEnJuego[nombre]->getPokemones()) {
                            if (i.second->evolucionar()) {
                                if (i.second->getLvl() % 2 == 0) {
                                    string nombreHabilidad;
                                    cout << "El pokemon " << i.second->getName() << " ha evolucionado y va a ganar una habilidad\n";
                                    cout << "Ingrese el nombre de la habilidad: ";
                                    cin >> nombreHabilidad;

                                    cout << i.second->obtenerHabilidad(nombreHabilidad);
                                }
                                else {
                                    string nombreTruco;
                                    cout << "El pokemon " << i.second->getName() << " ha evolucionado y va a aprender un truco\n";
                                    cout << "Ingrese el nombre del truco: ";
                                    cin >> nombreTruco;
                                    cout << i.second->obtenerTruco(nombreTruco);
                                }

                            }
                        }

                        string comandoEntrenador;
                        cout << "1. Agregar pokemon\n2. Hacer un truco con un pokemon\n3. Dar objeto a un pokemon\n4. Ir a la tienda\n5. Hacer un combate\n6. Salir\n";
                        cout << "Ingrese un comando: ";
                        cin >> comandoEntrenador;

                        if (comandoEntrenador == "1") {
                            string nombrePokemonNuevo;
                            cout << "Ingrese el nombre del pokemon: ";
                            cin >> nombrePokemonNuevo;

                            cout << entrenadoresEnJuego[nombre]->agregarPokemon(nombrePokemonNuevo) << endl;
                        }

                        else if (comandoEntrenador == "2") {
                            string nombrePokemontruco;
                            cout << "Que pokemon va a hacer el truco?\n";
                            cout << entrenadoresEnJuego[nombre]->verPokemones() << endl;

                            cout << "Ingrese el nombre: ";
                            cin >> nombrePokemontruco;

                            for (const auto& k: entrenadoresEnJuego[nombre]->getPokemones()) {
                                if (k.second->getName() == nombrePokemontruco) {
                                    string truco;
                                    bool trucoEncontrado = false;
                                    vector<Truco*> trucos = k.second->getTrucos();
                                    cout << k.second->mostrarTrucos();

                                    cout << "Ingrese el nombre del truco a realizar: ";
                                    cin >> truco;
                                    // ARREGLAR ESTOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
                                    for (const auto& t: trucos) {
                                        if (truco == t->getNombre()) {
                                            trucoEncontrado = true;
                                        }
                                    }
                                    if (!trucoEncontrado) {
                                        cout << "El truco no existe\n";
                                    }else {
                                        cout << k.second->hacerTruco(truco) << endl;
                                    }
                                }
                            }
                        }

                        else if (comandoEntrenador == "3") {
                            string nombrePokemonObjeto;

                            cout << entrenadoresEnJuego[nombre]->verPokemones();

                            cout << "Ingrese el nombre del pokemon al cual se le va a dar el objeto: ";
                            cin >> nombrePokemonObjeto;


                            if (entrenadoresEnJuego[nombre]->getPokemones()[nombrePokemonObjeto] != nullptr) {
                                string objetoADar;
                                bool seEncontro = false;
                                cout << entrenadoresEnJuego[nombre]->verObjetos();

                                cout << "Ingrese el nombre del objeto: ";
                                cin >> objetoADar;

                                for (int j = 0; entrenadoresEnJuego[nombre]->getObjetos().size() > j; j++) {
                                    if (entrenadoresEnJuego[nombre]->getObjetos()[i].first.getNombre() == objetoADar) {
                                        cout << entrenadoresEnJuego[nombre]->alimentarPokemon(nombrePokemonObjeto, &entrenadoresEnJuego[nombre]->getObjetos()[i].first);
                                        entrenadoresEnJuego[nombre]->getObjetos()[i].second - 1;
                                        seEncontro = true;
                                        if (entrenadoresEnJuego[nombre]->getObjetos()[i].second == 0) {
                                            entrenadoresEnJuego[nombre]->getObjetos().erase(entrenadoresEnJuego[nombre]->getObjetos().begin() + i);
                                        }
                                        cout << "Volviendo al menu principal...\n";
                                    }
                                }

                                if (!seEncontro) {
                                    cout << "No se encontro el objeto " + objetoADar + "\n";
                                    cout<<endl;
                                }

                            }
                            else {
                                cout << "No se encontro el pokemon\n";
                            }

                        }

                        else if (comandoEntrenador == "4") {

                            bool enTienda = true;
                            while (enTienda) {
                                string opcionTienda;
                                cout << "1. Comprar Objeto\n2. Listar objetos\n3. Salir\n";
                                cout << "Ingrese una opcion: ";
                                cin >> opcionTienda;

                                if (opcionTienda == "1") {
                                    // terminar esto

                                }
                                else if (opcionTienda == "2") {
                                    cout << t1.mostrarObjetos();
                                }
                                else if (opcionTienda == "3") {
                                    enTienda = false;
                                    cout << "Volviendo...\n";
                                    cout << endl;
                                }
                                else {
                                    cout << "Opcion no valida.\n";
                                }
                            }

                        }
                        else if (comandoEntrenador == "5") {
                            string nombreOponente;
                            Entrenador *oponente = nullptr;
                            bool vamoAJugar = false;
                            int pokemonesVivosOponente,pokemonesVivos;
                            vector<Pokemon*> pokemonesJugador;
                            vector<Pokemon*> pokemonesOponente;

                            for (const auto &e : entrenadoresEnJuego) {
                                cout << e.first << endl;
                            }
                            cout << endl;

                            cout << "Ingresa el nombre de tu oponente: ";
                            cin >> nombreOponente;

                            if (entrenadoresEnJuego[nombreOponente] != nullptr) {
                                cout << "No se encontro el oponente\n";
                            }
                            else if (entrenadoresEnJuego[nombre]->getPokemones().empty()) {
                                cout << "No tienes pokemones para combatir\n";
                            }
                            else if (oponente->getPokemones().empty()) {
                                cout << "El oponente no tiene pokemones para combatir\n";
                            }
                            else {
                                oponente = entrenadoresEnJuego[nombreOponente];
                                vamoAJugar = true;
                            }


                            if (vamoAJugar) {
                                 pokemonesJugador = convertirAVector(entrenadoresEnJuego[nombre]->getPokemones());
                                 pokemonesOponente = convertirAVector(oponente->getPokemones());
                            }


                            while (vamoAJugar) {
                                // Juego

                                quitarPokemonDeVector(pokemonesJugador);
                                quitarPokemonDeVector(pokemonesOponente);

                                pokemonesVivos = pokemonesJugador.size();
                                pokemonesVivosOponente = pokemonesOponente.size();
                                int opcionJugador, opcionOponente;
                                cout << entrenadoresEnJuego[nombre]->verPokemones();
                                cout << endl;

                                for (auto & j : pokemonesJugador) {
                                    cout << i+1 << ". " << j->getName() << endl;
                                }
                                cout << endl;

                                cout << "Ingresa una opcion: ";
                                cin >> opcionJugador;

                                if ( opcionJugador <= pokemonesJugador.size() && pokemonesJugador[opcionJugador-1] != nullptr ) {

                                    if (pokemonesJugador[opcionJugador-1]->getVivo()) {
                                        int habilidadSeleccionada;
                                        cout << i+1 << ". \n" <<pokemonesJugador[opcionJugador-1]->infoHabilidades() << endl;
                                        cout << "Selecciona una habilidad: ";
                                        cin >> habilidadSeleccionada;

                                        if (habilidadSeleccionada <= pokemonesJugador[opcionJugador-1]->getHabilidades().size() && pokemonesJugador[opcionJugador-1]->getHabilidades()[habilidadSeleccionada-1] != nullptr ) {
                                            int objetivoJugador;
                                            for (auto & k : pokemonesOponente) {
                                                cout << i+1 << ". " << k->getName() << " Vida: " << k->getSalud() << endl;
                                            }

                                            cout << endl;
                                            cout << "Selecciona un objetivo: ";
                                            cin >> objetivoJugador;

                                            if (pokemonesOponente[objetivoJugador-1]->getVivo() && pokemonesOponente[objetivoJugador-1] != nullptr ) {
                                                cout << pokemonesOponente[objetivoJugador-1]->recibirDano(pokemonesJugador[opcionJugador-1]->usarHabilidad(habilidadSeleccionada)) << endl;
                                            }
                                            else {
                                                cout << "Objetivo no valido, pierdes el turno\n";
                                            }

                                        }
                                        else {
                                            cout << "Opcion no valida, pierdes el turno\n";
                                        }
                                    }
                                    else {
                                        cout << "El pokemon esta fuera de batalla.\nPierdes el turno";
                                    }
                                }
                                else {
                                    cout << "Opcion no valida, pierdes el turno\n";
                                }

                                cout << endl;
                                cout << "Turno del oponente\n";


                                // Oponente. Quiero que sea aleatorio
                                random_device rd;
                                mt19937 rng(rd());
                                uniform_int_distribution<size_t> dist(0, pokemonesOponente.size()-1);
                                Pokemon* pokemonOponente = pokemonesOponente[dist(rng)];
                                uniform_int_distribution<size_t> objetivoOponente(0, pokemonesJugador.size()-1);
                                Pokemon * pokemonObjetivoOponente = pokemonesJugador[objetivoOponente(rng)];
                                uniform_int_distribution<size_t> habilidad(0, pokemonOponente->getHabilidades().size()-1);

                                cout << pokemonObjetivoOponente->recibirDano(pokemonOponente->usarHabilidad(habilidad(rng))) << endl;


                                // Verificar quien gana
                                if (pokemonesVivos == 0 ) {
                                    cout << "Perdiste.\nGano " << oponente->getNombre() << ".\n";
                                    vamoAJugar = false;
                                }
                                else if (pokemonesVivosOponente == 0) {
                                    cout << "Gano " << nombre << "\n";
                                    vamoAJugar = false;
                                    entrenadoresEnJuego[nombre]->aumentarBatallas();
                                    entrenadoresEnJuego[nombre]->setDinero(entrenadoresEnJuego[nombre]->getDinero() + 300);
                                    cout << "Ganaste 300 de oro\n";

                                }

                            }

                        }

                        else if (comandoEntrenador == "6") {
                            menuEntrenador = false;
                        }

                        else {
                            cout << "Opcion no valida\n";
                        }





                    }







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
            cout << endl;
        }
        else if (menu1 == "4") {
            cout << "Saliendo del programa";
            entrenadores = false;
        }
        else {
            cout << "Opcion no valida.\n";
        }

    }


    return 0;
}