/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef OLDMAIDVIEW_H_INCLUDED
#define OLDMAIDVIEW_H_INCLUDED
#include <vector>
#include <string>
#include "OldMaidModel.h"


class OldMaidView {
    friend class Deck;
 public:
   /**
   *@brief oldmaidview constructor
   *@param nothing
   *@return nothing
   */
    OldMaidView() {}

    /**
    *@brief oldmaidview deconstructor
    *@param nothing
    *@return nothing
    */
    ~OldMaidView() {}

    /**
    *@brief Menu view
    *@param nothing
    *@return int
    */
    int Menu();

    /**
    *@brief tracks the number of players playing
    *@param nothing
    *@return int
    */
    int numOfPlayers();

    /**
    *@brief tracks the name of player
    *@param nothing
    *@return string
    */
    std::string nameOfPlayer();

    /**
    *@brief enables player to play turn
    *@param Playerhand
    *@return nothing
    */
    void playTurn(Playerhand* player);

    /**
    *@brief function for player to see their hand
    *@param Playerhand
    *@return nothing
    */
    void viewPlayerHand(Playerhand* player);

    /**
    *@brief function to acssec the last opponents hand
    *@param Playerhand
    *@return nothing
    */
    void opponentPlayerHand(Playerhand* player);

    /**
    *@brief function to help the player ask for a Card
    *@param nothing
    *@return int
    */
    int askForCard();

    /**
    *@brief function that checks for pair
    *@param Playerhand
    *@param vector<Cards>
    *@return nothing
    */
    void playerPairs(Playerhand* player, std::vector<std::vector<Card>> pairr);

    /**
    *@brief
    *@param nothing
    *@return nothing
    */
    void playerHandEmpty(Playerhand* player);

    /**
    *@brief checks and prints the result
    *@param vector<Playerhand*>
    *@param Playerhand*
    *@return nothing
    */
    void result(std::vector<Playerhand*> winners, Playerhand* loser);
};

#endif // OLDMAIDVIEW_H_INCLUDED
