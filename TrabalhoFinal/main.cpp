#include "./Include/UserInterface.h"
//#include "./Include/Game.h"

int main(){
    UserInterface ui1;
    int option;
    // Loop
    do{
        option = ui1.call_menu();
        ui1.handle_menu(option);
        ui1.play_game();
        ui1.classificar();
    } while(option > 0);


    return 0;
}
