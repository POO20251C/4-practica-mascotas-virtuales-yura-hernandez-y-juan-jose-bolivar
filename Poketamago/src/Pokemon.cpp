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
    this->trucos.push_back(new Truco("Almendruco", rand() % 50, rand() % 50));
    this->vivo = true;
    this->habilidades.push_back(new Habilidad("Placaje", 50));
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

std::string Pokemon::getEstadoDeAnimo() {
    return this->estadoDeAnimo;
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
    std::string estadoAnterior = this->estadoDeAnimo;
    for (int i = 0; i < trucos.size(); i++) {
        if (trucos[i]->getNombre() == nombre) {
            ans += this->nombre + " hizo " + trucos[i]->getNombre() + " y gano " + std::to_string(trucos[i]->getXp()) + "XP\n";
            this->xp += trucos[i]->getXp();
            this->barraDeAnimo += trucos[i]->getAnimo();

            if (this->barraDeAnimo >= 66) {
                this->estadoDeAnimo = "Excitadisimo";
            } else if (this->barraDeAnimo >= 33 && this->barraDeAnimo <= 65) {
                this->estadoDeAnimo = "Normal";
            } else if (this->barraDeAnimo <= 32 ) {
                this->estadoDeAnimo = "Triste";
            }
            return ans;
        }
    }

    if (estadoAnterior != this->estadoDeAnimo) {
        ans += "El estado de ánimo de " + this->nombre + " ahora es " + this->estadoDeAnimo + ".\n";
    }

    return ans;
}

bool Pokemon::evolucionar() {
    bool ans = false;
    if (this->getXp() >= 100) {
        ans = true;
        this->lvl++;
        this->xp = 0;
    }
    return ans;
}

std::string Pokemon::obtenerHabilidad(std::string nombre) {
    std::string ans;
    const int dano = rand();
    habilidades.push_back(new Habilidad(nombre, dano));
    ans += "El pokemon " + this->nombre + " obtuvo la habilidad " + nombre + " con daño " + std::to_string(dano) + "\n";
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

int Pokemon::usarHabilidad(int i) {
    int ans = 0;
    ans = habilidades[i]->getDano();

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
    ans += "PS: " + std::to_string(this->salud) + "\n";
    ans += "Lvl: " + std::to_string(this->lvl) + "\n";
    ans += "Xp: " + std::to_string(this->xp) + "\n";
    ans += "Hambre: " + std::to_string(this->hambre) + "\n";
    ans += "Estado Animo: " + this->estadoDeAnimo + "\n";
    ans += "Cantidad de habilidades: " + std::to_string(habilidades.size()) + "\n";
    return ans;
}

std::vector<Truco *> Pokemon::getTrucos() {
    return this->trucos;
}

std::string Pokemon::obtenerTruco(std::string nombre) {
    std::string ans;
    trucos.push_back(new Truco(nombre, rand(), rand()));
    ans += "El pokemon " + this->nombre + " obtuvo el truco " + nombre + "\n";
    return ans;
}

std::string Pokemon::infoTrucos() {
    std::string ans;

    for (int i = 0; i < trucos.size(); i++) {
        ans += trucos[i]->infoTruco();
    }

    return ans += "\n";
}

std::string Pokemon::infoHabilidades() {
    std::string ans;
    for (int i = 0; i < habilidades.size(); i++) {
        ans += habilidades[i]->infoHabilidad();
    }
    return ans += "\n";
}

bool Pokemon::getVivo() {
    return this->vivo;
}

std::vector<Habilidad *> Pokemon::getHabilidades() {
    return this->habilidades;
}


std::string Pokemon::recibirDano(int dano) {
    std::string ans;
    int vidaDespuesDeDaño = this->salud - dano;
    if (!this->vivo) {
        ans += "El pokemon " + this->nombre + " esta fuera de combate, no puede recibir mas daño\n";
    }
    else if (vidaDespuesDeDaño <= 0) {
        this->salud = 0;
        this->vivo = false;
        ans += "El pokemon " + this->getName() + " recibio " + std::to_string(dano) + " y quedo fuera de combate\n";
    }
    else {
        this->salud -= dano;
        ans += "El pokemon " + this->getName() + " recibio " + std::to_string(dano) + " de daño\n";
    }

    return ans;
}

std::string Pokemon::infoHabilidad(const int i) const {
    return habilidades[i]->infoHabilidad();
}






