#include "Character.h"

Character::Character(int x, int y, string Name, int health){
    xPos = x;
    yPos = y;
    prevX = xPos;
    prevY = yPos;
    name = Name;
    HP = health;
}
int Character::getX() const{
    return xPos;
}
int Character::getY() const{
    return yPos;
}
bool Character::acquire(Item* item){
    if(Inventory.size() < 10){

        Inventory.insert(Inventory.end(),item);
        return true;
    }
    else
        return false;

}
void Character::print() const{
    system("clear");

    cout << name << endl
         << "Health: " << HP
         << " Inventory: "<< endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < Inventory.size(); i++) {
        if(Inventory.at(i) != nullptr) {
            cout << "[" << i << "] " << Inventory.at(i)->toString() << endl;
        }
    }
    cout << "-----------------------------------" << endl;

}

bool Character::move(char in){

    prevX = xPos;
    prevY = yPos;

    if(in == 'w'){
        yPos--;
        return true;
    }
    else if(in == 's'){
        yPos++;
        return true;
    }
    else if(in == 'a'){
        xPos--;
        return true;
    }
    else if(in == 'd'){
        xPos++;
        return true;
    }
    else{
        return false;
    }

}

int Character::command(char input){
    bool isWalk = move(input);
    if (isWalk){
        return 0;
    }
    else if(input == 'e'){
        return 1;
    }
}

void Character::moveBack(){
        xPos = prevX;
        yPos = prevY;
}
