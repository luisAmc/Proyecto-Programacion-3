#pragma once
#include "propertycard.h"
#include <string>

class RR : public PropertyCard {
public:
	RR(int, int, int, const char*, int, int);
	~RR();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();

	virtual sf::IntRect getRect();
private:
	int railroads;
};