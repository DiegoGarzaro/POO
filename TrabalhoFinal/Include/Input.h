#include <iostream>
#include <Windows.h>

// Enumerate
enum keys
{
    KEY_NONE = 0,
    KEY_UP,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_ESC
};

class Input
{
private:
    HANDLE rhnd;      // handle to read console
    DWORD Events;     // Event count
    DWORD EventsRead; // Events read from console
    keys pressed_key; // Store the pressed key

public:
    Input();
    ~Input();
    keys Listen();
};