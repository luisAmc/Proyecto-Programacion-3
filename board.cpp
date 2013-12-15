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
    if (places[1]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 1;
        //} 
    } else if (places[3]->getRect().contains(sf::Mouse::getPosition(window))) {
    	//if (!auxiliar) {
            auxiliar = 1;
            retVal = 3;
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
    } else if (places[21]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 21;
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
    } else if (places[37]->getRect().contains(sf::Mouse::getPosition(window))) {
        //if (!auxiliar) {
            auxiliar = 1;
            retVal = 37;
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
vector<CommunityChest*> Board::getCommunityChestCards(){
    return communitychest_cards;
}
vector<Chance*> Board::getChanceCards(){
    return chance_cards;    
}
void Board::initComponents(){
	//Cafes
    vector<int> v;
    places.push_back(new SpecialBox(527, 527, 0, 0, "Go", 78, 78, 1, v));

    v.clear(); v.push_back(2); v.push_back(10); v.push_back(30); v.push_back(90); v.push_back(160); v.push_back(250); 
    places.push_back(new NormalProperty(478, 527, 2, 60, "Mediterranean Avenue", 50, 80, v, 50));
    sf::Texture t1;
	t1.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
	places[1]->setImage(t1);
    sprites.push_back(places[1]->getSprite());

    v.clear();
    places.push_back(new CommunityChest(430, 527, 0, 0, "Community Chest", 50, 80, v));

    v.clear(); v.push_back(4); v.push_back(20); v.push_back(60); v.push_back(180); v.push_back(320); v.push_back(450);    
    places.push_back(new NormalProperty(380, 527, 4, 60, "Baltic Avenue", 50, 80, v, 50));
    sf::Texture t3;
	t3.loadFromFile("./resources/propiedades/moradas/Baltic_ave.png");
	places[3]->setImage(t3);
    sprites.push_back(places[3]->getSprite());

    v.clear();
    places.push_back(new SpecialBox(331, 527, 200, 0, "Income Tax", 50, 80, 2, v));

    v.clear();
    places.push_back(new RR(281, 527, 25, 200, "Reading Railroad", 50, 80, v));
    sf::Texture t5;
    t5.loadFromFile("./resources/railroad/railroad1.png");
    places[5]->setImage(t5);
    sprites.push_back(places[5]->getSprite());

	//Celestes
    v.clear(); v.push_back(6); v.push_back(30); v.push_back(90); v.push_back(270); v.push_back(400); v.push_back(550);    
    places.push_back(new NormalProperty(232, 527, 6, 100, "Oriental Avenue", 50, 80, v, 50));
    sf::Texture t6;
    t6.loadFromFile("./resources/propiedades/celestes/Oriental_Ave.png");
    places[6]->setImage(t6);
    sprites.push_back(places[6]->getSprite());

    v.clear();
    places.push_back(new Chance(183, 527, 0, 0, "Chance", 50, 80, v));

    v.clear(); v.push_back(6); v.push_back(30); v.push_back(90); v.push_back(270); v.push_back(400); v.push_back(550);    
    places.push_back(new NormalProperty(134, 527, 6, 100, "Vermont Avenue", 50, 80, v, 50));
    sf::Texture t8;
    t8.loadFromFile("./resources/propiedades/celestes/Vermont_ave.png");
    places[8]->setImage(t8);
    sprites.push_back(places[8]->getSprite());

    v.clear(); v.push_back(8); v.push_back(40); v.push_back(100); v.push_back(300); v.push_back(450); v.push_back(600);    
    places.push_back(new NormalProperty(85, 527, 8, 120, "Connecticut Avenue", 50, 80, v, 50));
    sf::Texture t9;
    t9.loadFromFile("./resources/propiedades/celestes/Connecticut_ave.png");
    places[9]->setImage(t9);
    sprites.push_back(places[9]->getSprite());

    v.clear();
    places.push_back(new SpecialBox(6, 527, 0, 0, "Jail", 78, 78, 3, v));

	//Rosadas
    v.clear(); v.push_back(10); v.push_back(50); v.push_back(150); v.push_back(450); v.push_back(625); v.push_back(750);    
    places.push_back(new NormalProperty(6, 478, 10, 140, "St. Charles Place", 80, 50, v, 100));
    sf::Texture t11;
    t11.loadFromFile("./resources/propiedades/rosadas/Charles_Place.png");
    places[11]->setImage(t11);
    sprites.push_back(places[11]->getSprite());

    v.clear();
    places.push_back(new Utilities(6, 430, 75, 150, "Electric Company", 80, 50, v));
    sf::Texture t12;
    t12.loadFromFile("./resources/utilities/utilities2.png");
    places[12]->setImage(t12);
    sprites.push_back(places[12]->getSprite());

    v.clear(); v.push_back(10); v.push_back(50); v.push_back(150); v.push_back(450); v.push_back(625); v.push_back(750);    
    places.push_back(new NormalProperty(6, 381, 10, 140, "States Avenue", 80, 50, v, 100));
    sf::Texture t13;
    t13.loadFromFile("./resources/propiedades/rosadas/States_ave.png");
    places[13]->setImage(t13);
    sprites.push_back(places[13]->getSprite());

    v.clear(); v.push_back(12); v.push_back(60); v.push_back(180); v.push_back(500); v.push_back(700); v.push_back(900);    
    places.push_back(new NormalProperty(6, 330, 12, 160, "Virginia Avenue", 80, 50, v, 100));
    sf::Texture t14;
    t14.loadFromFile("./resources/propiedades/rosadas/Virginia_ave.png");
    places[14]->setImage(t14);
    sprites.push_back(places[14]->getSprite());

    v.clear();
    places.push_back(new RR(6, 280, 25, 200, "Pennsylvania Railroad", 80, 50, v));
    sf::Texture t15;
    t15.loadFromFile("./resources/railroad/railroad4.png");
    places[15]->setImage(t15);
    sprites.push_back(places[15]->getSprite());

	//Anaranjadas
    v.clear(); v.push_back(14); v.push_back(70); v.push_back(200); v.push_back(550); v.push_back(750); v.push_back(950);    
    places.push_back(new NormalProperty(6, 232, 14, 180, "St James Place", 80, 50, v, 100));
    sf::Texture t16;
    t16.loadFromFile("./resources/propiedades/naranjas/James_Place.png");
    places[16]->setImage(t16);
    sprites.push_back(places[16]->getSprite());

    v.clear();
    places.push_back(new CommunityChest(6, 184, 0, 0, "Community Chest", 80, 50, v));

    v.clear(); v.push_back(14); v.push_back(70); v.push_back(200); v.push_back(550); v.push_back(750); v.push_back(950);    
    places.push_back(new NormalProperty(6, 134, 14, 160, "Tennessee Avenue", 80, 50, v, 100));
    sf::Texture t18;
    t18.loadFromFile("./resources/propiedades/naranjas/Tennessee_Ave.png");
    places[18]->setImage(t18);
    sprites.push_back(places[18]->getSprite());

    v.clear(); v.push_back(16); v.push_back(80); v.push_back(220); v.push_back(600); v.push_back(800); v.push_back(1000);    
    places.push_back(new NormalProperty(6, 85, 16, 200, "New York Avenue", 80, 50, v, 100));
    sf::Texture t19;
    t19.loadFromFile("./resources/propiedades/naranjas/NewYork_ave.png");
    places[19]->setImage(t19);
    sprites.push_back(places[19]->getSprite());

    v.clear();
    places.push_back(new SpecialBox(6, 6, 0, 0, "Free Parking", 78, 78, 4, v));

	//Rojo
    v.clear(); v.push_back(18); v.push_back(90); v.push_back(250); v.push_back(700); v.push_back(875); v.push_back(1050);    
    places.push_back(new NormalProperty(85, 6, 18, 220, "Kentucky Avenue", 50, 80, v, 150));
    sf::Texture t21;
    t21.loadFromFile("./resources/propiedades/rojas/Kentucky_ave.png");
    places[21]->setImage(t21);
    sprites.push_back(places[21]->getSprite());

    v.clear();
    places.push_back(new Chance(134, 6, 0, 0, "Chance", 50, 80, v));

    v.clear(); v.push_back(18); v.push_back(90); v.push_back(250); v.push_back(700); v.push_back(875); v.push_back(1050);    
    places.push_back(new NormalProperty(183, 6, 18, 220, "Indiana Avenue", 50, 80, v, 150));
    sf::Texture t23;
    t23.loadFromFile("./resources/propiedades/rojas/Indiana_ave.png");
    places[23]->setImage(t23);
    sprites.push_back(places[23]->getSprite());

    v.clear(); v.push_back(20); v.push_back(100); v.push_back(300); v.push_back(750); v.push_back(925); v.push_back(1100);    
    places.push_back(new NormalProperty(232, 6, 20, 240, "Illinois Avenue", 50, 80, v, 150));
    sf::Texture t24;
    t24.loadFromFile("./resources/propiedades/rojas/Illinois_ave.png");
    places[24]->setImage(t24);
    sprites.push_back(places[24]->getSprite());

    v.clear();
    places.push_back(new RR(282, 6, 25, 200, "B & O Railroad", 50, 80, v));
    sf::Texture t25;
    t25.loadFromFile("./resources/railroad/railroad3.png");
    places[25]->setImage(t25);
    sprites.push_back(places[25]->getSprite());

	//Amarillo
    v.clear(); v.push_back(22); v.push_back(110); v.push_back(330); v.push_back(800); v.push_back(975); v.push_back(1150);    
    places.push_back(new NormalProperty(330, 6, 22, 260, "Atlantic Avenue", 50, 80, v, 150));
    sf::Texture t26;
    t26.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    places[26]->setImage(t26);
    sprites.push_back(places[26]->getSprite());

    v.clear(); v.push_back(22); v.push_back(110); v.push_back(330); v.push_back(800); v.push_back(975); v.push_back(1150);    
    places.push_back(new NormalProperty(380, 6, 22, 260, "Ventnor Avenue", 50, 80, v, 150));
    sf::Texture t27;
    t27.loadFromFile("./resources/propiedades/amarillas/Ventnor_ave.png");
    places[27]->setImage(t27);
    sprites.push_back(places[27]->getSprite());

    v.clear();
    places.push_back(new Utilities(430, 6, 75, 150, "Water Works", 50, 80, v));
    sf::Texture t28;
    t28.loadFromFile("./resources/utilities/utilities1.png");
    places[28]->setImage(t28);
    sprites.push_back(places[28]->getSprite());

    v.clear(); v.push_back(24); v.push_back(120); v.push_back(360); v.push_back(850); v.push_back(1025); v.push_back(1200);    
    places.push_back(new NormalProperty(478, 6, 24, 280, "Marvin Gardens", 50, 80, v, 150));
    sf::Texture t29;
    t29.loadFromFile("./resources/propiedades/amarillas/Marvin_Gardens.png");
    places[29]->setImage(t29);
    sprites.push_back(places[29]->getSprite());

    v.clear();
    places.push_back(new SpecialBox(527, 6, 0, 0, "Go to Jail", 78, 78, 5, v));

	//Verde
    v.clear(); v.push_back(26); v.push_back(130); v.push_back(390); v.push_back(900); v.push_back(1100); v.push_back(1275);    
    places.push_back(new NormalProperty(527, 85, 26, 300, "Pacific Avenue", 80, 50, v, 200));
    sf::Texture t31;
    t31.loadFromFile("./resources/propiedades/verdes/Pacific_Ave.png");
    places[31]->setImage(t31);
    sprites.push_back(places[31]->getSprite());

    v.clear(); v.push_back(26); v.push_back(130); v.push_back(390); v.push_back(900); v.push_back(1100); v.push_back(1275);    
    places.push_back(new NormalProperty(527, 134, 26, 300, "North Carolina Avenue", 80, 50, v, 200));
    sf::Texture t32;
    t32.loadFromFile("./resources/propiedades/verdes/Carolina_Ave.png");
    places[32]->setImage(t32);
    sprites.push_back(places[32]->getSprite());

    v.clear();
    places.push_back(new CommunityChest(527, 184, 0, 0, "Community Chest", 80, 50, v));

    v.clear(); v.push_back(28); v.push_back(150); v.push_back(390); v.push_back(900); v.push_back(1200); v.push_back(1400);    
    places.push_back(new NormalProperty(527, 232, 28, 320, "Pennsylvania Avenue", 80, 50, v, 200));
    sf::Texture t34;
    t34.loadFromFile("./resources/propiedades/verdes/Pennsylvania_Ave.png");
    places[34]->setImage(t34);
    sprites.push_back(places[34]->getSprite());

    v.clear();
    places.push_back(new RR(527, 282, 25, 200, "Short Line Railroad", 80, 50, v));
    sf::Texture t35;
    t35.loadFromFile("./resources/railroad/railroad2.png");
    places[35]->setImage(t35);
    sprites.push_back(places[35]->getSprite());

    v.clear();
    places.push_back(new Chance(527, 332, 0, 0, "Chance", 80, 50, v));

	//Azul
    v.clear(); v.push_back(35); v.push_back(175); v.push_back(500); v.push_back(1100); v.push_back(1300); v.push_back(1500);    
    places.push_back(new NormalProperty(527, 380, 35, 360, "Park Place", 80, 50, v, 200));
    sf::Texture t37;
    t37.loadFromFile("./resources/propiedades/azules/Park.png");
    places[37]->setImage(t37);
    sprites.push_back(places[37]->getSprite());

    v.clear();
    places.push_back(new SpecialBox(527, 430, 100, 0, "Luxury Tax", 80, 50, 6, v));

    v.clear(); v.push_back(50); v.push_back(175); v.push_back(500); v.push_back(1100); v.push_back(1700); v.push_back(2000);    
    places.push_back(new NormalProperty(527, 478, 50, 400, "Boardwalk", 80, 50, v, 200));
    sf::Texture t39;
    t39.loadFromFile("./resources/propiedades/azules/Boardwalk.png");
    places[39]->setImage(t39);
    sprites.push_back(places[39]->getSprite());

    //-----------------------------------------------------------------------------------------------------------
    //***********************************************************************************************************
    //-----------------------------------------------------------------------------------------------------------

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC0", 0, 0, v));
    sf::Texture cc0;
    cc0.loadFromFile("./resources/community/community1.png");
    communitychest_cards[0]->setImage(cc0);
    communitychest_cards[0]->setId(0);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC1", 0, 0, v));
    sf::Texture cc1;
    cc1.loadFromFile("./resources/community/community2.png");
    communitychest_cards[1]->setImage(cc1);
    communitychest_cards[1]->setId(1);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC2", 0, 0, v));
    sf::Texture cc2;
    cc2.loadFromFile("./resources/community/community3.png");
    communitychest_cards[2]->setImage(cc2);
    communitychest_cards[2]->setId(2);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC3", 0, 0, v));
    sf::Texture cc3;
    cc3.loadFromFile("./resources/community/community4.png");
    communitychest_cards[3]->setImage(cc3);
    communitychest_cards[3]->setId(3);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC4", 0, 0, v));
    sf::Texture cc4;
    cc4.loadFromFile("./resources/community/community5.png");
    communitychest_cards[4]->setImage(cc4);
    communitychest_cards[4]->setId(4);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC5", 0, 0, v));
    sf::Texture cc5;
    cc5.loadFromFile("./resources/community/community6.png");
    communitychest_cards[5]->setImage(cc5);
    communitychest_cards[5]->setId(5);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC6", 0, 0, v));
    sf::Texture cc6;
    cc6.loadFromFile("./resources/community/community7.png");
    communitychest_cards[6]->setImage(cc6);
    communitychest_cards[6]->setId(6);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC7", 0, 0, v));
    sf::Texture cc7;
    cc7.loadFromFile("./resources/community/community8.png");
    communitychest_cards[7]->setImage(cc7);
    communitychest_cards[7]->setId(7);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC8", 0, 0, v));
    sf::Texture cc8;
    cc8.loadFromFile("./resources/community/community9.png");
    communitychest_cards[8]->setImage(cc8);
    communitychest_cards[8]->setId(8);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC9", 0, 0, v));
    sf::Texture cc9;
    cc9.loadFromFile("./resources/community/community10.png");
    communitychest_cards[9]->setImage(cc9);
    communitychest_cards[9]->setId(9);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC10", 0, 0, v));
    sf::Texture cc10;
    cc10.loadFromFile("./resources/community/community11.png");
    communitychest_cards[10]->setImage(cc10);
    communitychest_cards[10]->setId(10);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC11", 0, 0, v));
    sf::Texture cc11;
    cc11.loadFromFile("./resources/community/community12.png");
    communitychest_cards[11]->setImage(cc11);
    communitychest_cards[11]->setId(11);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC12", 0, 0, v));
    sf::Texture cc12;
    cc12.loadFromFile("./resources/community/community13.png");
    communitychest_cards[12]->setImage(cc12);
    communitychest_cards[12]->setId(12);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC13", 0, 0, v));
    sf::Texture cc13;
    cc13.loadFromFile("./resources/community/community14.png");
    communitychest_cards[13]->setImage(cc13);
    communitychest_cards[13]->setId(13);

    v.clear();
    communitychest_cards.push_back(new CommunityChest(0, 0, 0, 0, "CC14", 0, 0, v));
    sf::Texture cc14;
    cc14.loadFromFile("./resources/community/community15.png");
    communitychest_cards[14]->setImage(cc14);
    communitychest_cards[14]->setId(14);

    //-----------------------------------------------------------------------------------------------------------
    //***********************************************************************************************************
    //-----------------------------------------------------------------------------------------------------------

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C0", 0, 0, v));
    sf::Texture c0;
    c0.loadFromFile("./resources/chance/chance1.png");
    chance_cards[0]->setImage(c0);
    chance_cards[0]->setId(0);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C1", 0, 0, v));
    sf::Texture c1;
    c1.loadFromFile("./resources/chance/chance2.png");
    chance_cards[1]->setImage(c1);
    chance_cards[1]->setId(1);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C2", 0, 0, v));
    sf::Texture c2;
    c2.loadFromFile("./resources/chance/chance3.png");
    chance_cards[2]->setImage(c2);
    chance_cards[2]->setId(2);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C3", 0, 0, v));
    sf::Texture c3;
    c3.loadFromFile("./resources/chance/chance4.png");
    chance_cards[3]->setImage(c3);
    chance_cards[3]->setId(3);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C4", 0, 0, v));
    sf::Texture c4;
    c4.loadFromFile("./resources/chance/chance5.png");
    chance_cards[4]->setImage(c4);
    chance_cards[4]->setId(4);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C5", 0, 0, v));
    sf::Texture c5;
    c5.loadFromFile("./resources/chance/chance6.png");
    chance_cards[5]->setImage(c5);
    chance_cards[5]->setId(5);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C6", 0, 0, v));
    sf::Texture c6;
    c6.loadFromFile("./resources/chance/chance7.png");
    chance_cards[6]->setImage(c6);
    chance_cards[6]->setId(6);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C7", 0, 0, v));
    sf::Texture c7;
    c7.loadFromFile("./resources/chance/chance8.png");
    chance_cards[7]->setImage(c7);
    chance_cards[7]->setId(7);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C8", 0, 0, v));
    sf::Texture c8;
    c8.loadFromFile("./resources/chance/chance9.png");
    chance_cards[8]->setImage(c8);
    chance_cards[8]->setId(8);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C9", 0, 0, v));
    sf::Texture c9;
    c9.loadFromFile("./resources/chance/chance10.png");
    chance_cards[9]->setImage(c9);
    chance_cards[9]->setId(9);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C10", 0, 0, v));
    sf::Texture c10;
    c10.loadFromFile("./resources/chance/chance11.png");
    chance_cards[10]->setImage(c10);
    chance_cards[10]->setId(10);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C11", 0, 0, v));
    sf::Texture c11;
    c11.loadFromFile("./resources/chance/chance12.png");
    chance_cards[11]->setImage(c11);
    chance_cards[11]->setId(11);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C12", 0, 0, v));
    sf::Texture c12;
    c12.loadFromFile("./resources/chance/chance13.png");
    chance_cards[12]->setImage(c12);
    chance_cards[12]->setId(12);

    v.clear();
    chance_cards.push_back(new Chance(0, 0, 0, 0, "C13", 0, 0, v));
    sf::Texture c13;
    c13.loadFromFile("./resources/chance/chance14.png");
    chance_cards[13]->setImage(c13);
    chance_cards[13]->setId(13);
}