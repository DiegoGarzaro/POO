#include "./Include/UserInterface.h"
//#include "./Include/Game.h"

int main(){
    UserInterface ui1;
    int option;
    // Loop
    do{
        option = ui1.call_menu();
        ui1.handle_menu(option);
        option = 1;
        ui1.play_game();
        ui1.classificar();
    } while(option == TRUE);


    return 0;
}
