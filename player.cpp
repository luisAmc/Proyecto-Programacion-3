#include "player.h"
#include "propertycard.h"
#include <cstring>

Player::Player(string n, int ID)
{
    name = n;
    money = 1500;
    inJail = false;
    turnJail = 0;
    position[0] = 0;
    position[1] = 0;
    id = ID;
    box = 0;
}
void Player::setName(const char* n){
    name = n;
}
string Player::getName()
{
    return name;
}

void Player::setMoney(int m)
{
    money = m;
}

int Player::getMoney()
{
    return money;
}

void Player::setInJail(bool j)
{
    inJail = j;
}

bool Player::isInJail()
{
    return inJail;
}

void Player::setTurnJail(int t)
{
    turnJail = t;
}

int Player::getTurnJail()
{
    return turnJail;
}

void Player::setPosition(int p[])
{
    position[0] = p[0];
    position[1] = p[1];
}

int Player::getX()
{
    return position[0];
}

int Player::getY()
{
    return position[1];
}

void Player::setCard(PropertyCard* card)
{
  cards.push_back(card);
}

void Player::setId(int ID){
    id = ID;
}

int Player::getId(){
    return id;
}

void Player::draw(int pj) {
    if (pj == 1) {

    } else if (pj == 2) {

    }
}

int Player::getBox(){
    return box;
}

void Player::addBox(){
    if (box >= 39)
        box = 0;
    else 
        box++;
}