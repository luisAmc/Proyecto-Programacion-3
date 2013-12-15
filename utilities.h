#pragma once
#include "propertycard.h"
#include <string>
#include <vector>
using namespace std;

class Utilities : public PropertyCard {
public:
	Utilities(int, int, int, int, const char*, int, int, vector<int>);
	~Utilities();
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual int getCost();
	void addCount();
	int getCount();
	void setOwner(int);
	int getOwner();

	virtual sf::IntRect getRect();
private:
	int count, owner;
};