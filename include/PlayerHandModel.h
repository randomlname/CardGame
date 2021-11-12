/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef PLAYERHANDMODEL_H_INCLUDED
#define PLAYERHANDMODEL_H_INCLUDED

/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <vector>
#include <string>
#include "DeckModel.h"
#include "CardModel.h"

class Playerhand:public Deck {
 public:
     /**
     *@brief player hand Constructor
     */
     Playerhand(std::string name);

     /**
     *@brief player hand Destructor
     */
    ~Playerhand() {}

    /**
    *@brief function to get players hand
    *@param nothing
    *@return vector of Cards
    */
     std::vector<Card> getHand();

     /**
     *@brief function to get player name
     *@param nothing
     *@return string
     */
     std::string getName();

     /**
     *@brief function to add a Card
     *@param Card
     *@return nothing
     */
     void addCard(Card C);

     /**
     *@brief function to add a card to hand
     *@param Card
     *@return nothing
     */
     void addToHand(Card C);

     /**
     *@brief a function t remove the card at a postion
     *@param int
     *@return nothing
     */
     void removeCardAt(int Pos);

 private:
    std::string name;
    std::vector<Card> hand;
};

#endif // PLAYERHANDMODEL_H_INCLUDED
