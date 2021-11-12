/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#ifndef OLDMAIDCONTROLLER_H_INCLUDED
#define OLDMAIDCONTROLLER_H_INCLUDED

#include <vector>
#include <algorithm>
#include "OldMaidView.h"
#include "OldMaidModel.h"

class OldMaidControl {
 public:
   /**
   *@brief OldMaidControl constructor
   *@param const OldMaid
   *@param const OldMaidView
   *@return nothing
   */
    OldMaidControl(const OldMaid model, const OldMaidView view) {
        this -> setModel(model);
        this -> setView(view);
    }

    /**
    *@brief OldMaidControl deconstructor
    *@param nothing
    *@return nothing
    */
    ~OldMaidControl() {}

    /**
    *@brief sets the model
    *@param const OldMaid
    *@return nothing
    */
    void setModel(const OldMaid model) {
        this -> model = model;
        this -> model.getDeck() -> MakeDeck();
    }

    /**
    *@brief set the view
    *@param const OldMaidView
    *@return nothing
    */
    void setView(const OldMaidView view) {
        this -> view = view;
    }

    /**
    *@brief gets the view
    *@param nothing
    *@return OldMaidView
    */
    OldMaidView getView() {
        return view;
    }

    /**
    *@brief a loop for the game to play until a winner is found
    *@param nothing
    *@return nothing
    */
    void gameLoop();

    /**
    *@brief menu for the game
    *@param nothing
    *@return nothing
    */
    void menu();

    /**
    *@brief function to set the game up
    *@param nothing
    *@return nothing
    */
    void initializeGame();

    /**
    *@brief function to shuffle And Deal
    *@param nothing
    *@return nothing
    */
    void shuffleAndDeal();

    /**
    *@brief function to tell which player thrn it is
    *@param int
    *@return nothing
    */
    void playerTurn(int player);

 private:
    OldMaid model;
    OldMaidView view;
};


#endif // OLDMAIDCONTROLLER_H_INCLUDED
