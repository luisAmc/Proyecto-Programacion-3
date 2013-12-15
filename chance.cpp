#include "SFML/Graphics.hpp"
#include "chance.h"
#include "propertycard.h"

Chance::Chance(int x, int y, int rent, int cost, const char* name, int px, int py) :
	PropertyCard(x, y, rent, cost, name, px, py){
	setAvailable(1);
}
const char* Chance::getName(){
	return name;
}
int Chance::getRent(){
	return rent;
}
void Chance::setAvailable(int a){
	available = a;
}
int Chance::getAvailable(){
	return available;
}
void Chance::setImage(sf::Texture t){
	image = t;
}
sf::Sprite Chance::getSprite(){
	sf::Sprite sprite(image);
	return sprite;
}
sf::IntRect Chance::getRect(){
	return clickZone;
}
int Chance::getId(){
	return id;
}
int Chance::getCost(){
	return cost;
}