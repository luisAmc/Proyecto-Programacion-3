#include "specialbox.h"
using namespace std;

SpecialBox::SpecialBox(int x, int y, int rent, int cost, const char* name, int px, int py, int ID, vector<int> prices) : 
	PropertyCard(x, y, rent, cost, name, px, py, prices){
	id = ID;
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
int SpecialBox::getCost(){
	return cost;
}
int SpecialBox::getId(){
	return id;
}