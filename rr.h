#pragma once
#include "propertycard.h"
#include <string>
#include <vector>
using namespace std;

class RR : public PropertyCard {
public:
	RR(int, int, int, int, const char*, int, int, vector<int>);
	~RR();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual int getCost();
	void addRailroads();
	int getRailroads();
	void setOwner(int);
	int getOwner();

	virtual sf::IntRect getRect();
private:
	int railroads, owner;
};