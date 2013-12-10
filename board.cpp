#include "board.h"
#include "propertycard.h"
#include "normalproperty.h"
#include "utilities.h"
#include "rr.h"
#include "specialbox.h"
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
    if (places[0].getRect().contains(sf::Mouse::getPosition(window))) {
        cout << "soy el 0" << endl;
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 0;
        //} 
    } else if (places[1].getRect().contains(sf::Mouse::getPosition(window))) {
    	cout << "soy el 1" << endl;
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 1;
        //} 
    } else if (places[2].getRect().contains(sf::Mouse::getPosition(window))) {
    	cout << "soy el 2" << endl;
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 2;
        //} 
    } else if (places[3].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 3;
        //} 
    } else if (places[4].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 4;
        //} 
    } else if (places[5].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 5;
        //} 
    } else if (places[6].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 6;
        //} 
    } else if (places[7].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 7;
        //} 
    } else if (places[8].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 8;
        //} 
    } else if (places[9].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 9;
        //} 
    } else if (places[10].getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 10;
        //} 
    } else if (places[11].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 11;
        //} 
    } else if (places[12].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 12;
        //} 
    } else if (places[13].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 13;
        //} 
    } else if (places[14].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 14;
        //} 
    } else if (places[15].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 15;
        //} 
    } else if (places[16].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 16;
        //} 
    } else if (places[17].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 17;
        //} 
    } else if (places[18].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 18;
        //} 
    } else if (places[19].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 19;
        //} 
    } else if (places[20].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 20;
        //} 
    } else if (places[21].getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 21;
        //} 
    } else {
            auxiliar = 0;
            retVal = -1;
    }
    return retVal;
}
vector<PropertyCard> Board::getPlaces(){
	return places;
}
vector<sf::Sprite> Board::getSprites(){
    return sprites;
}
void Board::initComponents(){
	//Cafes
	places.push_back(NormalProperty(478, 527, 2, "Mediterranean Avenue", 50, 80));
    sf::Texture t1;
	t1.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
	places[0].setImage(t1);
    sprites.push_back(places[0].getSprite());

	places.push_back(NormalProperty(380, 527, 4, "Baltic Avenue", 50, 80));
    sf::Texture t2;
	t2.loadFromFile("./resources/propiedades/moradas/Baltic_ave.png");
	places[1].setImage(t2);
    sprites.push_back(places[1].getSprite());

	//Celestes
	places.push_back(NormalProperty(232, 527, 6, "Oriental Avenue", 50, 80));
    sf::Texture t3;
    t3.loadFromFile("./resources/propiedades/celestes/Oriental_Ave.png");
    places[2].setImage(t3);
    sprites.push_back(places[2].getSprite());

	places.push_back(NormalProperty(134, 527, 6, "Vermont Avenue", 50, 80));
    sf::Texture t4;
    t4.loadFromFile("./resources/propiedades/celestes/Vermont_ave.png");
    places[3].setImage(t4);
    sprites.push_back(places[3].getSprite());

	places.push_back(NormalProperty(85, 527, 8, "Connecticut Avenue", 50, 80));
    sf::Texture t5;
    t5.loadFromFile("./resources/propiedades/celestes/Connecticut_ave.png");
    places[4].setImage(t5);
    sprites.push_back(places[4].getSprite());

	//Rosadas
	places.push_back(NormalProperty(6, 478, 10, "St. Charles Place", 80, 50));
    sf::Texture t6;
    t6.loadFromFile("./resources/propiedades/rosadas/Charles_Place.png");
    places[5].setImage(t6);
    sprites.push_back(places[5].getSprite());

	places.push_back(NormalProperty(6, 381, 10, "States Avenue", 80, 50));
    sf::Texture t7;
    t7.loadFromFile("./resources/propiedades/rosadas/States_ave.png");
    places[6].setImage(t7);
    sprites.push_back(places[6].getSprite());

	places.push_back(NormalProperty(6, 330, 12, "Virginia Avenue", 80, 50));
    sf::Texture t8;
    t8.loadFromFile("./resources/propiedades/rosadas/Virginia_ave.png");
    places[7].setImage(t8);
    sprites.push_back(places[7].getSprite());

	//Anaranjadas
	places.push_back(NormalProperty(6, 232, 14, "St James Place", 80, 50));
    sf::Texture t9;
    t9.loadFromFile("./resources/propiedades/naranjas/James_Place.png");
    places[8].setImage(t9);
    sprites.push_back(places[8].getSprite());

	places.push_back(NormalProperty(6, 134, 14, "Tennessee Avenue", 80, 50));
    sf::Texture t10;
    t10.loadFromFile("./resources/propiedades/naranjas/Tennessee_Ave.png");
    places[9].setImage(t10);
    sprites.push_back(places[9].getSprite());

	places.push_back(NormalProperty(6, 85, 16, "New York Avenue", 80, 50));
    sf::Texture t11;
    t11.loadFromFile("./resources/propiedades/naranjas/NewYork_ave.png");
    places[10].setImage(t11);
    sprites.push_back(places[10].getSprite());


	//Rojo
	places.push_back(NormalProperty(85, 6, 18, "Kentucky Avenue", 50, 80));
    sf::Texture t12;
    t12.loadFromFile("./resources/propiedades/rojas/Kentucky_ave.png");
    places[11].setImage(t12);
    sprites.push_back(places[11].getSprite());

	places.push_back(NormalProperty(183, 6, 18, "Indiana Avenue", 50, 80));
    sf::Texture t13;
    t13.loadFromFile("./resources/propiedades/rojas/Indiana_ave.png");
    places[12].setImage(t13);
    sprites.push_back(places[12].getSprite());

	places.push_back(NormalProperty(232, 6, 20, "Illinois Avenue", 50, 80));
    sf::Texture t14;
    t14.loadFromFile("./resources/propiedades/rojas/Illinois_ave.png");
    places[13].setImage(t14);
    sprites.push_back(places[13].getSprite());


	//Amarillo
	places.push_back(NormalProperty(330, 6, 22, "Atlantic Avenue", 50, 80));
    sf::Texture t15;
    t15.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    places[14].setImage(t15);
    sprites.push_back(places[14].getSprite());

	places.push_back(NormalProperty(380, 6, 22, "Ventnor Avenue", 50, 80));
    sf::Texture t16;
    t16.loadFromFile("./resources/propiedades/amarillas/Ventnor_ave.png");
    places[15].setImage(t16);
    sprites.push_back(places[15].getSprite());

	places.push_back(NormalProperty(478, 6, 24, "Marvin Gardens", 50, 80));
    sf::Texture t17;
    t17.loadFromFile("./resources/propiedades/amarillas/Marvin_Gardens.png");
    places[16].setImage(t17);
    sprites.push_back(places[16].getSprite());


	//Verde
	places.push_back(NormalProperty(527, 85, 26, "Pacific Avenue", 80, 50));
    sf::Texture t18;
    t18.loadFromFile("./resources/propiedades/verdes/Pacific_Ave.png");
    places[17].setImage(t18);
    sprites.push_back(places[17].getSprite());

	places.push_back(NormalProperty(527, 134, 26, "North Carolina Avenue", 80, 50));
    sf::Texture t19;
    t19.loadFromFile("./resources/propiedades/verdes/Carolina_Ave.png");
    places[18].setImage(t19);
    sprites.push_back(places[18].getSprite());

	places.push_back(NormalProperty(527, 232, 28, "Pennsylvania Avenue", 80, 50));
    sf::Texture t20;
    t20.loadFromFile("./resources/propiedades/verdes/Pennsylvania_Ave.png");
    places[19].setImage(t20);
    sprites.push_back(places[19].getSprite());


	//Azul
	places.push_back(NormalProperty(527, 380, 35, "Park Place", 80, 50));
    sf::Texture t21;
    t21.loadFromFile("./resources/propiedades/azules/Park.png");
    places[20].setImage(t21);
    sprites.push_back(places[20].getSprite());

	places.push_back(NormalProperty(527, 478, 50, "Boardwalk", 80, 50));
    sf::Texture t22;
    t22.loadFromFile("./resources/propiedades/azules/Boardwalk.png");
    places[21].setImage(t22);
    sprites.push_back(places[21].getSprite());

}