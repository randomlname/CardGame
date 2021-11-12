/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <string>
#include <vector>
#include <iostream>
#include "../include/PlayerHandModel.h"
/**
*@brief default constroctor
*/
Playerhand::Playerhand(std::string name) {
         this -> name = name;
         hand = {};
}
/**
*@brief returns player hand
*/
std::vector<Card> Playerhand::getHand() {
    return hand;
}

/**
*@brief  return player name
*/
std::string Playerhand::getName() {
    return name;
}

/**
*@brief adds a card to players hand
*/
void Playerhand::addCard(Card C) {
    hand.push_back(C);
}

/**
*@brief adds a card to players hand
*/
void Playerhand::addToHand(Card C) {
    hand.push_back(C);
}

/**
*@brief removes a card at a certain position
*/
void Playerhand::removeCardAt(int pos) {
    hand.erase(hand.begin()+ pos);
}
