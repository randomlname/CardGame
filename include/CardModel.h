/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef CARDMODLE_H_INCLUDED
#define CARDMODLE_H_INCLUDED

/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/

#include <string>

class Card {
 public:
   /**
   *@brief Card constructor
   *@param const string
   *@param const string
   */
Card(const std::string Type, const std::string suit);

   /**
   *@brief function to printCard
   *@param nothing
   *@return nothing
   */
void printCard();

   /**
   *@brief function to get the number of a Card
   *@param nothing
   *@return nothing
   */
    const std::string getType();

    /**
    *@brief function to get the suit of the card
    *@param nothing
    *@return nothing
    */
    const std::string getSuit();

 private:
        std::string Type;
        std::string Suit;
};

#endif // CARDMODLE_H_INCLUDED
