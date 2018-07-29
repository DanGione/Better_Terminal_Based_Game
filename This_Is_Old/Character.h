#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"

enum Direction{
    NORTH, EAST, SOUTH, WEST
};

class Character
{
private:
    int InvSize = 10;
    vector<Item*> Inventory;

    int xPos;
    int yPos;
    int prevX;
    int prevY;

    int HP;
    string name;

public:
    Character(int x, int y, string Name, int health);
    int getX() const;
    int getY() const;
    bool acquire(Item* item);
    void print() const;
    bool move(char in);
    int command(char input);
    void movex();
    void moveY();
    void moveBack();
};

#endif // CHARACTER_H
