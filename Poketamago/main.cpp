#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <filesystem>


#include "src/Entrenador.h"
#include "src/Pokemon.h"
#include "src/Objeto.h"
#include "src/Truco.h"
#include "src/Tienda.h"

using namespace std;

void guardarHistorial(map<string, Entrenador*>& entrenadoresEnJuego) {
    filesystem::create_directory("saves");

    ofstream archivo("../saves/historial.txt");
    if (archivo.is_open()) {

        if (!entrenadoresEnJuego.empty()) {

            archivo << "Historial de Entrenadores y sus Pokémon:\n";
            for ( auto& [nombre, entrenador] : entrenadoresEnJuego) {
                archivo << "Entrenador:" << "\n";
                archivo << entrenador->verInformacionGeneral() + "\n";
                archivo << "Pokémones:\n";
                for ( auto& [nombrePokemon, pokemon] : entrenador->getPokemones()) {
                    archivo << pokemon->mostrarInfo() << "\n";
                }
                archivo << "--------------------------\n";
            }

        }
        archivo.close();
        cout << "Historial guardado en historial.txt\n";
    }




}

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

vector<Pokemon*> convertirAVector(const map<string, Pokemon*> &lista) {
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

    srand(time(nullptr));

    Objeto caci("Caci", 3, 20, 20, 50, 40);
    Objeto caramelo("Caramelo", 4, 2, 100, 50, 1);

    Tienda t1("Tienda");

    t1.agregarObjeto(&caramelo);
    t1.agregarObjeto(&caci);

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
            if (entrenadoresEnJuego.find(nombre) != entrenadoresEnJuego.end()) {
                // Menu entrenador
                    bool menuEntrenador = true;
                    while (menuEntrenador == true) {
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

                        int comandoEntrenador;
                        cout << "1. Agregar pokemon\n2. Hacer un truco con un pokemon\n3. Dar objeto a un pokemon\n4. Ir a la tienda\n5. Hacer un combate\n6. Ver informacion\n7. Ver pokemones\n8. Salir\n";
                        cout << "Ingrese un comando: ";
                        cin >> comandoEntrenador;

                        if (comandoEntrenador == 8) {
                            menuEntrenador = false;
                            cout << "Saliendo al menu principal...\n";
                            cout << endl;
                        }
                        else if (comandoEntrenador == 7) {
                            cout << entrenadoresEnJuego[nombre]->verPokemones();
                        }
                        else if (comandoEntrenador == 6) {
                            cout << entrenadoresEnJuego[nombre]->verInformacionGeneral() << endl;
                        }
                        else if (comandoEntrenador == 1) {
                            string nombrePokemonNuevo;
                            cout << "Ingrese el nombre del pokemon: ";
                            cin >> nombrePokemonNuevo;

                            cout << entrenadoresEnJuego[nombre]->agregarPokemon(nombrePokemonNuevo) << endl;
                        }
                        else if (comandoEntrenador == 2) {
                            string nombrePokemontruco;
                            cout << "Que pokemon va a hacer el truco?\n";

                            cout << entrenadoresEnJuego[nombre]->verPokemones() << endl;

                            cout << "Ingrese el nombre: ";
                            cin >> nombrePokemontruco;

                            for (const auto& k: entrenadoresEnJuego[nombre]->getPokemones()) {
                                if (k.second->getName() == nombrePokemontruco) {
                                    int truco;
                                    bool trucoEncontrado = false;
                                    vector<Truco*> trucos = k.second->getTrucos();
                                    cout << k.second->mostrarTrucos();

                                    cout << "Seleccione el truco: ";
                                    cin >> truco;
                                    for (const auto& t: trucos) {
                                        if (truco <= 1 || truco >= trucos.size() ) {
                                            trucoEncontrado = true;
                                        }

                                    }
                                    if (!trucoEncontrado) {
                                        cout << "El truco no existe\n";
                                    }else {
                                        cout << k.second->hacerTruco(trucos[truco - 1]->getNombre()) << endl;
                                        cout << "El estado de animo cambio a: " << k.second->getEstadoDeAnimo()<< endl;
                                    }
                                }
                            }
                        }
                        else if (comandoEntrenador == 3) {
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

                                for (int i = 0; entrenadoresEnJuego[nombre]->getObjetos().size() > i; i++) {
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
                        else if (comandoEntrenador == 4) {

                            bool enTienda = true;
                            while (enTienda) {
                                string opcionTienda = "";
                                cout << "1. Comprar Objeto\n2. Listar objetos\n3. Salir\n";
                                cout << "Ingrese una opcion: ";
                                getline(cin, opcionTienda);

                                if (opcionTienda == "1") {

                                    cout << t1.mostrarObjetos();
                                    cout << endl;

                                    std::string nombreObjeto;
                                    int cantidad;

                                    std::cout << "Ingrese el nombre del objeto que desea comprar: ";
                                    std::cin >> nombreObjeto;

                                    std::cout << "Ingrese la cantidad que desea comprar: ";
                                    std::cin >> cantidad;

                                    bool encontrado = false;
                                    for (auto &item : *t1.getDisponibles()) {

                                        if (item->getNombre() == nombreObjeto) {
                                            encontrado = true;
                                            int costoTotal = item->getPrecio() * cantidad;
                                            if (entrenadoresEnJuego[nombre]->getDinero() >= costoTotal && item->getStock() >= cantidad) {
                                                entrenadoresEnJuego[nombre]->setDinero(entrenadoresEnJuego[nombre]->getDinero() - costoTotal);
                                                entrenadoresEnJuego[nombre]->agregarObjeto(cantidad, *item);
                                                item->setStock(item->getStock() - cantidad);
                                                std::cout << "Compra exitosa! Has comprado " << cantidad << " " << nombreObjeto << " por " << costoTotal << " Oro.\n";
                                            } else if (entrenadoresEnJuego[nombre]->getDinero() < costoTotal) {
                                                std::cout << "No tienes suficiente dinero para comprar esta cantidad.\n";
                                            } else {
                                                std::cout << "No hay suficiente stock disponible en la tienda.\n";
                                            }
                                            // Lo hizo Boli no yo.
                                            break;
                                        }
                                    }
                                    if (!encontrado) {
                                        std::cout << "El objeto ingresado no existe en la tienda.\n";
                                    }
                                }
                                else if (opcionTienda == "2") {
                                    cout << t1.mostrarObjetos();
                                    cout << endl;
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
                        else if (comandoEntrenador == 5) {
                            string nombreOponente;
                            Entrenador *oponente = nullptr;
                            bool vamoAJugar = false;
                            vector<Pokemon*> pokemonesJugador;
                            vector<Pokemon*> pokemonesOponente;

                            for (const auto &e : entrenadoresEnJuego) {
                                if (e.first != nombre) {
                                    cout << e.first << endl;
                                }
                            }
                            cout << endl;

                            cout << "Ingresa el nombre de tu oponente: ";
                            cin >> nombreOponente;

                            if (entrenadoresEnJuego.find(nombreOponente) == entrenadoresEnJuego.end()) {
                                cout << "No se encontró el oponente\n";
                            }
                            else if (entrenadoresEnJuego[nombre]->getPokemones().empty()) {
                                cout << "No tienes pokemones para combatir\n";
                            }

                            else {
                                oponente = entrenadoresEnJuego[nombreOponente];
                                vamoAJugar = true;
                            }

                            if (oponente->getPokemones().empty()) {
                                cout << "El oponente no tiene pokemones para combatir\n";
                                vamoAJugar = false;
                            }


                            if (vamoAJugar) {
                                 pokemonesJugador = convertirAVector(entrenadoresEnJuego[nombre]->getPokemones());
                                 pokemonesOponente = convertirAVector(oponente->getPokemones());
                            }

                            int muertosOponente = 0, muertosJugador = 0;
                            while (vamoAJugar) {
                                // Juego

                                int opcionJugador, opcionOponente;
                                cout << entrenadoresEnJuego[nombre]->verPokemones();
                                cout << endl;


                                for (int j = 0; j < pokemonesJugador.size(); j++) {
                                    cout << j + 1 << ". " << pokemonesJugador[j]->getName() << endl;
                                }
                                cout << endl;

                                cout << "Selecciona el pokemon que va a atacar: ";
                                cin >> opcionJugador;

                                if (opcionJugador >= 1 || opcionJugador <= pokemonesJugador.size() ) {
                                    Pokemon * pokemonSeleccionado = pokemonesJugador[opcionJugador];
                                    if (pokemonesJugador[opcionJugador - 1]->getVivo()) {
                                        int habilidadSeleccionada;

                                        for (int i = 0; i < pokemonesJugador[opcionJugador - 1]->getHabilidades().size(); i++) {
                                            cout << i + 1 << ". \n" <<pokemonesJugador[opcionJugador - 1]->infoHabilidad(i) << endl;
                                        }

                                        cout << "Selecciona una habilidad: ";
                                        cin >> habilidadSeleccionada;

                                        if (habilidadSeleccionada >= 1 || habilidadSeleccionada <= pokemonSeleccionado->getHabilidades().size()) {
                                            int objetivoJugador;
                                            for (int o = 0; o < pokemonesOponente.size(); o++) {
                                                cout << o + 1 << ". " << pokemonesOponente[o]->getName() << " Vida: " << pokemonesOponente[o]->getSalud() << endl;
                                            }

                                            cout << endl;
                                            cout << "Selecciona un objetivo: ";
                                            cin >> objetivoJugador;

                                            if (objetivoJugador >= 1 || objetivoJugador <= pokemonesOponente.size()) {
                                                cout << pokemonesOponente[objetivoJugador - 1]->recibirDano(pokemonesJugador[opcionJugador - 1]->usarHabilidad(habilidadSeleccionada - 1)) << endl;
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
                                        cout << "El pokemon seleccionado esta fuera de batalla.\nPierdes el turno";
                                    }
                                }
                                else {
                                    cout << "Opcion no valida, pierdes el turno\n";
                                }

                                cout << endl;


                                // Oponente. Quiero que sea aleatorio
                                int indicePokemonOponente = rand() % pokemonesOponente.size();
                                Pokemon * pokemonOponente = pokemonesOponente[indicePokemonOponente];

                                int indiceObjetivo = rand() % pokemonesJugador.size();
                                Pokemon* ObjetivoOponente = pokemonesJugador[indiceObjetivo];

                                int indiceHabilidad = rand() % pokemonOponente->getHabilidades().size();

                                if (pokemonOponente->getVivo()) {
                                    cout << "Turno del oponente\n";
                                    cout << ObjetivoOponente->recibirDano(pokemonOponente->usarHabilidad(indiceHabilidad)) << endl;
                                }

                                // Verificar quien gana
                                int killO = 0;
                                for (int k = 0; k < pokemonesOponente.size(); k++) {
                                    if (!pokemonesOponente[k]->getVivo()) {
                                        killO += 1;
                                    }
                                }
                                muertosOponente = killO;

                                int killJ = 0;
                                for (int k = 0; k < pokemonesJugador.size(); k++) {
                                    if (!pokemonesJugador[k]->getVivo()) {
                                        killJ += 1;
                                    }
                                }
                                muertosJugador = killJ;

                                if (muertosJugador == pokemonesJugador.size() ) {
                                    cout << "Perdiste.\nGano " << oponente->getNombre() << ".\n";
                                    vamoAJugar = false;
                                    pokemonesJugador.clear();
                                    pokemonesOponente.clear();
                                }
                                else if (muertosOponente == pokemonesOponente.size()) {
                                    cout << "Gano " << nombre << "\n";
                                    vamoAJugar = false;
                                    entrenadoresEnJuego[nombre]->aumentarBatallas();
                                    entrenadoresEnJuego[nombre]->setDinero(entrenadoresEnJuego[nombre]->getDinero() + 300);
                                    cout << "Ganaste 300 de oro\n";
                                    pokemonesJugador.clear();
                                    pokemonesOponente.clear();
                                }

                            }
                        }
                        else {
                            cout << "Opcion no valida\n";
                            cin.clear();
                        }
                        if (cin.fail()) {
                            cin.clear();
                            cout << "Entrada inválida. Intenta de nuevo.\n";
                            continue;
                        }
                    }
                }
                else {
                    cout << "No se encontro el entrenador " + nombre << endl;
                    cout << "Volviendo al menu principal....\n";
                }
        }
        else if (menu1 == "3") {
            for (const auto &i : entrenadoresEnJuego) {
                cout << i.first << endl;
            }
            cout << endl;
        }
        else if (menu1 == "4") {
            cout << "Saliendo del programa\n";
            entrenadores = false;
        }
        else {
            cout << "Opcion no valida.\n";
        }

    }

    cout << endl;

    guardarHistorial(entrenadoresEnJuego);

    for (auto& e : entrenadoresEnJuego) {
        delete e.second;
    }

    return 0;
}