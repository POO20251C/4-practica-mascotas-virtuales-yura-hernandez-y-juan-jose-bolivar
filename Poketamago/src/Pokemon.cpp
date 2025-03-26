//
// Created by Yura on 26/03/2025.
//

#include "Pokemon.h"
#include "Truco.h"


Pokemon::Pokemon(std::string name, std::string entrenador) {
    this->nombre = name;
    this->entrenador = entrenador;
    this->salud = 100;
    this->lvl = 0;
    this->xp = 0;
    this->hambre = 0;
    this->estadoDeAnimo = "Normal";
}

Pokemon::~Pokemon() {

}

std::string Pokemon::getName() {
    return this->nombre;
}

std::string Pokemon::getEntrenador() {
    return this->entrenador;
}

int Pokemon::getSalud() {
    return this->salud;
}

int Pokemon::getLvl() {
    return this->lvl;
}

int Pokemon::getXp() {
    return this->xp;
}

int Pokemon::getHambre() {
    return this->hambre;
}

std::string Pokemon::mostrarHabilidades() {
    std::string ans = "#        Nombre          dano";
    for (int i = 0; i < habilidades.size(); i++) {
        ans += std::to_string(i+1) + ". " + habilidades[i]->getNombre() + " " + std::to_string(habilidades[i]->getDano()) + "\n";
    }
    return ans;
}

std::string Pokemon::mostrarTrucos() {
    std::string ans = "";
    for (int i = 0; i < trucos.size(); i++) {
        ans += std::to_string(i+1) + ". " + trucos[i]->getNombre() + "\n";
    }
    return ans;
}

std::string Pokemon::hacerTruco(std::string nombre) {
    std::string ans = "";
    for (int i = 0; i < trucos.size(); i++) {
        if (trucos[i]->getNombre() == nombre) {
            ans += this->nombre + " hizo " + trucos[i]->getNombre() + " y gano " + std::to_string(trucos[i]->getXp()) + "XP\n";
            this->xp += trucos[i]->getXp();
            this->barraDeAnimo += trucos[i]->getAnimo();
        }
    }
    return ans;
}

bool Pokemon::evolucionar() {
    bool ans = false;
    if (this->getXp() >= 100) {
        ans = true;
    }
    return ans;
}

std::string Pokemon::obtenerHabilidad(std::string nombre) {
    std::string ans = "";
    habilidades.push_back(new Habilidad(nombre, rand()));
    ans += "El pokemon " + this->nombre + " obtuvo la habilidad " + nombre;
    return ans;
}

void Pokemon::setHambre(int hambre) {
    this->hambre = hambre;
}

void Pokemon::setLvl(int lvl) {
    this->lvl = lvl;
}

void Pokemon::setXp(int xp) {
    this->xp = xp;
}

void Pokemon::setSalud(int salud) {
    this->salud = salud;
}

int Pokemon::usarHabilidad() {
    int ans = 0;
    for (int i = 0; i < habilidades.size(); i++) {
        ans = habilidades[i]->getDano();
    }
    return ans;
}

int Pokemon::getBarraDeAnimo() {
    return this->barraDeAnimo;
}

void Pokemon::setBarraDeAnimo(int barraDeAnimo) {
    this->barraDeAnimo = barraDeAnimo;
}

std::string Pokemon::mostrarInfo() {
    std::string ans = "";
    ans += "Nombre: " + this->nombre + "\n";
    ans += "Lvl: " + std::to_string(this->lvl) + "\n";
    ans += "Xp: " + std::to_string(this->xp) + "\n";
    ans += "Hambre: " + std::to_string(this->hambre) + "\n";
    ans += "Estado Animo: " + this->estadoDeAnimo + "\n";
    ans += "Cantidad de habilidades: " + std::to_string(habilidades.size()) + "\n";
    return ans;
}