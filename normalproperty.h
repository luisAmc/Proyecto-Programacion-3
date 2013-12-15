#pragma once
#include "propertycard.h"
#include <string>

class NormalProperty : public PropertyCard {
public:
	NormalProperty(int, int, int, int, const char*, int, int);
	~NormalProperty();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual int getCost();
	void setOwner(int);
	int getOwner();
	void setHouse(int);
	int getHouse();

	virtual sf::IntRect getRect();
private:
	int houses, owner;
};