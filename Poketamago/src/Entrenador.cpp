//
// Created by Yura on 26/03/2025.
//

#include "Entrenador.h"

Entrenador::Entrenador(std::string nombre) {
    this->nombre = nombre;
    this->dinero = 500;
    this->trucosTotales = 0;
    this->objetosComprados = 0;
}

Entrenador::~Entrenador() {

}

std::string Entrenador::getNombre() {
    return this->nombre;
}

int Entrenador::getDinero() {
    return this->dinero;
}

void Entrenador::setDinero(int d) {
    this->dinero = d;
}

void Entrenador::setNombre(std::string n) {
    this->nombre = n;
}

std::string Entrenador::agregarPokemon(std::string nombre) {
    string ans = "Se agregando el pokemon: " + nombre + "\n";
    this->pokemones[nombre] = new Pokemon(nombre, this->nombre);
    return ans;
    }

std::string Entrenador::verObjetos() {
    std::string ans = "#    Nombre      cantidad\n";
    for (int i = 0; i < this->objetos.size(); i++) {
        ans += to_string(i+1) + ". " + this->objetos[i].first.getNombre() + " " + to_string(this->objetos[i].second) + "\n";
    }
    return ans;
}

std::string Entrenador::agregarObjeto(int cantidad, Objeto objeto) {
    string ans;
    pair<Objeto, int> hola = make_pair(objeto, cantidad);
    objetos.push_back(hola);
    ans += "Se agrego el objeto " + objeto.getNombre() + "\n";
    return ans;
}

std::string Entrenador::verInformacionGeneral() {
    string ans;
    ans += "Nombre: " + this->nombre + "\n";
    ans += "Cantidad de pokemones: " + to_string(pokemones.size()) + "\n";
    ans += "Cantidad de objetos: " + to_string(this->objetos.size()) + "\n";
    ans += "Trucos realizados: " + to_string(this->trucosTotales) + "\n";
    ans += "Objetos comprados: " + to_string(this->objetosComprados) + "\n";
    ans += "Batallas ganadas: " + to_string(this->batallas) + "\n";
    return ans;

}

std::string Entrenador::verInformacionPokemon(std::string nombre) {
    return this->pokemones[nombre]->mostrarInfo();
}