#include "propertycard.h"
#include "normalproperty.h"
#include <string>
#include <iostream>
using namespace std;

NormalProperty::NormalProperty(int x, int y, int rent, int cost, const char* name, int px, int py, vector<int> prices, int hc) : 
	PropertyCard(x, y, rent, cost, name, px, py, prices){
		setAvailable(1);
		houses = 0;
		house_cost = hc;
}

NormalProperty::~NormalProperty(){
	//Dtor NormalProperty
}

const char* NormalProperty::getName(){
	return name;
}

int NormalProperty::getRent(){
	switch(houses){
		case 1:
			return prices[1];
			break;
		case 2:
			return prices[2];
			break;
		case 3:
			return prices[3];
			break;
		case 4:
			return prices[4];
			break;
		case 5:
			return prices[5];
			break;
	}
	return rent;
}

void NormalProperty::setAvailable(int a){
	available = a;
}

int NormalProperty::getAvailable(){
	return available;
}

void NormalProperty::setImage(sf::Texture t){
	image = t;
}

sf::Sprite NormalProperty::getSprite() {
	sf::Sprite sprite(image);
	return sprite;
}

void NormalProperty::addHouses(){
	houses++;
}

int NormalProperty::getHouse(){
	return houses;
}

sf::IntRect NormalProperty::getRect(){
	return clickZone;
}
void NormalProperty::setOwner(int o){
	owner = o;
}
int NormalProperty::getOwner(){
	return owner;
}
int NormalProperty::getCost(){
	return cost;
}
int NormalProperty::getHouseCost(){
	return house_cost;
}