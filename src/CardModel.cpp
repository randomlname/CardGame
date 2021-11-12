/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <iostream>
#include <string>
#include "../include/CardModel.h"
/**
*@brief Sets the number and suit of the Card
*/
Card::Card(const std::string T, const std::string S) {
    this -> Type = T;
    this -> Suit = S;
}
/**
*@brief prints the Card
*/
void Card::printCard() {
    std::cout << Type << " of " << Suit << "." << std::endl;
}
/**
*@brief gets the number of the Card
*/
const std::string Card::getType() {
    return Type;
}
/**
*@brief gets the suit of the Card
*/
const std::string Card::getSuit() {
    return Suit;
}
