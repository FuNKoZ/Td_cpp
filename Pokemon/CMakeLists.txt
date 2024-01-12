cmake_minimum_required(VERSION 3.27)
project(Pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pokemon main.cpp
        Card.cpp
        Card.h
        PokemonCard.cpp
        PokemonCard.h
        EnergyCard.cpp
        EnergyCard.h
        TrainerCard.cpp
        TrainerCard.h
        Player.cpp
        Player.h)
