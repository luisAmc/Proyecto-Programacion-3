#include "communitychest.h"
#include "SFML/Graphics.hpp"
#include "propertycard.h"

//int X, int Y, int Rent, const char* Name, int px, int py
CommunityChest::CommunityChest(int x, int y, int rent, const char* name, int px, int py) : 
	PropertyCard(x, y, rent, name, px, py){
	setAvailable(1);
}
const char* CommunityChest::getName(){
	return name;
}
int CommunityChest::getRent(){
	return rent;
}
void CommunityChest::setAvailable(int a){
	available = a;
}
int CommunityChest::getAvailable(){
	return available;
}
void CommunityChest::setImage(sf::Texture t){
	image = t;
}
sf::Sprite CommunityChest::getSprite(){
	sf::Sprite sprite(image);
	return sprite;
}
sf::IntRect CommunityChest::getRect(){
	return clickZone;
}
int CommunityChest::getId(){
	return id;
}