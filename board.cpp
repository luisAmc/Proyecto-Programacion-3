#include "board.h"
#include "propertycard.h"
#include "normalproperty.h"
#include "utilities.h"
#include "rr.h"
#include "specialbox.h"
#include "communitychest.h"
#include "chance.h"
#include <vector>
#include <iostream>
using namespace std;

Board::Board(){
	initComponents();
}
Board::~Board(){

}
int Board::compare(sf::RenderWindow& window, sf::RenderWindow& info_window, int& auxiliar){
	int retVal = 1;
    if (places[0]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 0;
        //} 
    } else if (places[1]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 1;
        //} 
    } else if (places[2]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 2;
        //} 
    } else if (places[3]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 3;
        //} 
    } else if (places[4]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 4;
        //} 
    } else if (places[5]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 5;
        //} 
    } else if (places[6]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 6;
        //} 
    } else if (places[7]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 7;
        //} 
    } else if (places[8]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 8;
        //} 
    } else if (places[9]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 9;
        //} 
    } else if (places[10]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 10;
        //} 
    } else if (places[11]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 11;
        //} 
    } else if (places[12]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 12;
        //} 
    } else if (places[13]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 13;
        //} 
    } else if (places[14]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 14;
        //} 
    } else if (places[15]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 15;
        //} 
    } else if (places[16]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 16;
        //} 
    } else if (places[17]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 17;
        //} 
    } else if (places[18]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 18;
        //} 
    } else if (places[19]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 19;
        //} 
    } else if (places[20]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 20;
        //} 
    } else if (places[21]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 21;
        //} 
    } else if (places[22]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 22;
        //} 
    } else if (places[23]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 23;
        //} 
    } else if (places[24]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 24;
        //} 
    } else if (places[25]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 25;
        //} 
    } else if (places[26]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 26;
        //} 
    } else if (places[27]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 27;
        //} 
    } else if (places[28]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 28;
        //} 
    } else if (places[29]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 29;
        //} 
    } else if (places[30]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 30;
        //} 
    } else if (places[31]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 31;
        //} 
    } else if (places[32]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 32;
        //} 
    } else if (places[33]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 33;
        //} 
    } else if (places[34]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 34;
        //} 
    } else if (places[35]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 35;
        //} 
    } else if (places[36]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 36;
        //} 
    } else if (places[37]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 37;
        //} 
    } else if (places[38]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 38;
        //} 
    } else if (places[39]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 39;
        //} 
    } else {
            auxiliar = 0;
            retVal = -1;
    }
    return retVal;
}
vector<PropertyCard*> Board::getPlaces(){
	return places;
}
vector<sf::Sprite> Board::getSprites(){
    return sprites;
}
void Board::initComponents(){
	//Cafes
    places.push_back(new SpecialBox(527, 527, 0, "Go", 78, 78));

	places.push_back(new NormalProperty(478, 527, 2, "Mediterranean Avenue", 50, 80));
    sf::Texture t1;
	t1.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
	places[1]->setImage(t1);
    sprites.push_back(places[1]->getSprite());

    places.push_back(new CommunityChest(430, 527, 0, "Community Chest", 50, 80));

	places.push_back(new NormalProperty(380, 527, 4, "Baltic Avenue", 50, 80));
    sf::Texture t3;
	t3.loadFromFile("./resources/propiedades/moradas/Baltic_ave.png");
	places[3]->setImage(t3);
    sprites.push_back(places[3]->getSprite());

    places.push_back(new SpecialBox(331, 527, 200, "Income Tax", 50, 80));
    places.push_back(new RR(281, 527, 200, "Reading Railroad", 50, 80));

	//Celestes
	places.push_back(new NormalProperty(232, 527, 6, "Oriental Avenue", 50, 80));
    sf::Texture t6;
    t6.loadFromFile("./resources/propiedades/celestes/Oriental_Ave.png");
    places[6]->setImage(t6);
    sprites.push_back(places[6]->getSprite());

    places.push_back(new Chance(183, 527, 0, "Chance", 50, 80));

	places.push_back(new NormalProperty(134, 527, 6, "Vermont Avenue", 50, 80));
    sf::Texture t8;
    t8.loadFromFile("./resources/propiedades/celestes/Vermont_ave.png");
    places[8]->setImage(t8);
    sprites.push_back(places[8]->getSprite());

	places.push_back(new NormalProperty(85, 527, 8, "Connecticut Avenue", 50, 80));
    sf::Texture t9;
    t9.loadFromFile("./resources/propiedades/celestes/Connecticut_ave.png");
    places[9]->setImage(t9);
    sprites.push_back(places[9]->getSprite());

    places.push_back(new SpecialBox(6, 527, 0, "Jail", 78, 78));

	//Rosadas
	places.push_back(new NormalProperty(6, 478, 10, "St. Charles Place", 80, 50));
    sf::Texture t11;
    t11.loadFromFile("./resources/propiedades/rosadas/Charles_Place.png");
    places[11]->setImage(t11);
    sprites.push_back(places[11]->getSprite());

    places.push_back(new Utilities(6, 430, 0, "Electric Company", 80, 50));

	places.push_back(new NormalProperty(6, 381, 10, "States Avenue", 80, 50));
    sf::Texture t13;
    t13.loadFromFile("./resources/propiedades/rosadas/States_ave.png");
    places[13]->setImage(t13);
    sprites.push_back(places[13]->getSprite());

	places.push_back(new NormalProperty(6, 330, 12, "Virginia Avenue", 80, 50));
    sf::Texture t14;
    t14.loadFromFile("./resources/propiedades/rosadas/Virginia_ave.png");
    places[14]->setImage(t14);
    sprites.push_back(places[14]->getSprite());

    places.push_back(new RR(6, 280, 200, "Pennsylvania Railroad", 80, 50));

	//Anaranjadas
	places.push_back(new NormalProperty(6, 232, 14, "St James Place", 80, 50));
    sf::Texture t16;
    t16.loadFromFile("./resources/propiedades/naranjas/James_Place.png");
    places[16]->setImage(t16);
    sprites.push_back(places[16]->getSprite());

    places.push_back(new CommunityChest(6, 184, 0, "Community Chest", 80, 50));

	places.push_back(new NormalProperty(6, 134, 14, "Tennessee Avenue", 80, 50));
    sf::Texture t18;
    t18.loadFromFile("./resources/propiedades/naranjas/Tennessee_Ave.png");
    places[18]->setImage(t18);
    sprites.push_back(places[18]->getSprite());

	places.push_back(new NormalProperty(6, 85, 16, "New York Avenue", 80, 50));
    sf::Texture t19;
    t19.loadFromFile("./resources/propiedades/naranjas/NewYork_ave.png");
    places[19]->setImage(t19);
    sprites.push_back(places[19]->getSprite());

    places.push_back(new SpecialBox(6, 6, 0, "Free Parking", 78, 78));

	//Rojo
	places.push_back(new NormalProperty(85, 6, 18, "Kentucky Avenue", 50, 80));
    sf::Texture t21;
    t21.loadFromFile("./resources/propiedades/rojas/Kentucky_ave.png");
    places[21]->setImage(t21);
    sprites.push_back(places[21]->getSprite());

    places.push_back(new Chance(134, 6, 0, "Chance", 50, 80));

	places.push_back(new NormalProperty(183, 6, 18, "Indiana Avenue", 50, 80));
    sf::Texture t23;
    t23.loadFromFile("./resources/propiedades/rojas/Indiana_ave.png");
    places[23]->setImage(t23);
    sprites.push_back(places[23]->getSprite());

	places.push_back(new NormalProperty(232, 6, 20, "Illinois Avenue", 50, 80));
    sf::Texture t24;
    t24.loadFromFile("./resources/propiedades/rojas/Illinois_ave.png");
    places[24]->setImage(t24);
    sprites.push_back(places[24]->getSprite());

    places.push_back(new RR(282, 6, 200, "B & O Railroad", 50, 80));

	//Amarillo
	places.push_back(new NormalProperty(330, 6, 22, "Atlantic Avenue", 50, 80));
    sf::Texture t26;
    t26.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    places[26]->setImage(t26);
    sprites.push_back(places[26]->getSprite());

	places.push_back(new NormalProperty(380, 6, 22, "Ventnor Avenue", 50, 80));
    sf::Texture t27;
    t27.loadFromFile("./resources/propiedades/amarillas/Ventnor_ave.png");
    places[27]->setImage(t27);
    sprites.push_back(places[27]->getSprite());

    places.push_back(new Utilities(430, 6, 0, "Water Works", 50, 80));

	places.push_back(new NormalProperty(478, 6, 24, "Marvin Gardens", 50, 80));
    sf::Texture t29;
    t29.loadFromFile("./resources/propiedades/amarillas/Marvin_Gardens.png");
    places[29]->setImage(t29);
    sprites.push_back(places[29]->getSprite());

    places.push_back(new SpecialBox(527, 6, 0, "Go to Jail", 78, 78));

	//Verde
	places.push_back(new NormalProperty(527, 85, 26, "Pacific Avenue", 80, 50));
    sf::Texture t31;
    t31.loadFromFile("./resources/propiedades/verdes/Pacific_Ave.png");
    places[31]->setImage(t31);
    sprites.push_back(places[31]->getSprite());

	places.push_back(new NormalProperty(527, 134, 26, "North Carolina Avenue", 80, 50));
    sf::Texture t32;
    t32.loadFromFile("./resources/propiedades/verdes/Carolina_Ave.png");
    places[32]->setImage(t32);
    sprites.push_back(places[32]->getSprite());

    places.push_back(new CommunityChest(527, 184, 0, "Community Chest", 80, 50));

	places.push_back(new NormalProperty(527, 232, 28, "Pennsylvania Avenue", 80, 50));
    sf::Texture t34;
    t34.loadFromFile("./resources/propiedades/verdes/Pennsylvania_Ave.png");
    places[34]->setImage(t34);
    sprites.push_back(places[34]->getSprite());

    places.push_back(new RR(527, 282, 200, "Short Line Railroad", 80, 50));
    places.push_back(new Chance(527, 332, 0, "Chance", 80, 50));

	//Azul
	places.push_back(new NormalProperty(527, 380, 35, "Park Place", 80, 50));
    sf::Texture t37;
    t37.loadFromFile("./resources/propiedades/azules/Park.png");
    places[37]->setImage(t37);
    sprites.push_back(places[37]->getSprite());

    places.push_back(new SpecialBox(527, 430, 100, "Luxury Tax", 80, 50));

	places.push_back(new NormalProperty(527, 478, 50, "Boardwalk", 80, 50));
    sf::Texture t39;
    t39.loadFromFile("./resources/propiedades/azules/Boardwalk.png");
    places[39]->setImage(t39);
    sprites.push_back(places[39]->getSprite());

}