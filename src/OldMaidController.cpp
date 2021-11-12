#include <vector>
#include <string>
#include "../include/OldMaidController.h"

/**
*@brief A loop to help keep the game going
*/
void OldMaidControl::gameLoop() {
    menu();
}

/**
*@brief The menu for go fish
*/
void OldMaidControl::menu() {
    int ans = 0;
    int playerNum = 0;

    while (ans < 1 || ans > 3) {
        ans = view.Menu();
    }
    switch (ans) {
    case 1:
        initializeGame();
        do {
            view.playerHandEmpty(model.checkWinner());
            if (model.endGame()) {
                view.result(model.getWinners(), model.getPlayers()[0]);
                return;
            }

            playerTurn(playerNum);
            view.playerHandEmpty(model.checkWinner());

            if (playerNum != 0 && playerNum %
                (model.getPlayers().size() - 1) == 0) {
                playerNum = 0;
            } else {
                playerNum++;
            }
        }while (model.endGame() == false);
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

/**
*@brief makes the game
*/
void OldMaidControl::initializeGame() {
    int numOfPlayers;
    std::string playerName;

    numOfPlayers = view.numOfPlayers();

    for (int i = 0; i < numOfPlayers; i++) {
        model.addPlayer(view.nameOfPlayer());
    }

    shuffleAndDeal();

    for (Playerhand* player : model.getPlayers()) {
        std::vector<std::vector<Card>> Pair = model.checkForPair(player);
        view.playerPairs(player, Pair);
    }
}

/**
*@brief shuffles And Deals the cards
*/
void OldMaidControl::shuffleAndDeal() {
    model.getDeck() -> deleteQueen();
    model.dealCard();
}

/**
*@brief Function to enable the player to play
*/
void OldMaidControl::playerTurn(int Player) {
    Playerhand* currentPlayer = model.getPlayers()[Player];
    int cardPos;

    view.playTurn(currentPlayer);

    if (Player == 0) {
        Playerhand* previousPlayer =
        model.getPlayers()[model.getPlayers().size() - 1];
        view.opponentPlayerHand(previousPlayer);
        cardPos = view.askForCard();
        Card cardTaken = model.removeCard(previousPlayer, cardPos);
        model.moveCard(currentPlayer, cardTaken);

        std::vector<std::vector<Card>> Pairs =
        model.checkForPair(model.getPlayers()[Player]);
        view.playerPairs(model.getPlayers()[Player], Pairs);
    } else {
        Playerhand* previousPlayer = model.getPlayers()[Player - 1];
        view.opponentPlayerHand(previousPlayer);
        cardPos = view.askForCard();
        Card cardTaken = model.removeCard(previousPlayer, cardPos);
        model.moveCard(currentPlayer, cardTaken);

        std::vector<std::vector<Card>> Pair =
        model.checkForPair(model.getPlayers()[Player]);
        view.playerPairs(model.getPlayers()[Player], Pair);
    }
}
