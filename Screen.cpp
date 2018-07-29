#include "Screen.h"

Screen::Screen() : Map()
{
    player = nullptr;
    screenVar = 0;
}

Screen::Screen(string newMap) : Map(newMap)
{
    player = nullptr;
    screenVar = 0;
}

Screen::Screen(Character* newPlayer) : Map()
{
    player = newPlayer;
    screenVar = 0;
}

bool Screen::withinBounds(){
    if(player->getX() < 0 || player->getY() < 0)
        return false;

    else if(player->getX() >= width || player->getY() >= height)
        return false;

    else
        return true;

}

void Screen::setScreen(int newVar){
    screenVar = newVar;
}

void Screen::addItem(Item* newItem, int itemX, int itemY){
    locations[itemX][itemY].addDrop(newItem);
}

void Screen::addExit(string exitName, int x, int y){
    locations[x][y].addExit(exitName);
}

void Screen::printMap(){

    string* out = new string[height];
    *out = {};

    for(int i = 0; i < Map::height; i++){
        for(int j = 0; j < Map::width; j++){

            if(player != nullptr && i == player->getY() && j == player->getX())
                out[i] += '@';

            else
                out[i] += static_cast<char>(locations[i][j].print());
            out[i] += ' ';
        }
        cout << out[i] << endl;
    }
    cout << endl;
}

void Screen::print(){
    system("clear");

    if(screenVar == 0){
        printMap();
    }
    if(screenVar == 1){
        player->print();
    }
}

string* Screen::ssPrint(){

    system("clear");

    string* out = new string[height];
    *out = {};

    for(int i = 0; i < Map::height; i++){
        for(int j = 0; j < Map::width; j++){

            if(player != nullptr && i == player->getY() && j == player->getX())
                out[i] += '@';

            else
                out[i] += static_cast<char>(locations[j][i].print());
        }
        out[i] += "\n";
    }
    return out;
}

void Screen::update(){


    if(withinBounds()){
    Location newloc = locations.at(player->getY()).at(player->getX());

//    if(newloc.getItem() != nullptr){
//        player->acquire(newloc.getItem());
//        locations[player->getX()][player->getY()].deleteItem();
//    }

    if(newloc.wall())
        player->moveBack();
    }

    else
        player->moveBack();

}
