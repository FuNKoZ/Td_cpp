//
// Created by clement on 15/12/23.
//

#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card{

private:
    string cardName;

public:
    virtual string displayInfo();
    Card(const string &name);
    string& getName();

};

#endif //POKEMON_CARD_H



