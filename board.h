#pragma once
#include "SFML/Graphics.hpp"
#include "propertycard.h"
#include "communitychest.h"
#include "chance.h"
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
	vector<CommunityChest*> getCommunityChestCards();
	vector<Chance*> getChanceCards();
private:
	vector<PropertyCard*> places;
	vector<sf::Sprite> sprites;
	vector<CommunityChest*> communitychest_cards;
	vector<Chance*> chance_cards;
};