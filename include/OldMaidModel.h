/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef OLDMAIDMODEL_H_INCLUDED
#define OLDMAIDMODEL_H_INCLUDED
/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include "DeckModel.h"
#include "PlayerHandModel.h"
#include <vector>
#include <string>


class OldMaid {
    friend class Deck;
 public:
    /**
     *@brief Oldmaid Constructor
     *@param nothing
     *@return nothing
     */
     OldMaid();

     /**
     *@brief Oldmaid Destructor
     *@param nothing
     *@return nothing
     */
     virtual ~OldMaid() {}

     /**
     *@brief a function to add a player
     *@param string
     *@return nothing
     */
     void addPlayer(std::string namee);

     /**
     *@brief function to get the mumber of players
     *@param nothing
     *@return int
     */
     int getPlayerSize();

     /**
     *@brief a function to get the Deck
     *@param nothing
     *@return Deck
     */
     Deck* getDeck();

     /**
     *@brief function to deal the cards
     *@param nothing
     *@return nothing
     */
     void dealCard();

     /**
     *@brief function to check for pairs
     *@param nothing
     *@return returns a vector of vector cards
     */
     std::vector<std::vector<Card>> checkForPair(Playerhand* player);

     /**
     *@brief a fuction to check if we can end the game
     *@param nothing
     *@return bool
     */
     bool endGame();

     /**
     *@brief a function to check for a winner
     *@param nothing
     *@return Playerhand
     */
     Playerhand* checkWinner();

     /**
     *@brief a function to get players
     *@param nothing
     *@return vector of players
     */
     std::vector<Playerhand*> getPlayers();

     /**
     *@brief function to get winners
     *@param nothing
     *@return vector of players
     */
     std::vector<Playerhand*> getWinners();

     /**
     *@brief function to move a Card
     *@param Playerhand
     *@param Card
     *@return nothing
     */
     void moveCard(Playerhand* player, Card C);

     /**
     *@brief function to remove a Card
     *@param Playerhand
     *@param int 
     *@return nothing
     */
     Card removeCard(Playerhand* player, int pos);



 protected:
    Deck* deck;
    std::vector<Playerhand*> players;
    std::vector<Playerhand*> winners;
};



#endif // OLDMAIDMODEL_H_INCLUDED
