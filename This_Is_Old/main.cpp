#include <iostream>
#include <ncurses.h>
#include "Character.h"
#include "Screen.h"
#include <unistd.h>
#include <termios.h>

using namespace std;

class BufferToggle
{
    private:
        struct termios t;

    public:

        /*
         * Disables buffered input
         */

        void off(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }


        /*
         * Enables buffered input
         */

        void on(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag |= ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }
};

int main()
{
    BufferToggle bt;
    bt.off();
    Item vase("Vase", 10);
    //    Item mace("Mace", 20);

    Character Link(1,0,"Link",20);

    Screen newScreen(&Link);
    newScreen.addItem(&vase,5,5);
    newScreen.print();

    char input;

    while(newScreen.withinBounds()){
        cin >> input;
        Link.command(input);

        newScreen.update();
        newScreen.print();
    }
    return 0;
}
