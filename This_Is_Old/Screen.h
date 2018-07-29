#ifndef SCREEN_H
#define SCREEN_H

#include "Character.h"
#include "Map.h"

#include <ncurses.h>

class Screen : public Map
{
private:
    Character* player;
    int screenVar;

public:
    Screen();
    Screen(string newMap);
    Screen(Character* newPlayer);
    void setScreen(int newVar);
    int getHeight() { return height; };
    void addExit(string exitName, int x, int y);
    void update();
    bool withinBounds();
    void addItem(Item* newItem, int itemX, int itemY);
    void printMap();
    void print();
    string* ssPrint();
};

#endif // SCREEN_H
