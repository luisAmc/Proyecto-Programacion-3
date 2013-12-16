#pragma once
#include "propertycard.h"
#include <vector>
using namespace std;

class SpecialBox : public PropertyCard{
public:
	SpecialBox(int, int, int, int, const char*, int, int, int, vector<int>);
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual sf::IntRect getRect();
	virtual int getCost();
	int getId();
private:
	int id;
};