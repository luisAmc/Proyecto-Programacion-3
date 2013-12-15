#pragma once
#include "propertycard.h"

class SpecialBox : public PropertyCard{
public:
	SpecialBox(int, int, int, int, const char*, int, int);
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual sf::IntRect getRect();
	virtual int getCost();
};