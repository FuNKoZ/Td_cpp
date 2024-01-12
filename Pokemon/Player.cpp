//
// Created by clement on 22/12/23.
//

#include "Player.h"
#include "EnergyCard.h"

Player::Player(const string& name):
playerName(name){}

vector<PokemonCard*> Player::getActionCards() {
    return actionCards;
}

string& Player::getName(){
    return playerName;
}

void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index){
    cout << playerName << " is activating a Pokemon Card:" << benchCards[index]->getName() <<endl;
    benchCards.erase(benchCards.begin() + index);
    actionCards.push_back((PokemonCard*) benchCards[index]);
}

void Player::attachEnergyCard(int benchIndex, int actionIndex){
    PokemonCard* pokemon = actionCards[actionIndex];
    Card* energy = benchCards[benchIndex];
    benchCards.erase(benchCards.begin() + benchIndex);
    EnergyCard* energyCard = (EnergyCard *) energy;
    if (pokemon->getType() != energyCard->getType()) return;
    pokemon->attachEnergy();
    cout << playerName <<" is attaching Energy Card of type" << energyCard->getType() << "to the Pokemon" << pokemon->getName() <<endl;
}

void Player::killPoke(int index) {
    actionCards.erase(actionCards.begin() + index);
}


void Player::attack(int actionIndex, int attackNumber, Player& opponent, int opponentIndex){
    vector<PokemonCard*> opponentActionCards = opponent.getActionCards();
    PokemonCard* pokemon = actionCards[actionIndex];
    PokemonCard* opponentsPokemon = opponentActionCards[opponentIndex];
    tuple<int, string, int> attack = pokemon->getAttack(attackNumber);
    int energyCost = get<0>(attack);
    int damageNumber = get<2>(attack);
    if (pokemon->getNumberOfEnergy() >= energyCost){
        cout << playerName << " attacking " << opponent.getName() << "'s Pokemon "
             << opponent.getCard(opponentIndex)->getName() << " with the Pokemon "
             << actionCards[actionIndex]->getName()
             << " with its attack: " << get<1>(attack) << endl;
        cout << "Reducing " << to_string(damageNumber) << " from" << opponent.getName() << "'s Pokemon's HP" << endl;
        pokemon->minusNumberOfEnergy(energyCost);
        bool isAlive = opponentsPokemon->reduceHp(damageNumber);
        if (isAlive) cout << "Pokemon" << opponentsPokemon->getName() << "is still alive" << endl;
        else {
            opponent.killPoke(opponentIndex);
            cout << "Pokemon" << opponentsPokemon->getName() << "is dead" << endl;
        }
    }
    else{
        cout << "Not enough energy to attack" << endl;
    }
}

void Player::displayBench(){
    cout << "Bench cards for Player " << playerName << endl;
    for (Card* card:benchCards){
        cout << card->displayInfo() << endl;
    }
}

void Player::displayAction(){
    cout << "Action cards for Player " << playerName << endl;
    for (Card* card:actionCards){
        cout << card->displayInfo() << endl;
    }
}

void Player::useTrainer(int trainerIndex){
    cout << playerName << "is using the Trainer Card to '" << dynamic_cast<TrainerCard*>(benchCards[trainerIndex])->getTrainerEffect() << "'" <<endl;
    for (PokemonCard* pokemonCard : actionCards){
        pokemonCard->fullHeal();
    }
}

PokemonCard* Player::getCard(int i){
    return actionCards[i];
}



