//
// Created by clement on 15/12/23.
//

#ifndef POKEMON_ENERGYCARD_H
#define POKEMON_ENERGYCARD_H

#include "Card.h"

class EnergyCard : public Card{

private:
    string energyType;

public:

    EnergyCard(const string& type);
    string& getType();

};


#endif //POKEMON_ENERGYCARD_H
