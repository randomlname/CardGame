/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef DECKMODEL_H_INCLUDED
#define DECKMODEL_H_INCLUDED
#include "CardModel.h"
#include <vector>
#include <string>

class Deck {
 public:
     /**
     *@brief Deck Constructor
     */
     Deck();

      /**
     *@brief Deck Destructor
     */
     ~Deck();

     const std::string Types[13] = { "Ace", "Two", "Three", "Four", "Five",
     "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

     const std::string Suits[4] = { "Diamonds", "Hearts", "Spades", "Clubs" };

     /**
     *@brief function to shuffle Deck
     *@param nothing
     *@return nothing
     */
     void shuffleDeck();

     /**
     *@brief function to make Deck
     *@param nothing
     *@return nothing
     */
     void MakeDeck();

     /**
     *@brief function to get the cards in a Deck
     *@param nothing
     *@return vector of cards
     */
     std::vector<Card> getCards();

     /**
     *@brief function to delete 1 Queen
     *@param nothing
     *@return nothing
     */
     void deleteQueen();

     /**
     *@brief function to get the top card
     *@param nothing
     *@return  a card object
     */
     Card topCard();

 private:
         std::vector<Card> cardDeck;
};

#endif // DECKMODEL_H_INCLUDED
