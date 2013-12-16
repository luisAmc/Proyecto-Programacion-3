#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "propertycard.h"
#include <vector>
using namespace std;

class Player
{
    public:
        Player(string, int);
        string getName();
        void setName(const char*);
        void setMoney(int);
        int getMoney();
        void setInJail(bool);
        bool isInJail();
        void setTurnJail(int);
        int getTurnJail();
        void setPosition(int[]);
        int getX();
        int getY();
        void setId(int);
        int getId();
        void addBox();
        int getBox();
        void setCard(PropertyCard*);
        void draw(int);

    private:
        string name;
        int money;
        bool inJail;
        int turnJail;
        int position[2];
        int id, box;
        vector<PropertyCard*> cards;
};

#endif // PLAYER_H
