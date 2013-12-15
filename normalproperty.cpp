#include "propertycard.h"
#include "normalproperty.h"
#include <string>
#include <iostream>

NormalProperty::NormalProperty(int x, int y, int rent, int cost, const char* name, int px, int py) : 
	PropertyCard(x, y, rent, cost, name, px, py){
		setAvailable(1);
}

NormalProperty::~NormalProperty(){
	//Dtor NormalProperty
}

const char* NormalProperty::getName(){
	return name;
}

int NormalProperty::getRent(){
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

void NormalProperty::setHouse(int h){
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
