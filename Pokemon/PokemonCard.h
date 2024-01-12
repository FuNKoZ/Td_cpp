//
// Created by clement on 15/12/23.
//

#ifndef POKEMON_POKEMONCARD_H
#define POKEMON_POKEMONCARD_H

#include <vector>
#include <tuple>
#include "Card.h"
#include "EnergyCard.h"


using namespace std;

class PokemonCard : public Card
{
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, string, int>> attacks;
    int numberOfEnergy;


public:
    PokemonCard(const string&,const string&,const string&,const int,const int,const int,const string&,const int,const int,const string&,const int);

    string& getType();

    bool reduceHp(int);
    tuple<int, string, int> getAttack(int);
    void fullHeal();

    string displayInfo();

    int getNumberOfEnergy();

    void minusNumberOfEnergy(int number);

    void attachEnergy();
};

#endif //POKEMON_POKEMONCARD_H
