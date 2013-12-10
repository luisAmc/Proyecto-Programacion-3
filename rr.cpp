#include "propertycard.h"
#include "rr.h"
#include <string>

RR::RR(int x, int y, int rent, const char* name, int px, int py):
	PropertyCard(x, y, rent, name, px, py){
		setAvailable(1);
}
RR::~RR(){
	//Dtor RR
}
const char* RR::getName(){
	return name;
}
int RR::getRent(){
	return rent;
}
void RR::setAvailable(int a){
	available = a;
}
int RR::getAvailable(){
	return available;
}
void RR::setImage(sf::Texture t){
	image = t;
}
sf::Sprite RR::getSprite(){
	sf::Sprite sprite(image);
	return sprite;
}
sf::IntRect RR::getRect(){
	return clickZone;
}