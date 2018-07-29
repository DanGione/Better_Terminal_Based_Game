#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
#include <stdio.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>

using namespace std;

class InputManager
{
private:
    bool initialized;
    const int STDIN = 0;
    struct termios t;

public:
    InputManager();
    int kbhit();
};

#endif // INPUTMANAGER_H
