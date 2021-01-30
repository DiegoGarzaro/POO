#include <iostream>
#include <Windows.h>

int main(int argc, char *argv[]){

    HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

    DWORD Events = 0;     // Event count
    DWORD EventsRead = 0; // Events read from console

    bool Running = true;

    //programs main loop
    while(Running) {

        // gets the systems current "event" count
        GetNumberOfConsoleInputEvents(rhnd, &Events);

        if(Events != 0){ // if something happened we will handle the events we want

            // create event buffer the size of how many Events
            INPUT_RECORD eventBuffer[Events];

            // fills the event buffer with the events and saves count in EventsRead
            ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

            // loop through the event buffer using the saved count
            for(DWORD i = 0; i < EventsRead; ++i){

                // check if event[i] is a key event && if so is a press not a release
                if(eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown){

                    // check if the key press was an arrow key
                    switch(eventBuffer[i].Event.KeyEvent.wVirtualKeyCode){
                        case VK_LEFT:
                            std::cout<< "arrow Left key pressed.\n";
                            break;
                        case VK_RIGHT:
                            std::cout<< "arrow Right key pressed.\n";
                            break;
                        case VK_UP:
                            std::cout<< "arrow Up key pressed.\n";
                            break;
                        case VK_DOWN:   // if any arrow key was pressed break here
                            std::cout<< "arrow Down key pressed.\n";
                            break;

                        case VK_ESCAPE: // if escape key was pressed end program loop
                            std::cout<< "escape key pressed.\n";
                            Running = false;
                            break;

                        default:        // no handled cases where pressed 
                            std::cout<< "key not handled pressed.\n";
                            break;
                    }
                }

            } // end EventsRead loop

        }

    } // end program loop

    return 0;
}