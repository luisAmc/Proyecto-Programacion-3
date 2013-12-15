#include "communitychest.h"
#include "SFML/Graphics.hpp"
#include "propertycard.h"
using namespace std;

//int X, int Y, int Rent, const char* Name, int px, int py
CommunityChest::CommunityChest(int x, int y, int rent, int cost, const char* name, int px, int py, vector<int> prices) : 
	PropertyCard(x, y, rent, cost, name, px, py, prices){
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
void CommunityChest::setId(int i){
	id = i;
}
int CommunityChest::getId(){
	return id;
}
int CommunityChest::getCost(){
	return cost;
}