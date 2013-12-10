#pragma once
#include "propertycard.h"
#include <string>

class Utilities : public PropertyCard {
public:
	Utilities(int, int, int, const char*, int, int);
	~Utilities();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	void addCount();

	virtual sf::IntRect getRect();
private:
	int count;
};