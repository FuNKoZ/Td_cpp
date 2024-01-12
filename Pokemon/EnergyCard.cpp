//
// Created by clement on 15/12/23.
//

#include "EnergyCard.h"

EnergyCard::EnergyCard(const string& type):
Card("Energy"), energyType(type){}

string& EnergyCard::getType(){
    return energyType;
}