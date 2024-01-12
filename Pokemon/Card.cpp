//
// Created by clement on 15/12/23.
//

#include "Card.h"

Card::Card(const string& name):
cardName(name){}

string Card::displayInfo(){

}

string& Card::getName(){
    return cardName;
}