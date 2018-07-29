#include "InputManager.h"
#include "Screen.h"
#include <chrono>

using namespace std::chrono;

int main() {
    InputManager Input;

    Character Link(1,0,"Link",20);
    system("setterm -cursor off");

    Screen newScreen(&Link);
    newScreen.print();

    int key = 0;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    while (key != 27) {

        key = Input.kbhit();
        if(key){
            Link.command(key);
        }
        newScreen.update();
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

        if(time_span.count() >= 0.01666){
            newScreen.print();
            t1 = high_resolution_clock::now();
        }
        //        usleep(33333);
    }
    printf("\nDone.\n");
    usleep(16666);
    system("pkill terminal");

    return 0;
}
