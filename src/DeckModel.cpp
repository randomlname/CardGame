/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // shuffle
#include <random> // default_random_engine
#include <chrono> // chrono::system clock //NO LINT
#include "../include/CardModel.h"
#include "../include/DeckModel.h"

/**
*@brief Default constructor that sets all values to 0
*/
Deck::Deck() {}

/**
*@brief A de-constructor that deletes the cardDeck vector
*/
Deck::~Deck() {}

/**
*@brief Make the deck of cards for the game
*/
void Deck::MakeDeck() {
    std::string Type;
    std::string Suit;

    for (std::string Typee : Types) {
            for (std::string Suitt : Suits) {
                cardDeck.push_back(Card(Typee, Suitt));
            }
    }
}

/**
*@brief Shuffles the deck of cards
*/
void Deck::shuffleDeck() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
}

/**
*@brief getCards an entire set of cards
*/
std::vector<Card> Deck::getCards() {
    return cardDeck;
}

/**
*@brief removes 1 queen from the deck for old maid
*/
void Deck::deleteQueen() {
    for (int i = 0; i <= 1; i++) {
        if (cardDeck[i].getType() == "Queen") {
            cardDeck.erase((cardDeck.begin()+ i));
            return;
        }
    }
}

/**
*@brief gets the top card on the deck/hand
*/
Card Deck::topCard() {
    Card topcard = cardDeck.at(cardDeck.size() - 1);
    cardDeck.pop_back();
    return topcard;
}
