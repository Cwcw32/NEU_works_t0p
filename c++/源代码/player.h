#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
class player
{
public:
    player(int color=0,std::string name="player");
private:
    int color;
    std::string name;
    friend class gamescene1;

};

#endif // PLAYER_H
