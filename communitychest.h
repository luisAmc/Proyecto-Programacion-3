#pragma once
#include "SFML/Graphics.hpp"
#include "propertycard.h"

class CommunityChest : public PropertyCard {
	CommunityChest(int, int, int, const char*, int, int);
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual sf::IntRect getRect();

	int getId();
private:
	int id;
};