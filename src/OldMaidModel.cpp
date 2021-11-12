/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <vector>
#include <string>
#include "../include/OldMaidModel.h"
#include "../include/DeckModel.h"

/**
*@brief constructor that makes a new Deck
*/
OldMaid::OldMaid() {
         deck = new Deck();
}

/**
*@brief function to add a player to the game
*/
void OldMaid::addPlayer(std::string namee) {
    players.push_back(new Playerhand(namee));
}

/**
*@brief function to get player size
*/
int OldMaid::getPlayerSize() {
    return players.size();
}

/**
*@brief  function to get a vector of winning players
*/
std::vector<Playerhand*> OldMaid::getWinners() {
    return winners;
}

/**
*@brief function to get a vector of players
*/
std::vector<Playerhand*> OldMaid::getPlayers() {
    return players;
}

/**
*@brief function to get the deck
*/
Deck* OldMaid::getDeck() {
    return deck;
}

/**
*@brief function to deal the cards
*/
void OldMaid::dealCard() {
    int numofplayers = 0;
    for (int i = getDeck() -> getCards().size(); i > 0; i++) {
        if (getDeck() -> getCards().size() == 0) {
            return;
        }
        Card Add = getDeck() -> topCard();
        (players)[numofplayers++] -> addCard(Add);

        if (numofplayers % players.size() == 0 && numofplayers != 0) {
            numofplayers = 0;
        }
    }
}

/**
*@brief function to move a card to a players hand
*/
void OldMaid::moveCard(Playerhand* P, Card C) {
    P -> addToHand(C);
}

/**
*@brief function to remove a card from a player hand
*/
Card OldMaid::removeCard(Playerhand* P, int pos) {
    Card cardRemoved = P -> getHand()[pos - 1];
    P -> removeCardAt(pos - 1);
    return cardRemoved;
}

std::vector<std::vector<Card>> OldMaid::checkForPair(Playerhand* P) {
    std::vector<std::vector<Card>> pairr;
    for (unsigned int i = 0; i < P -> getHand().size() - 1; i++) {
        for (unsigned int j = 0; j < P -> getHand().size(); j ++) {
            if (P -> getHand()[i].getType() == P -> getHand()[j].getType()) {
                pairr.push_back(std::vector<Card>
                                {P -> getHand()[i], P ->getHand()[j]});
                P -> removeCardAt(j);
                P -> removeCardAt(i);
                if (P -> getHand().size() == 0) {
                    return pairr;
                }
                break;
            }
        }
    }
    return pairr;
}

/**
*@brief function to check for a winner in the game
*/
Playerhand* OldMaid::checkWinner() {
    for (unsigned int i = 0; i < getPlayers().size(); i++) {
        if (getPlayers()[i] -> getHand().size() == 0) {
            winners.push_back(new Playerhand(getPlayers()[i] -> getName()));
            players.erase(players.begin() + 1);
            return getWinners()[getWinners().size() - 1];
        }
    }
    return nullptr;
}

bool OldMaid::endGame() {
    if (getPlayers().size() == 1) {
        return true;
    }
    return false;
}
