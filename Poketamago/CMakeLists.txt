cmake_minimum_required(VERSION 3.30)
project(Poketamago)

set(CMAKE_CXX_STANDARD 20)

add_executable(Poketamago main.cpp
        src/Habilidad.cpp
        src/Habilidad.h
        src/Pokemon.cpp
        src/Pokemon.h
        src/Entrenador.cpp
        src/Entrenador.h
        src/Tienda.h
        src/Tienda.cpp
        src/Truco.h
        src/Truco.cpp
        src/Objeto.h
        src/Objeto.cpp


)
