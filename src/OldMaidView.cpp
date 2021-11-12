/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <iostream>
#include <vector>
#include <string>
#include "../include/OldMaidView.h"
#include "../include/OldMaidModel.h"

/**
*@brief  menu for ould Maid
*/
int OldMaidView::Menu() {
    int ans;
    std::cout << "|Old Maid|" << std::endl;
    std::cout << "|1) Play |" << std::endl;
    std::cout << "|2) Quit |" <<std::endl;
    std::cin >> ans;
    return ans;
}

/**
*@brief function to enter number of players
*/
int OldMaidView::numOfPlayers() {
    int ans;
    std::cout << "|How many people are playing (2-4)|: ";
    std::cin >> ans;
    return ans;
}

/**
*@brief fucntion to Enter name of player
*/
std::string OldMaidView::nameOfPlayer() {
    std::string name;
    std::cout << "|Enter player name|" << std::endl;
    std::cin >> name;
    return name;
}

/**
*@brief fuction to show whos turn it is
*/
void OldMaidView::playTurn(Playerhand* P) {
    std::cout << "|Its "<< P -> getName() << "'s turn|" << std::endl;
}

/**
*@brief fuction to see the player hand
*/
void OldMaidView::viewPlayerHand(Playerhand* P) {
    std::cout << P -> getName() << "'s Cards" << std::endl;
    for (Card C : P -> getHand()) {
        std::cout << "|" << std::endl;
    }
}

/**
*@brief
*/
int OldMaidView::askForCard() {
    int pos;
    std::cout << "|Which card would you like to take|: ";
    std::cin >> pos;
    return pos;
}

/**
*@brief function to check if player has a pair
*/
void OldMaidView::playerPairs(Playerhand* P,
                              std::vector<std::vector<Card>> pairs) {
    std::cout << "\n----------------\n"
    << P -> getName() << " has got a pair(s) of: \n";
    for (std::vector<Card> Pair : pairs) {
        std::cout << "pair of " << Pair[0].getType() << "'s \n";
    }
}

/**
*@brief function to check if a players hand is empty
*/
void OldMaidView::playerHandEmpty(Playerhand* P) {
    if (P == nullptr) {
        return;
    }
    std::cout << "\n" << P -> getName()
    << " has emptied their hand" << std::endl;
}

/**
*@brief function to print out the winners and losser
*/
void OldMaidView::result(std::vector<Playerhand*> winners, Playerhand* loser) {
    if (loser == nullptr) {
        return;
    }
    std::cout << "\n|The game is over showing results|" << std::endl;
    std::cout << "|" << loser -> getName() << " has the old maid|" << std::endl;
    std::cout << "|The winners are|" << std::endl;
    for (unsigned int i = 0; i < winners.size(); i++) {
        std::cout << i + 1 << ". " << winners[i] -> getName() << std::endl;
    }
}

/**
*@brief function to access and opponent players hand
*/
void OldMaidView::opponentPlayerHand(Playerhand* P) {
    std::cout << P -> getName() << "'s hand has "
    << P -> getHand().size() << " cards" << std::endl;
    for (Card C : P -> getHand()) {
    }
}
