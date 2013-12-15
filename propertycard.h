#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class PropertyCard {
public:
	PropertyCard(int, int, int, int, const char*, int, int);
	~PropertyCard();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual sf::IntRect getRect();
	virtual int getCost() = 0;
protected:
	int x, y, rent, cost, available;
	sf::RectangleShape card;
	sf::IntRect clickZone;
	sf::Texture image;
	sf::Sprite card_image;
	const char* name;
};