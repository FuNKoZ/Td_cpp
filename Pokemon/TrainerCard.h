//
// Created by clement on 15/12/23.
//

#ifndef POKEMON_TRAINERCARD_H
#define POKEMON_TRAINERCARD_H

#include "Card.h"

class TrainerCard : public Card{

private:

    string cardName;
    string trainerEffect;

public:
    TrainerCard(const string& name,const string& effect);
    string& getTrainerEffect();

    string displayInfo() override;
};


#endif //POKEMON_TRAINERCARD_H
