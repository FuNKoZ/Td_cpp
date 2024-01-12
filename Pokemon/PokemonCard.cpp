//
// Created by clement on 15/12/23.
//

#include "PokemonCard.h"

PokemonCard::PokemonCard(const string& name,
                         const string& type,
                         const string& familyName,
                         const int evoLevel,
                         const int maxHp,
                         const int cost1,
                         const string& attack1,
                         const int damage1,
                         const int cost2,
                         const string& attack2,
                         const int damage2):
Card(name),
evolutionLevel(evoLevel),
pokemonType(type),
familyName(familyName),
maxHP(maxHp),
hp(maxHp),
numberOfEnergy(0)
{
    attacks.push_back(make_tuple(cost1, attack1, damage1));
    attacks.push_back(make_tuple(cost2, attack2, damage2));
}

string& PokemonCard::getType(){
    return pokemonType;
}

bool PokemonCard::reduceHp(int number){
    hp = hp-number;
    return hp>0;
}

tuple<int, string, int> PokemonCard::getAttack(int i) {
    return attacks[i];
}

void PokemonCard::fullHeal(){
    hp = maxHP;
}

void PokemonCard::attachEnergy(){
    numberOfEnergy++;
}

void PokemonCard::minusNumberOfEnergy(int number) {
    numberOfEnergy = numberOfEnergy - number;
}


int PokemonCard::getNumberOfEnergy() {
    return numberOfEnergy;
}

string PokemonCard::displayInfo() {
    string stockEnergy = "\n Attack current energy storage: " + to_string(numberOfEnergy);
    return "Pokemon Card - Name:" + getName() + ", Type:" + pokemonType +
    ", Evolution level:" + to_string(evolutionLevel) + " of the family "+ familyName
    + ", Hp:" + to_string(hp) + "\n"
    + "Attacks: \n Attack #0: \n Attack Cost:" + to_string(get<0>(attacks[0]))
    + stockEnergy
    + "\n Attack description :" + get<1>(attacks[0])
    + "\n Attack damage: " + to_string(get<2>(attacks[0]))
    +"\n Attack #1: \n Attack Cost:" + to_string(get<0>(attacks[1]))
    + stockEnergy
    + "\n Attack description :" + get<1>(attacks[1])
    + "\n Attack damage: " + to_string(get<2>(attacks[1])) + "\n";
}




