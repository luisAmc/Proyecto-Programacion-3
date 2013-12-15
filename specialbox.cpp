#include "specialbox.h"

SpecialBox::SpecialBox(int x, int y, int rent, const char* name, int px, int py) : 
	PropertyCard(x, y, rent, name, px, py){
}
const char* SpecialBox::getName(){
	return name;
}
int SpecialBox::getRent(){
	return rent;
}
void SpecialBox::setAvailable(int a){
	available = a;
}
int SpecialBox::getAvailable(){
	return available;
}
void SpecialBox::setImage(sf::Texture t){
	image = t;
}
sf::Sprite SpecialBox::getSprite() {
	sf::Sprite sprite(image);
	return sprite;
}
sf::IntRect SpecialBox::getRect(){
	return clickZone;
}