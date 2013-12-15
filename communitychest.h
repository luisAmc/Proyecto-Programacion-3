#pragma once
#include "SFML/Graphics.hpp"
#include "propertycard.h"
#include <vector>
using namespace std;

class CommunityChest : public PropertyCard {
public:
	CommunityChest(int, int, int, int, const char*, int, int, vector<int>);
	virtual const char* getName();
	virtual int getRent();
	virtual void setAvailable(int);
	virtual int getAvailable();
	virtual void setImage(sf::Texture);
	virtual sf::Sprite getSprite();
	virtual sf::IntRect getRect();
	virtual int getCost();

	void setId(int);
	int getId();
private:
	int id;
};