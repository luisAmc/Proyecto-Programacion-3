#include "SFML/Graphics.hpp"
#include "propertycard.h"
#include <string>
#include <iostream>
using namespace std;

PropertyCard::PropertyCard(int X, int Y, int Rent, int Cost, const char* Name, int px, int py, vector<int> p) : 
	x(X), y(Y), rent(Rent), cost(Cost), name(Name), prices(p){
	card.setPosition(x, y);
	card.setSize(sf::Vector2f(px, py));
	card.setFillColor(sf::Color::Green);
	clickZone = sf::IntRect (card.getPosition().x, card.getPosition().y, card.getSize().x, card.getSize().y);
}

PropertyCard::~PropertyCard() {
	//Dtor PropertyCard
}

const char* PropertyCard::getName() {
	return name;
}

int PropertyCard::getRent() {
	return rent;
}

void PropertyCard::setAvailable(int a){
}
int PropertyCard::getAvailable(){
}
void PropertyCard::setImage(sf::Texture t){
	image = t;
}
sf::Sprite PropertyCard::getSprite(){
	sf::Sprite sprite(image);
	return sprite;
}

sf::IntRect PropertyCard::getRect(){
	return clickZone;
}
