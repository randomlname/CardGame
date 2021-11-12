/*
 Cpsc 3720 fall 2019
 Nwabunor Onwuanyi
*/
#include <iostream>
#include "../include/DeckModel.h"
#include "../include/OldMaidController.h"
#include "../include/OldMaidModel.h"
#include "../include/OldMaidView.h"

int main() {
    OldMaid model;
    OldMaidView view;
    OldMaidControl controller(model, view);
    controller.gameLoop();
    return 0;
}
