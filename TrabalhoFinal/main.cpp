/**
 * Trabalho Final - POO (TE353) - Equipe 3 - Snake
 * Author: Diego R. Garzaro
 * GRR20172364
 * */

#include "./Include/UserInterface.h"

int main(){
    UserInterface ui1;
    int option = 0;
    // Loop
    do{
        option = ui1.call_menu();
        ui1.handle_menu(option);
        ui1.play_game();
        ui1.classify();
    } while(option > 0);


    return 0;
}
