#include "propertycard.h"
#include "utilities.h"
#include <string>

Utilities::Utilities(int x, int y, int rent, int cost, const char* name, int px, int py) : 
	PropertyCard(x, y, rent, cost, name, px, py){
		setAvailable(1);	
}
Utilities::~Utilities(){
	//Dtor Utilities
}
const char* Utilities::getName(){
	return name;
}
int Utilities::getRent(){
	return rent;
}
void Utilities::setAvailable(int a){
	available = a;
	addCount();
}
int Utilities::getAvailable(){
	return available;
}
void Utilities::setImage(sf::Texture t){
	image = t;
}
sf::Sprite Utilities::getSprite(){
	sf::Sprite sprite(image);
	return sprite;
}
void Utilities::addCount(){
	count++;
}
int Utilities::getCount(){
	return count;
}
sf::IntRect Utilities::getRect(){
	return clickZone;
}
void Utilities::setOwner(int o){
	owner = o;
}
int Utilities::getOwner(){
	return owner;
}
int Utilities::getCost(){
	return cost;
}