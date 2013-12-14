#pragma once
#include "SFML/Graphics.hpp"
#include "propertycard.h"
#include <vector>

using std::vector;

class Board {
public:
	Board();
	~Board();
	void initComponents();
	int compare(sf::RenderWindow&, sf::RenderWindow&, int&);
	vector<PropertyCard*> getPlaces();
	vector<sf::Sprite> getSprites();
private:
	vector<PropertyCard*> places;
	vector<sf::Sprite> sprites;
};