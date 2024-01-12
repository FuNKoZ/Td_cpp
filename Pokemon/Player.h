//
// Created by clement on 22/12/23.
//

#ifndef POKEMON_PLAYER_H
#define POKEMON_PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "PokemonCard.h"
#include "TrainerCard.h"
#include "EnergyCard.h"

using namespace std;

class Player {

private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string&);
    string& getName();
    void addCardToBench(Card *);
    void activatePokemonCard(int);
    void attachEnergyCard(int, int);
    void attack(int, int, Player&, int);
    void displayBench();
    void displayAction();
    void useTrainer(int trainerIndex);
    vector<PokemonCard*> getActionCards();
    void killPoke(int index);
    PokemonCard *getCard(int i);
};


#endif //POKEMON_PLAYER_H
