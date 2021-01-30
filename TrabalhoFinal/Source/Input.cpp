#include "../Include/Input.h"

Input::Input(){
    this->rhnd = GetStdHandle(STD_INPUT_HANDLE);
    this->Events = 0;
    this->EventsRead = 0;
    this->pressed_key = KEY_NONE;
}

keys Input::Listen()
{
    // gets the systems current "event" count
    GetNumberOfConsoleInputEvents(this->rhnd, &this->Events);
    //this->pressed_key = KEY_NONE;

    if (this->Events != 0)
    {   // if something happened we will handle the events we want

        // create event buffer the size of how many Events
        INPUT_RECORD eventBuffer[Events];

        // fills the event buffer with the events and saves count in EventsRead
        ReadConsoleInput(this->rhnd, eventBuffer, this->Events, &this->EventsRead);

        // loop through the event buffer using the saved count
        for (DWORD i = 0; i < this->EventsRead; ++i)
        {

            // check if event[i] is a key event && if so is a press not a release
            if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown)
            {
                //std::cout << "\t\t\t" << eventBuffer[i].Event.KeyEvent.wVirtualKeyCode;
                // check if the key press was an arrow key
                switch (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode)
                {
                case VK_LEFT:
                    //std::cout << "arrow Left key pressed.\n";
                    this->pressed_key = KEY_LEFT;
                    break;
                case VK_RIGHT:
                    //std::cout << "arrow Right key pressed.\n";
                    this->pressed_key = KEY_RIGHT;
                    break;
                case VK_UP:
                    //std::cout << "arrow Up key pressed.\n";
                    this->pressed_key = KEY_UP;
                    break;
                case VK_DOWN: // if any arrow key was pressed break here
                    //std::cout << "arrow Down key pressed.\n";
                    this->pressed_key = KEY_DOWN;
                    break;
                case VK_ESCAPE: // if escape key was pressed end program loop
                    //std::cout << "escape key pressed.\n";
                    this->pressed_key = KEY_ESC;
                    //exit(1);
                    break;

                default: // no handled cases where pressed
                    //std::cout << "key not handled pressed.\n";
                    this->pressed_key = KEY_NONE;
                    break;
                }
            }

        } // end EventsRead loop
    }
    return this->pressed_key;
}

Input::~Input(){}