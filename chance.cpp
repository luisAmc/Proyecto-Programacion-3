#include "SFML/Graphics.hpp"
#include "chance.h"
#include "propertycard.h"
using namespace std;

Chance::Chance(int x, int y, int rent, int cost, const char* name, int px, int py, vector<int> prices) :
	PropertyCard(x, y, rent, cost, name, px, py, prices){
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
void Chance::setId(int i){
	id = i;
}
int Chance::getId(){
	return id;
}
int Chance::getCost(){
	return cost;
}