#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "board.h"
#include "propertycard.h"
#include "normalproperty.h"
#include "rr.h"
#include "utilities.h"
#include "dice.h"
#include "specialbox.h"
#include <fstream>
#include <cstring>
using namespace std;

vector<sf::IntRect> vectorCards(int j);
void selectorRectangles();
vector<sf::Sprite> createSprites();
vector<sf::Vector2i> boardPosition();
void drawMiniProperties(sf::RenderWindow&, vector<int>&, vector<int>&);
void loadMiniProperties(vector<sf::Sprite>&);

int main (int argc, char * argv[]) {
    sf::RenderWindow window;
    sf::RenderWindow player_selector;
    sf::RenderWindow buy_property;
    sf::RenderWindow pay_window;
    sf::RenderWindow winner_window;
    sf::RenderWindow auction_window;
    sf::RenderWindow house_window;
    sf::RenderWindow c_window;
    sf::RenderWindow save_window;

    vector<int> mini_pj1;
    vector<int> mini_pj2;

    Board board;
    vector<PropertyCard*> board_places = board.getPlaces();
    vector<sf::Sprite> board_sprites = createSprites();
    vector<sf::Sprite> mini_properties;
    loadMiniProperties(mini_properties);
    vector<sf::Vector2i> board_positions = boardPosition();
    vector<CommunityChest*> communitychest_cards = board.getCommunityChestCards();
    vector<Chance*> chance_cards = board.getChanceCards();

    srand(time(0));
    for (int i = 0; i < communitychest_cards.size(); i++){
        int r = rand() % communitychest_cards.size();
        CommunityChest* temp = communitychest_cards[i];
        communitychest_cards[i] = communitychest_cards[r];
        communitychest_cards[r] = temp;
    }

    srand(time(0));
    for (int i = 0; i < chance_cards.size(); i++){
        int r = rand() % chance_cards.size();
        Chance* temp = chance_cards[i];
        chance_cards[i] = chance_cards[r];
        chance_cards[r] = temp;
    }

    Dice dice;

    sf::Texture buy_button_image;
    buy_button_image.loadFromFile("./resources/buy_button.png");
    sf::Sprite buy_button(buy_button_image);
    buy_button.setPosition(255, 60);
    sf::IntRect buy_button_rect(buy_button.getPosition().x, buy_button.getPosition().y, 60, 30);

    sf::Texture auction_button_image;
    auction_button_image.loadFromFile("./resources/auction_button.png");
    sf::Sprite auction_button(auction_button_image);
    auction_button.setPosition(230, 110);
    sf::IntRect auction_button_rect(auction_button.getPosition().x, auction_button.getPosition().y, 120, 30);

    sf::Texture accept_button_image;
    accept_button_image.loadFromFile("./resources/accept_button.png");
    sf::Sprite accept_button(accept_button_image);
    accept_button.setPosition(255, 80);
    sf::IntRect accept_button_rect(accept_button.getPosition().x, accept_button.getPosition().y, 60, 30);

    sf::Texture close_button_image;
    close_button_image.loadFromFile("./resources/close_button.png");
    sf::Sprite close_button(close_button_image);
    close_button.setPosition(150, 180);
    sf::IntRect close_button_rect(close_button.getPosition().x, close_button.getPosition().y, 60, 30);

    sf::Texture auction_accept_button_image;
    auction_accept_button_image.loadFromFile("./resources/auction_accept_button.png");
    sf::Sprite auction_accept_button(auction_accept_button_image);
    auction_accept_button.setPosition(255, 110);
    sf::IntRect auction_accept_button_rect(auction_accept_button.getPosition().x, auction_accept_button.getPosition().y, 60, 30);

    sf::Texture auction_cancel_button_image;
    auction_cancel_button_image.loadFromFile("./resources/auction_cancel_button.png");
    sf::Sprite auction_cancel_button(auction_cancel_button_image);
    auction_cancel_button.setPosition(255,150);
    sf::IntRect auction_cancel_button_rect(auction_cancel_button.getPosition().x, auction_cancel_button.getPosition().y, 60, 30);

    sf::Texture buy_house_accept_button_image;
    buy_house_accept_button_image.loadFromFile("./resources/auction_accept_button.png");
    sf::Sprite buy_house_accept_button(buy_house_accept_button_image);
    buy_house_accept_button.setPosition(255, 110);
    sf::IntRect buy_house_accept_button_rect(buy_house_accept_button.getPosition().x, buy_house_accept_button.getPosition().y, 60, 30);

    sf::Texture buy_house_cancel_button_image;
    buy_house_cancel_button_image.loadFromFile("./resources/auction_cancel_button.png");
    sf::Sprite buy_house_cancel_button(buy_house_cancel_button_image);
    buy_house_cancel_button.setPosition(255, 150);
    sf::IntRect buy_house_cancel_button_rect(buy_house_cancel_button.getPosition().x, buy_house_cancel_button.getPosition().y, 60, 30);

    sf::Texture c_accept_button_image;
    c_accept_button_image.loadFromFile("./resources/auction_accept_button.png");
    sf::Sprite c_accept_button(c_accept_button_image);
    c_accept_button.setPosition(235, 60);
    sf::IntRect c_accept_button_rect(c_accept_button.getPosition().x, c_accept_button.getPosition().y, 60, 30);

    sf::Texture ranura1_button_image;
    ranura1_button_image.loadFromFile("./resources/ranura1.png");
    sf::Sprite ranura1_button(ranura1_button_image);
    ranura1_button.setPosition(630, 477);
    sf::IntRect ranura1_button_rect(ranura1_button.getPosition().x, ranura1_button.getPosition().y, 140, 30);

    sf::Texture ranura2_button_image;
    ranura2_button_image.loadFromFile("./resources/ranura2.png");
    sf::Sprite ranura2_button(ranura2_button_image);
    ranura2_button.setPosition(630, 517);
    sf::IntRect ranura2_button_rect(ranura2_button.getPosition().x, ranura2_button.getPosition().y, 140, 30);

    sf::Texture ranura3_button_image;
    ranura3_button_image.loadFromFile("./resources/ranura3.png");
    sf::Sprite ranura3_button(ranura3_button_image);
    ranura3_button.setPosition(630, 557);
    sf::IntRect ranura3_button_rect(ranura3_button.getPosition().x, ranura3_button.getPosition().y, 140, 30);

    sf::RenderWindow info_window;
    sf::Texture info_image;
    info_window.create(sf::VideoMode(200, 228), "Information", sf::Style::None);
    info_window.setPosition(sf::Vector2i(260, 245));
    info_window.setVisible(false);
    info_image.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    sf::Sprite info(info_image);
    info.setPosition(0, 0);

    //************************************************************************************************************
    //Creo lo referente a los dos jugadores
    //---------------------------------------------------------------------
    int auxiliar = 0, cardIndex = 0, player_turn = 1, pj1_position = 0, pj2_position = 0;
    //---------------------------------------------------------------------
    //Pido los nombres de los jugadores
     //Creacion de la fuente para los textos desplegados
    sf::Font font;
    if(!font.loadFromFile("./resources/Action Man.ttf")) {
        std::cout << "No encontre el font!" << std::endl;
    }

    Player pj1("", 1);
    Player pj2("", 2);

    string opcion;
    cout << endl << endl
    << "-------------Monopoly--------------" << endl
    << "1) Nuevo Juego" << endl
<< "2) Cargar partida" << endl
<< "Ingrese el numero de seleccion:" << endl;
getline(cin, opcion);

int o = atoi(opcion.c_str());
string name1;
string name2;
switch (o) {
    case 1:
    {
        std::cout << "Ingrese el nombre del primer jugador:" << std::endl;
        getline(cin, name1);
        std::cout << endl;
        std::cout << "Ingrese el nombre del segundo jugador:" << std::endl;
        getline(cin, name2);
        std::cout << endl;
        pj1.setName(name1.c_str());
        pj2.setName(name2.c_str());
    }
    break;
    case 2:
    {
        string opcion2;
        cout << endl 
        << "Seleccione una ranura" << endl
        << "1) Ranura 1" << endl
<< "2) Ranura 2" << endl
<< "3) Ranura 3" << endl
<< "Ingrese el numero de su selecion:" << endl;
getline(cin, opcion2);
int o2 = atoi(opcion2.c_str());
int m1, m2;
char cadena[512];
switch (o2) {
    case 1:
    {
        ifstream input("./resources/ranura1.txt");
        int fila = 0;
        while (input.getline(cadena, 512)) {
            if (fila == 0) {
                char *aux; aux = strtok(cadena, "#");
                int i = 0; 
                while (aux != NULL) {
                    if (i == 0) {
                        name1 = aux;
                    } else if (i == 1) {
                        m1 = atoi(aux);
                    } else if (i == 2) {
                        pj1_position = atoi(aux);
                    } else if (i > 2) {
                        mini_pj1.push_back(atoi(aux)); 
                    }
                    i++;
                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            } else {
                                char *aux; aux = strtok(cadena, "#");
                                int i = 0; 
                                while (aux != NULL) {
                                    if (i == 0) {
                                        name2 = aux;
                                    } else if (i == 1) {
                                        m2 = atoi(aux);
                                    } else if (i == 2) {
                                        pj2_position = atoi(aux);
                                    } else if (i > 2) {
                                        mini_pj2.push_back(atoi(aux));
                                    }
                                    i++;
                                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            }//Final de los ifs
                            fila++;
                        }//Final del while
                    }//Final del caso 1
                    break;
                    case 2:
                    {
                        ifstream input("./resources/ranura2.txt");
                        int fila = 0;
                        while (input.getline(cadena, 512)) {
                            if (fila == 0) {
                                char *aux; aux = strtok(cadena, "#");
                                int i = 0; 
                                while (aux != NULL) {
                                    if (i == 0) {
                                        name1 = aux;
                                    } else if (i == 1) {
                                        m1 = atoi(aux);
                                    } else if (i == 2) {
                                        pj1_position = atoi(aux);
                                    } else if (i > 2) {
                                        mini_pj1.push_back(atoi(aux));
                                    }
                                    i++;
                                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            } else {
                                char *aux; aux = strtok(cadena, "#");
                                int i = 0; 
                                while (aux != NULL) {
                                    if (i == 0) {
                                        name2 = aux;
                                    } else if (i == 1) {
                                        m2 = atoi(aux);
                                    } else if (i == 2) {
                                        pj2_position = atoi(aux);
                                    } else if (i > 2) {
                                        mini_pj2.push_back(atoi(aux));
                                    }
                                    i++;
                                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            }//Final de los ifs
                            fila++;
                        }//Final del while
                    }
                    break;
                    case 3:
                    {
                        ifstream input("./resources/ranura3.txt");
                        int fila = 0;
                        while (input.getline(cadena, 512)) {
                            if (fila == 0) {
                                char *aux; aux = strtok(cadena, "#");
                                int i = 0; 
                                while (aux != NULL) {
                                    if (i == 0) {
                                        name1 = aux;
                                    } else if (i == 1) {
                                        m1 = atoi(aux);
                                    } else if (i == 2) {
                                        pj1_position = atoi(aux);
                                    } else if (i > 2) {
                                        mini_pj1.push_back(atoi(aux));
                                    }
                                    i++;
                                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            } else {
                                char *aux; aux = strtok(cadena, "#");
                                int i = 0; 
                                while (aux != NULL) {
                                    if (i == 0) {
                                        name2 = aux;
                                    } else if (i == 1) {
                                        m2 = atoi(aux);
                                    } else if (i == 2) {
                                        pj2_position = atoi(aux);
                                    } else if (i > 2) {
                                        mini_pj2.push_back(atoi(aux));
                                    }
                                    i++;
                                    aux = strtok(NULL, "#"); 
                                }//Final del while interno
                            }//Final de los ifs
                            fila++;
                        }//Final del while
                    }
                    break;
                }//Final del switch de ranura
                pj1.setName(name1.c_str());
                pj2.setName(name2.c_str());
                pj1.setMoney(m1);
                pj2.setMoney(m2);
                for (int i = 0; i < mini_pj1.size(); i++) {
                    board_places[mini_pj1[i]]->setAvailable(0);
                    if (NormalProperty* np = dynamic_cast<NormalProperty*>(board_places[mini_pj1[i]])) {
                        np->setOwner(1);
                    } else if (Utilities* u = dynamic_cast<Utilities*>(board_places[mini_pj1[i]])) {
                        u->setOwner(1);
                    } else if (RR* rr = dynamic_cast<RR*>(board_places[mini_pj1[i]])) {
                        rr->setOwner(1);
                    }
                }
                for (int i = 0; i < mini_pj2.size(); i++) {
                    board_places[mini_pj2[i]]->setAvailable(0);
                    if (NormalProperty* np = dynamic_cast<NormalProperty*>(board_places[mini_pj1[i]])) {
                        np->setOwner(2);
                    } else if (Utilities* u = dynamic_cast<Utilities*>(board_places[mini_pj1[i]])) {
                        u->setOwner(2);
                    } else if (RR* rr = dynamic_cast<RR*>(board_places[mini_pj1[i]])) {
                        rr->setOwner(2);
                    }
                }
            }//Final de iniciar con ranura
            break;
            default:
            cout << "Se iniciara un juego nuevo." << endl;
            std::cout << "Ingrese el nombre del primer jugador:" << std::endl;
            getline(cin, name1);
            std::cout << endl;
            std::cout << "Ingrese el nombre del segundo jugador:" << std::endl;
            getline(cin, name2);
            std::cout << endl;
            pj1.setName(name1.c_str());
            pj2.setName(name2.c_str());
            break;
        } 

        sf::Text pj1Name(pj1.getName(), font, 18);
        sf::Text pj2Name(pj2.getName(), font, 18);
        pj1Name.setPosition(624, 10);
        pj2Name.setPosition(624, 220);
        pj1Name.setColor(sf::Color::Black);
        pj2Name.setColor(sf::Color::Black);
        pj1Name.setStyle(sf::Text::Bold);
        pj2Name.setStyle(sf::Text::Bold);

        std::stringstream money1;
        money1 << "$ " << pj1.getMoney();
        std::stringstream money2;
        money2 << "$ " << pj2.getMoney();

        std::stringstream text_accept;

        sf::Text pj1Money(money1.str(), font, 15);
        sf::Text pj2Money(money2.str(), font, 15);
        pj1Money.setPosition(635, 30);
        pj2Money.setPosition(635, 240);
        pj1Money.setColor(sf::Color(0, 255, 0));
        pj2Money.setColor(sf::Color(0, 255, 0));
        pj1Money.setStyle(sf::Text::Bold);
        pj2Money.setStyle(sf::Text::Bold);

        sf::Texture pj1_texture;
        pj1_texture.loadFromFile("./resources/robot.png");
        sf::Texture pj2_texture;
        pj2_texture.loadFromFile("./resources/ring.png");
        sf::Sprite pj1_image(pj1_texture);
        sf::Sprite pj2_image(pj2_texture);
        pj1_image.setPosition(board_positions[0].x, board_positions[0].y);
        pj2_image.setPosition(board_positions[0].x, board_positions[0].y);
        pj1_image.setPosition(board_positions[pj1_position].x, board_positions[pj1_position].y);
        pj2_image.setPosition(board_positions[pj2_position].x, board_positions[pj2_position].y);
    //************************************************************************************************************

        vector<sf::IntRect> cards_pj1 = vectorCards(0);
        vector<sf::IntRect> cards_pj2 = vectorCards(209);

    //Creo la ventana principal
        window.create(sf::VideoMode(800, 610), "Monopoly");
        window.setPosition(sf::Vector2i(0, 0));

        sf::Texture background_image;
        if (!background_image.loadFromFile("./resources/monopoly_board.jpg"))
            return EXIT_FAILURE;
        sf::Sprite background(background_image);

        sf::Texture dice_background;
        dice_background.loadFromFile("./resources/dados.png");
        sf::Sprite dice_image(dice_background);
        dice_image.setPosition(sf::Vector2f(660, 424));
        sf::IntRect dice_rect(dice_image.getPosition().x, dice_image.getPosition().y, 60, 48);

        while (window.isOpen()) {
            sf::Event Event;

            while (window.pollEvent(Event)) {

                switch (Event.type) {
                    case sf::Event::Closed:
                    window.close();
                    break;
                    case sf::Event::MouseMoved:
                    cardIndex = board.compare(window, info_window, auxiliar);
                    if (cardIndex != -1){
                        info_window.setPosition(sf::Vector2i(260, 245));
                        info_window.setVisible(true);
                        info_window.clear(sf::Color::White);
                        info_window.draw(board_places[cardIndex]->getSprite());
                        info_window.display();
                    } else {
                        info_window.setVisible(false);
                    }
                    break;
                    case sf::Event::MouseButtonPressed:
                    if (dice_rect.contains(sf::Mouse::getPosition(window))){
                        int mov = dice.getValue();
                        if (player_turn == 1) {
                            if (pj1_position + mov >= 40) {
                                pj1_position = mov - (40 - pj1_position);
                                pj1.setMoney(pj1.getMoney() + 200);
                            } else {
                                pj1_position += mov;
                            }

                            pj1_image.setPosition(board_positions[pj1_position].x, board_positions[pj1_position].y);

                            window.clear(sf::Color::White);
                            window.draw(background);
                            window.draw(pj1Name);
                            window.draw(pj2Name);
                            window.draw(pj1Money);
                            window.draw(pj2Money);
                            window.draw(pj1_image); 
                            window.draw(pj2_image);   
                            window.draw(dice_image);
                            window.draw(ranura1_button);
                            window.draw(ranura2_button);
                            window.draw(ranura3_button);
                            drawMiniProperties(window, mini_pj1, mini_pj2);
                            window.display();

                            if (NormalProperty* np = dynamic_cast<NormalProperty*>(board_places[pj1_position])) {
                                if (np->getAvailable()) {
                                    buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                                    buy_property.setPosition(sf::Vector2i(160, 190));
                                    while (buy_property.isOpen()) {
                                        sf::Event bEvent;
                                        while (buy_property.pollEvent(bEvent)) {
                                            switch (bEvent.type) {
                                                case sf::Event::Closed:
                                                buy_property.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                    if (pj1.getMoney() > np->getCost()) {
                                                        pj1.setMoney(pj1.getMoney() - np->getCost());
                                                        np->setAvailable(0);
                                                        pj1.setCard(np);
                                                        np->setOwner(1);
                                                        mini_pj1.push_back(pj1_position);
                                                        buy_property.close();
                                                    }
                                                } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                    auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                                    auction_window.setPosition(sf::Vector2i(160, 190));
                                                    while (auction_window.isOpen()) {
                                                        sf::Event aEvent;
                                                        while (auction_window.pollEvent(aEvent)) {
                                                            switch (aEvent.type) {
                                                                case sf::Event::Closed:
                                                                auction_window.close();
                                                                buy_property.close();
                                                                break;
                                                                case sf::Event::MouseButtonPressed:
                                                                if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                    if (pj2.getMoney() > np->getCost()){
                                                                        pj2.setMoney(pj2.getMoney() - np->getCost());
                                                                        np->setAvailable(0);
                                                                        pj2.setCard(np);
                                                                        np->setOwner(2);
                                                                        mini_pj2.push_back(pj1_position);
                                                                        auction_window.close();
                                                                        buy_property.close();
                                                                    }
                                                                } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                    auction_window.close();
                                                                    buy_property.close();
                                                                }
                                                                break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj2.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(np->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(np->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                        window.draw(ranura1_button);
                                        window.draw(ranura2_button);
                                        window.draw(ranura3_button);
                                    }
                                }    
                            } else if (!np->getAvailable()){
                                if (np->getOwner() == 2) {
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()){
                                        sf::Event pEvent;
                                        while (pay_window.pollEvent(pEvent)){
                                            switch (pEvent.type){
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))) {
                                                    pay_window.close();
                                                } 
                                                break;
                                            }
                                            text_accept.str("");
                                            text_accept << pj1.getName() << endl << " have to pay $" << np->getRent() << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(np->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }
                                    }
                                    pj1.setMoney(pj1.getMoney() - np->getRent());
                                    pj2.setMoney(pj2.getMoney() + np->getRent());
                                } else if (np->getOwner() == 1) {
                                    if (np->getHouse() < 4) {
                                        house_window.create(sf::VideoMode(400, 228), "Monopoly");
                                        house_window.setPosition(sf::Vector2i(160, 190));
                                        while (house_window.isOpen()) {
                                            sf::Event hEvent;
                                            while (house_window.pollEvent(hEvent)){
                                                switch (hEvent.type) {
                                                    case sf::Event::Closed:
                                                    house_window.close();
                                                    break;
                                                    case sf::Event::MouseButtonPressed:
                                                    if (buy_house_accept_button_rect.contains(sf::Mouse::getPosition(house_window)) && (pj1.getMoney() > np->getHouseCost())) {
                                                        np->addHouses();
                                                        pj1.setMoney(pj1.getMoney() - np->getHouseCost());
                                                        house_window.close();
                                                    } else if (buy_house_cancel_button_rect.contains(sf::Mouse::getPosition(house_window)))
                                                    house_window.close();
                                                    break;
                                                }//Final del switch
                                            }//Final del while
                                            text_accept.str("");
                                            text_accept << "Buy a house?" << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            house_window.clear(sf::Color::White);
                                            house_window.draw(np->getSprite());
                                            house_window.draw(itext);
                                            house_window.draw(buy_house_accept_button);
                                            house_window.draw(buy_house_cancel_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            house_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }//Final del isOpen()
                                    }//Final del la validacion de cant. de casas
                                }
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------    
                        } else if (Utilities* u = dynamic_cast<Utilities*>(board_places[pj1_position])) {
                            if (u->getAvailable()){
                                buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                                buy_property.setPosition(sf::Vector2i(160, 190));
                                while (buy_property.isOpen()){
                                    sf::Event bEvent;
                                    while (buy_property.pollEvent(bEvent)){
                                        switch (bEvent.type) {
                                            case sf::Event::Closed:
                                            buy_property.close();
                                            break;
                                            case sf::Event::MouseButtonPressed:
                                            if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                if (pj1.getMoney() > u->getCost()) {
                                                    pj1.setMoney(pj1.getMoney() - u->getCost());
                                                    u->setAvailable(0);
                                                    pj1.setCard(u);
                                                    u->setOwner(1);
                                                    u->addCount();
                                                    mini_pj1.push_back(pj1_position);
                                                    buy_property.close();
                                                }
                                            } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                                auction_window.setPosition(sf::Vector2i(160, 190));
                                                while (auction_window.isOpen()) {
                                                    sf::Event aEvent;
                                                    while (auction_window.pollEvent(aEvent)) {
                                                        switch (aEvent.type) {
                                                            case sf::Event::Closed:
                                                            auction_window.close();
                                                            buy_property.close();
                                                            break;
                                                            case sf::Event::MouseButtonPressed:
                                                            if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                if (pj2.getMoney() > u->getCost()){
                                                                    pj2.setMoney(pj2.getMoney() - u->getCost());
                                                                    u->setAvailable(0);
                                                                    pj2.setCard(u);
                                                                    u->setOwner(2);
                                                                    mini_pj2.push_back(pj1_position);
                                                                    auction_window.close();
                                                                    buy_property.close();
                                                                }
                                                            } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                auction_window.close();
                                                                buy_property.close();
                                                            }
                                                            break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj2.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(u->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }//Final del switch de bEvent.type
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(u->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                        window.draw(ranura1_button);
                                        window.draw(ranura2_button);
                                        window.draw(ranura3_button);
                                    }//Fin del poolEvent(bEvent)
                                }//Fin del mientras buy_property este abierta
                            } else if (!u->getAvailable()){
                                if (u->getOwner() == 2) {
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()){
                                        sf::Event pEvent;
                                        while (pay_window.pollEvent(pEvent)){
                                            switch (pEvent.type){
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))) {
                                                    pay_window.close();
                                                }
                                                break;
                                            }
                                            text_accept.str("");
                                            text_accept << pj1.getName() << endl << " have to pay $" << (u->getRent() * u->getCount()) << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(u->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }
                                    }
                                    pj1.setMoney(pj1.getMoney() - (u->getRent() * u->getCount()));
                                    pj2.setMoney(pj2.getMoney() + (u->getRent() * u->getCount()));
                                }
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (RR* rr = dynamic_cast<RR*>(board_places[pj1_position])) {
                            if (rr->getAvailable()){
                                buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                                buy_property.setPosition(sf::Vector2i(160, 190));
                                while (buy_property.isOpen()){
                                    sf::Event bEvent;
                                    while (buy_property.pollEvent(bEvent)){
                                        switch (bEvent.type) {
                                            case sf::Event::Closed:
                                            buy_property.close();
                                            break;
                                            case sf::Event::MouseButtonPressed:
                                            if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                if (pj1.getMoney() > rr->getCost()) {
                                                    pj1.setMoney(pj1.getMoney() - rr->getCost());
                                                    rr->setAvailable(0);
                                                    pj1.setCard(rr);
                                                    rr->setOwner(1);
                                                    rr->addRailroads();
                                                    mini_pj1.push_back(pj1_position);
                                                    buy_property.close();
                                                }
                                            } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                                auction_window.setPosition(sf::Vector2i(160, 190));
                                                while (auction_window.isOpen()) {
                                                    sf::Event aEvent;
                                                    while (auction_window.pollEvent(aEvent)) {
                                                        switch (aEvent.type) {
                                                            case sf::Event::Closed:
                                                            auction_window.close();
                                                            buy_property.close();
                                                            break;
                                                            case sf::Event::MouseButtonPressed:
                                                            if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                if (pj2.getMoney() > rr->getCost()){
                                                                    pj2.setMoney(pj2.getMoney() - rr->getCost());
                                                                    rr->setAvailable(0);
                                                                    pj2.setCard(rr);
                                                                    rr->setOwner(2);
                                                                    mini_pj2.push_back(pj1_position);
                                                                    auction_window.close();
                                                                    buy_property.close();
                                                                }
                                                            } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                auction_window.close();
                                                                buy_property.close();
                                                            }
                                                            break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj2.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(rr->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }//Final del switch de bEvent.type
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(rr->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                        window.draw(ranura1_button);
                                        window.draw(ranura2_button);
                                        window.draw(ranura3_button);
                                    }//Fin del poolEvent(bEvent)
                                }//Fin del mientras buy_property este abierta
                            } else if (!rr->getAvailable()){
                                if (rr->getOwner() == 2){
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()) {
                                        sf::Event rrEvent;
                                        while (pay_window.pollEvent(rrEvent)) {
                                            switch (rrEvent.type) {
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))){
                                                    pay_window.close();
                                                }
                                                break;
                                            }//Final del switch
                                            text_accept.str("");
                                            text_accept << pj1.getName() << endl << " have to pay $" << (rr->getRent() * rr->getRailroads()) << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(rr->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }//Final del while de pollEvent(rrEvent)
                                    }//Final del while de pay_window.isOpen()
                                    pj1.setMoney(pj1.getMoney() - (rr->getRent() * rr->getRailroads()));
                                    pj2.setMoney(pj2.getMoney() + (rr->getRent() * rr->getRailroads()));
                                }
                            }//Final de las validaciones
                        } else if (SpecialBox* sb = dynamic_cast<SpecialBox*>(board_places[pj1_position])) {
                            switch (sb->getId()){
                                case 2:
                                pj1.setMoney(pj1.getMoney() - sb->getRent());
                                break;
                                case 5:
                                pj1_position = 10;
                                break;
                                case 6:
                                pj1.setMoney(pj1.getMoney() - sb->getRent());
                                break;
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (CommunityChest* cc = dynamic_cast<CommunityChest*>(board_places[pj1_position])){
                            c_window.create(sf::VideoMode(310, 150), "Monopoly");
                            c_window.setPosition(sf::Vector2i(160, 190));
                            while (c_window.isOpen()) {
                                sf::Event cEvent;
                                while (c_window.pollEvent(cEvent)) {
                                    switch (cEvent.type) {
                                        case sf::Event::Closed:
                                        c_window.close();
                                        break;
                                        case sf::Event::MouseButtonPressed:
                                        if (c_accept_button_rect.contains(sf::Mouse::getPosition(c_window))) {
                                            switch(communitychest_cards.front()->getId()){
                                                case 0:
                                                pj1_position = 0;
                                                pj1.setMoney(pj1.getMoney() + 200);
                                                break;
                                                case 1:
                                                pj1.setMoney(pj1.getMoney() + 75);
                                                break;
                                                case 2:
                                                pj1.setMoney(pj1.getMoney() - 50);
                                                break;
                                                case 3:
                                                pj1_position = 10;
                                                break;
                                                case 4:
                                                pj1.setMoney(pj1.getMoney() + 10);
                                                pj2.setMoney(pj2.getMoney() - 10);
                                                break;
                                                case 5:
                                                pj1.setMoney(pj1.getMoney() + 50);
                                                pj2.setMoney(pj2.getMoney() - 50);
                                                break;
                                                case 6:
                                                pj1.setMoney(pj1.getMoney() + 20);
                                                break;
                                                case 7:
                                                pj1.setMoney(pj1.getMoney() + 100);
                                                break;
                                                case 8:
                                                pj1.setMoney(pj1.getMoney() - 100);
                                                break;
                                                case 9:
                                                pj1.setMoney(pj1.getMoney() - 50);
                                                break;
                                                case 10:
                                                pj1.setMoney(pj1.getMoney() + 25);
                                                break;
                                                case 11:
                                                pj1.setMoney(pj1.getMoney() + 10);
                                                break;
                                                case 12:
                                                pj1.setMoney(pj1.getMoney() + 100);
                                                break;
                                                case 13:
                                                pj1.setMoney(pj1.getMoney() + 50);
                                                break;
                                                case 14:
                                                pj1.setMoney(pj1.getMoney() + 100);
                                                break;
                                            }
                                            c_window.close();
                                        }
                                    }//Final del switch
                                }//Final del while pollEvent
                                pj1_image.setPosition(board_positions[pj1_position].x, board_positions[pj1_position].y);
                                c_window.clear(sf::Color::White);
                                c_window.draw(communitychest_cards.front()->getSprite());
                                c_window.draw(c_accept_button);
                                drawMiniProperties(window, mini_pj1, mini_pj2);
                                c_window.display();
                                window.draw(pj1Money);
                                window.draw(pj2Money);
                                window.draw(pj1_image);
                                window.draw(pj2_image);
                                window.draw(ranura1_button);
                                window.draw(ranura2_button);
                                window.draw(ranura3_button);
                            }//Final del while isOpen()
                            communitychest_cards.back() = communitychest_cards.front();
                            for (int i = 1; i < communitychest_cards.size() - 1; i++){
                                communitychest_cards[i - 1] = communitychest_cards[i];
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (Chance* c = dynamic_cast<Chance*>(board_places[pj1_position])){
                            c_window.create(sf::VideoMode(310, 150), "Monopoly");
                            c_window.setPosition(sf::Vector2i(160, 190));
                            while (c_window.isOpen()) {
                                sf::Event cEvent;
                                while (c_window.pollEvent(cEvent)) {
                                    switch (cEvent.type) {
                                        case sf::Event::Closed:
                                        c_window.close();
                                        break;
                                        case sf::Event::MouseButtonPressed:
                                        if (c_accept_button_rect.contains(sf::Mouse::getPosition(c_window))) {
                                            switch(chance_cards.front()->getId()){
                                                case 0:
                                                pj1_position = 0;
                                                pj1.setMoney(pj1.getMoney() + 200);
                                                break;
                                                case 1:
                                                pj1_position = 24;
                                                break;
                                                case 2:
                                                if (pj1_position >= 12  && pj1_position < 27) {
                                                    pj1_position = 28;
                                                } else {
                                                    pj1_position = 12;
                                                }
                                                break;
                                                case 3:
                                                if (pj1_position >= 5 && pj1_position < 14){
                                                    pj1_position = 15;
                                                } else if (pj1_position >= 15 && pj1_position < 24){
                                                    pj1_position = 25;
                                                } else if (pj1_position >= 25 && pj1_position < 34){
                                                    pj1_position = 35;
                                                } else {
                                                    pj1_position = 5;
                                                }
                                                break;
                                                case 4:
                                                if (pj1_position > 11){
                                                    pj1.setMoney(pj1.getMoney() + 200);
                                                    pj1_position = 11;
                                                } else {
                                                    pj1_position = 11;
                                                }
                                                break;
                                                case 5:
                                                pj1.setMoney(pj1.getMoney() + 50);
                                                break;
                                                case 6:
                                                if (pj1_position == 2) {
                                                    pj1_position = 39;
                                                } else {
                                                    pj1_position = pj1_position - 3;
                                                }
                                                break;
                                                case 7:
                                                pj1_position = 10;
                                                break;
                                                case 8:
                                                pj1.setMoney(pj1.getMoney() - 15);
                                                break;
                                                case 9:
                                                pj1_position = 5;
                                                break;
                                                case 10:
                                                pj1_position = 39;
                                                break;
                                                case 11:
                                                break;
                                                case 12:
                                                pj1.setMoney(pj1.getMoney() + 150);
                                                break;
                                                case 13:
                                                pj1.setMoney(pj1.getMoney() + 100);
                                                break;
                                            }
                                            c_window.close();
                                        }
                                    }//Final del switch
                                }//Final del while pollEvent
                                pj1_image.setPosition(board_positions[pj1_position].x, board_positions[pj1_position].y);
                                c_window.clear(sf::Color::White);
                                c_window.draw(chance_cards.front()->getSprite());
                                c_window.draw(c_accept_button);
                                drawMiniProperties(window, mini_pj1, mini_pj2);
                                c_window.display();
                                window.draw(pj1Money);
                                window.draw(pj2Money);
                                window.draw(pj1_image);
                                window.draw(pj2_image);
                                window.draw(ranura1_button);
                                window.draw(ranura2_button);
                                window.draw(ranura3_button);
                            }//Final del while isOpen()
                            chance_cards.back() = chance_cards.front();
                            for (int i = 1; i < chance_cards.size() - 1; i++){
                                chance_cards[i - 1] = chance_cards[i];
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                            //------------------------------------------
                        player_turn = 2;
                            //------------------------------------------
                    //**************************************************************************************************************
                    //--------------------------------------------------------------------------------------------------------------    
                    //**************************************************************************************************************    
                    } else if (player_turn == 2) {
                        if (pj2_position + mov >= 40) {
                            pj2_position = mov - (40 - pj2_position);
                            pj2.setMoney(pj2.getMoney() + 200);
                        } else {
                            pj2_position += mov;
                        }
                        pj2_image.setPosition(board_positions[pj2_position].x, board_positions[pj2_position].y);

                        window.clear(sf::Color::White);
                        window.draw(background);
                        window.draw(pj1Name);
                        window.draw(pj2Name);
                        window.draw(pj1Money);
                        window.draw(pj2Money);
                        window.draw(pj1_image);
                        window.draw(pj2_image);
                        window.draw(dice_image);
                        window.draw(ranura1_button);
                        window.draw(ranura2_button);
                        window.draw(ranura3_button);
                        drawMiniProperties(window, mini_pj1, mini_pj2);
                        window.display();

                        if (NormalProperty* np = dynamic_cast<NormalProperty*>(board_places[pj2_position])) {
                            if (np->getAvailable()) {
                                buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                                buy_property.setPosition(sf::Vector2i(160, 190));
                                while (buy_property.isOpen()) {
                                    sf::Event bEvent;
                                    while (buy_property.pollEvent(bEvent)) {
                                        switch (bEvent.type) {
                                            case sf::Event::Closed:
                                            buy_property.close();
                                            break;
                                            case sf::Event::MouseButtonPressed:
                                            if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                if (pj2.getMoney() > np->getCost()) {
                                                    pj2.setMoney(pj2.getMoney() - np->getCost());
                                                    np->setAvailable(0);
                                                    pj1.setCard(np);
                                                    np->setOwner(2);
                                                    mini_pj2.push_back(pj2_position);
                                                    buy_property.close();
                                                }
                                            } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                                auction_window.setPosition(sf::Vector2i(160, 190));
                                                while (auction_window.isOpen()) {
                                                    sf::Event aEvent;
                                                    while (auction_window.pollEvent(aEvent)) {
                                                        switch (aEvent.type) {
                                                            case sf::Event::Closed:
                                                            auction_window.close();
                                                            buy_property.close();
                                                            break;
                                                            case sf::Event::MouseButtonPressed:
                                                            if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                if (pj1.getMoney() > np->getCost()){
                                                                    pj1.setMoney(pj1.getMoney() - np->getCost());
                                                                    np->setAvailable(0);
                                                                    pj1.setCard(np);
                                                                    np->setOwner(2);
                                                                    mini_pj1.push_back(pj2_position);
                                                                    auction_window.close();
                                                                    buy_property.close();
                                                                }
                                                            } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                auction_window.close();
                                                                buy_property.close();
                                                            }
                                                            break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj1.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(np->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(np->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                    }
                                }    
                            } else if (!np->getAvailable()){
                                if (np->getOwner() == 1){
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()){
                                        sf::Event pEvent;
                                        while (pay_window.pollEvent(pEvent)){
                                            switch (pEvent.type){
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))) {
                                                    pay_window.close();
                                                }
                                                break;
                                            }
                                            text_accept.str("");
                                            text_accept << pj2.getName() << endl << " have to pay $" << np->getRent() << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(np->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }
                                    }
                                    pj2.setMoney(pj2.getMoney() - np->getRent());
                                    pj1.setMoney(pj1.getMoney() + np->getRent());
                                } else if (np->getOwner() == 1) {
                                    if (np->getHouse() < 4) {
                                        house_window.create(sf::VideoMode(400, 228), "Monopoly");
                                        house_window.setPosition(sf::Vector2i(160, 190));
                                        while (house_window.isOpen()) {
                                            sf::Event hEvent;
                                            while (house_window.pollEvent(hEvent)){
                                                switch (hEvent.type) {
                                                    case sf::Event::Closed:
                                                    house_window.close();
                                                    break;
                                                    case sf::Event::MouseButtonPressed:
                                                    if (buy_house_accept_button_rect.contains(sf::Mouse::getPosition(house_window)) && (pj2.getMoney() > np->getHouseCost())) {
                                                        np->addHouses();
                                                        pj2.setMoney(pj2.getMoney() - np->getHouseCost());
                                                        house_window.close();
                                                    } else if (buy_house_cancel_button_rect.contains(sf::Mouse::getPosition(house_window)))
                                                    house_window.close();
                                                    break;
                                                }//Final del switch
                                            }//Final del while
                                            text_accept.str("");
                                            text_accept << "Buy a house?" << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            house_window.clear(sf::Color::White);
                                            house_window.draw(np->getSprite());
                                            house_window.draw(itext);
                                            house_window.draw(buy_house_accept_button);
                                            house_window.draw(buy_house_cancel_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            house_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }//Final del isOpen()
                                    }//Final del la validacion de cant. de casas
                                }
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (Utilities* u = dynamic_cast<Utilities*>(board_places[pj2_position])) {
                            if (u->getAvailable()){
                                buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                                buy_property.setPosition(sf::Vector2i(160, 190));
                                while (buy_property.isOpen()){
                                    sf::Event bEvent;
                                    while (buy_property.pollEvent(bEvent)){
                                        switch (bEvent.type) {
                                            case sf::Event::Closed:
                                            buy_property.close();
                                            break;
                                            case sf::Event::MouseButtonPressed:
                                            if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                if (pj2.getMoney() > u->getCost()) {
                                                    pj2.setMoney(pj2.getMoney() - u->getCost());
                                                    u->setAvailable(0);
                                                    pj2.setCard(u);
                                                    u->setOwner(2);
                                                    u->addCount();
                                                    mini_pj2.push_back(pj2_position);
                                                    buy_property.close();
                                                }
                                            } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                                auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                                auction_window.setPosition(sf::Vector2i(160, 190));
                                                while (auction_window.isOpen()) {
                                                    sf::Event aEvent;
                                                    while (auction_window.pollEvent(aEvent)) {
                                                        switch (aEvent.type) {
                                                            case sf::Event::Closed:
                                                            auction_window.close();
                                                            buy_property.close();
                                                            break;
                                                            case sf::Event::MouseButtonPressed:
                                                            if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                if (pj1.getMoney() > u->getCost()){
                                                                    pj1.setMoney(pj1.getMoney() - u->getCost());
                                                                    u->setAvailable(0);
                                                                    pj1.setCard(u);
                                                                    u->setOwner(2);
                                                                    mini_pj1.push_back(pj2_position);
                                                                    auction_window.close();
                                                                    buy_property.close();
                                                                }
                                                            } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                                auction_window.close();
                                                                buy_property.close();
                                                            }
                                                            break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj1.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(u->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }//Final del switch de bEvent.type
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(u->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                        window.draw(ranura1_button);
                                        window.draw(ranura2_button);
                                        window.draw(ranura3_button);
                                    }//Fin del poolEvent(bEvent)
                                }//Fin del mientras buy_property este abierta
                            } else if (!u->getAvailable()) {
                                if (u->getOwner() == 1) {
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()){
                                        sf::Event pEvent;
                                        while (pay_window.pollEvent(pEvent)){
                                            switch (pEvent.type){
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))) {
                                                    pay_window.close();
                                                }
                                                break;
                                            }
                                            text_accept.str("");
                                            text_accept << pj2.getName() << endl << " have to pay $" << (u->getRent() * u->getCount()) << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(u->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }
                                    }
                                    pj2.setMoney(pj2.getMoney() - (u->getRent() * u->getCount()));
                                    pj1.setMoney(pj1.getMoney() + (u->getRent() * u->getCount()));
                                }
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (RR* rr = dynamic_cast<RR*>(board_places[pj2_position])) {
                         if (rr->getAvailable()){
                            buy_property.create(sf::VideoMode(400, 228), "Monopoly");
                            buy_property.setPosition(sf::Vector2i(160, 190));
                            while (buy_property.isOpen()){
                                sf::Event bEvent;
                                while (buy_property.pollEvent(bEvent)){
                                    switch (bEvent.type) {
                                        case sf::Event::Closed:
                                        buy_property.close();
                                        break;
                                        case sf::Event::MouseButtonPressed:
                                        if (buy_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                            if (pj2.getMoney() > rr->getCost()) {
                                                pj2.setMoney(pj2.getMoney() - rr->getCost());
                                                rr->setAvailable(0);
                                                pj2.setCard(rr);
                                                rr->setOwner(2);
                                                rr->addRailroads();
                                                mini_pj2.push_back(pj2_position);
                                                buy_property.close();
                                            }
                                        } else if (auction_button_rect.contains(sf::Mouse::getPosition(buy_property))) {
                                            auction_window.create(sf::VideoMode(400, 228), "Monopoly");
                                            auction_window.setPosition(sf::Vector2i(160, 190));
                                            while (auction_window.isOpen()) {
                                                sf::Event aEvent;
                                                while (auction_window.pollEvent(aEvent)) {
                                                    switch (aEvent.type) {
                                                        case sf::Event::Closed:
                                                        auction_window.close();
                                                        buy_property.close();
                                                        break;
                                                        case sf::Event::MouseButtonPressed:
                                                        if (auction_accept_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                            if (pj1.getMoney() > rr->getCost()){
                                                                pj1.setMoney(pj1.getMoney() - rr->getCost());
                                                                rr->setAvailable(0);
                                                                pj1.setCard(rr);
                                                                rr->setOwner(2);
                                                                mini_pj1.push_back(pj2_position);
                                                                auction_window.close();
                                                                buy_property.close();
                                                            }
                                                        } else if (auction_cancel_button_rect.contains(sf::Mouse::getPosition(auction_window))) {
                                                            auction_window.close();
                                                            buy_property.close();
                                                        }
                                                        break;
                                                        }//Final del switch
                                                    }//Final del while de pollEvent(aEvent)
                                                    text_accept.str("");
                                                    text_accept << pj1.getName() << endl << "do you  want to buy " 
                                                    << endl << "this property?" << endl;
                                                    sf::Text itext(text_accept.str(), font, 15);
                                                    itext.setPosition(210, 40);
                                                    itext.setColor(sf::Color::Black);
                                                    auction_window.clear(sf::Color::White);
                                                    auction_window.draw(rr->getSprite());
                                                    auction_window.draw(itext);
                                                    auction_window.draw(auction_accept_button);
                                                    auction_window.draw(auction_cancel_button);
                                                    drawMiniProperties(window, mini_pj1, mini_pj2);
                                                    auction_window.display();
                                                    window.draw(ranura1_button);
                                                    window.draw(ranura2_button);
                                                    window.draw(ranura3_button);
                                                }//Final del while de isOpen()
                                            }
                                            break;
                                        }//Final del switch de bEvent.type
                                        buy_property.clear(sf::Color::White);
                                        buy_property.draw(rr->getSprite());
                                        buy_property.draw(buy_button);
                                        buy_property.draw(auction_button);
                                        drawMiniProperties(window, mini_pj1, mini_pj2);
                                        buy_property.display();
                                        window.draw(ranura1_button);
                                        window.draw(ranura2_button);
                                        window.draw(ranura3_button);
                                    }//Fin del poolEvent(bEvent)
                                }//Fin del mientras buy_property este abierta
                            } else if (!rr->getAvailable()){
                                if (rr->getOwner() == 1){
                                    pay_window.create(sf::VideoMode(400, 228), "Monopoly");
                                    pay_window.setPosition(sf::Vector2i(160, 190));
                                    while (pay_window.isOpen()) {
                                        sf::Event rrEvent;
                                        while (pay_window.pollEvent(rrEvent)) {
                                            switch (rrEvent.type) {
                                                case sf::Event::Closed:
                                                pay_window.close();
                                                break;
                                                case sf::Event::MouseButtonPressed:
                                                if (accept_button_rect.contains(sf::Mouse::getPosition(pay_window))){
                                                    pay_window.close();
                                                }
                                                break;
                                            }//Final del switch
                                            text_accept.str("");
                                            text_accept << pj2.getName() << endl << " have to pay $" << (rr->getRent() * rr->getRailroads()) << endl;
                                            sf::Text itext(text_accept.str(), font, 15);
                                            itext.setPosition(235, 40);
                                            itext.setColor(sf::Color::Black);
                                            pay_window.clear(sf::Color::White);
                                            pay_window.draw(itext);
                                            pay_window.draw(rr->getSprite());
                                            pay_window.draw(accept_button);
                                            drawMiniProperties(window, mini_pj1, mini_pj2);
                                            pay_window.display();
                                            window.draw(ranura1_button);
                                            window.draw(ranura2_button);
                                            window.draw(ranura3_button);
                                        }//Final del while de pollEvent(rrEvent)
                                    }//Final del while de pay_window.isOpen()
                                    pj2.setMoney(pj2.getMoney() - (rr->getRent() * rr->getRailroads()));
                                    pj1.setMoney(pj1.getMoney() + (rr->getRent() * rr->getRailroads()));
                                }
                            }//Final de las validaciones
                        } else if (SpecialBox* sb = dynamic_cast<SpecialBox*>(board_places[pj2_position])) {
                            switch (sb->getId()){
                                case 2:
                                pj2.setMoney(pj2.getMoney() - sb->getRent());
                                break;
                                case 5:
                                pj2_position = 10;
                                break;
                                case 6:
                                pj2.setMoney(pj2.getMoney() - sb->getRent());
                                break;
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (CommunityChest* cc = dynamic_cast<CommunityChest*>(board_places[pj2_position])){
                            c_window.create(sf::VideoMode(310, 150), "Monopoly");
                            c_window.setPosition(sf::Vector2i(160, 190));
                            while (c_window.isOpen()) {
                                sf::Event cEvent;
                                while (c_window.pollEvent(cEvent)) {
                                    switch (cEvent.type) {
                                        case sf::Event::Closed:
                                        c_window.close();
                                        break;
                                        case sf::Event::MouseButtonPressed:
                                        if (c_accept_button_rect.contains(sf::Mouse::getPosition(c_window))) {
                                            switch(communitychest_cards.front()->getId()){
                                                case 0:
                                                pj2_position = 0;
                                                pj2.setMoney(pj2.getMoney() + 200);
                                                break;
                                                case 1:
                                                pj2.setMoney(pj2.getMoney() + 75);
                                                break;
                                                case 2:
                                                pj2.setMoney(pj2.getMoney() - 50);
                                                break;
                                                case 3:
                                                pj2_position = 10;
                                                break;
                                                case 4:
                                                pj2.setMoney(pj2.getMoney() + 10);
                                                pj1.setMoney(pj1.getMoney() - 10);
                                                break;
                                                case 5:
                                                pj2.setMoney(pj2.getMoney() + 50);
                                                pj1.setMoney(pj1.getMoney() - 50);
                                                break;
                                                case 6:
                                                pj2.setMoney(pj2.getMoney() + 20);
                                                break;
                                                case 7:
                                                pj2.setMoney(pj2.getMoney() + 100);
                                                break;
                                                case 8:
                                                pj2.setMoney(pj2.getMoney() - 100);
                                                break;
                                                case 9:
                                                pj2.setMoney(pj2.getMoney() - 50);
                                                break;
                                                case 10:
                                                pj2.setMoney(pj2.getMoney() + 25);
                                                break;
                                                case 11:
                                                pj2.setMoney(pj2.getMoney() + 10);
                                                break;
                                                case 12:
                                                pj2.setMoney(pj2.getMoney() + 100);
                                                break;
                                                case 13:
                                                pj2.setMoney(pj2.getMoney() + 50);
                                                break;
                                                case 14:
                                                pj2.setMoney(pj2.getMoney() + 100);
                                                break;
                                            }
                                            c_window.close();
                                        }
                                    }//Final del switch
                                }//Final del while pollEvent
                                pj2_image.setPosition(board_positions[pj2_position].x, board_positions[pj2_position].y);
                                c_window.clear(sf::Color::White);
                                c_window.draw(communitychest_cards.front()->getSprite());
                                c_window.draw(c_accept_button);
                                drawMiniProperties(window, mini_pj1, mini_pj2);
                                c_window.display();
                                window.draw(pj1Money);
                                window.draw(pj2Money);
                                window.draw(pj1_image);
                                window.draw(pj2_image);
                                window.draw(ranura1_button);
                                window.draw(ranura2_button);
                                window.draw(ranura3_button);
                            }//Final del while isOpen()
                            communitychest_cards.back() = communitychest_cards.front();
                            for (int i = 1; i < communitychest_cards.size() - 1; i++){
                                communitychest_cards[i - 1] = communitychest_cards[i];
                            }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        } else if (Chance* c = dynamic_cast<Chance*>(board_places[pj2_position])){
                            c_window.create(sf::VideoMode(310, 150), "Monopoly");
                            c_window.setPosition(sf::Vector2i(160, 190));
                            while (c_window.isOpen()) {
                                sf::Event cEvent;
                                while (c_window.pollEvent(cEvent)) {
                                    switch (cEvent.type) {
                                        case sf::Event::Closed:
                                        c_window.close();
                                        break;
                                        case sf::Event::MouseButtonPressed:
                                        if (c_accept_button_rect.contains(sf::Mouse::getPosition(c_window))) {
                                            switch(chance_cards.front()->getId()){
                                                case 0:
                                                pj2_position = 0;
                                                pj2.setMoney(pj2.getMoney() + 200);
                                                break;
                                                case 1:
                                                pj2_position = 24;
                                                break;
                                                case 2:
                                                if (pj2_position >= 12  && pj2_position < 27) {
                                                    pj2_position = 28;
                                                } else {
                                                    pj2_position = 12;
                                                }
                                                break;
                                                case 3:
                                                if (pj2_position >= 5 && pj2_position < 14){
                                                    pj2_position = 15;
                                                } else if (pj2_position >= 15 && pj2_position < 24){
                                                    pj2_position = 25;
                                                } else if (pj2_position >= 25 && pj2_position < 34){
                                                    pj2_position = 35;
                                                } else {
                                                    pj2_position = 5;
                                                }
                                                break;
                                                case 4:
                                                if (pj2_position > 11){
                                                    pj2.setMoney(pj2.getMoney() + 200);
                                                    pj2_position = 11;
                                                } else {
                                                    pj2_position = 11;
                                                }
                                                break;
                                                case 5:
                                                pj2.setMoney(pj2.getMoney() + 50);
                                                break;
                                                case 6:
                                                if (pj2_position == 2) {
                                                    pj2_position = 39;
                                                } else {
                                                    pj2_position = pj2_position - 3;
                                                }
                                                break;
                                                case 7:
                                                pj2_position = 10;
                                                break;
                                                case 8:
                                                pj2.setMoney(pj2.getMoney() - 15);
                                                break;
                                                case 9:
                                                pj2_position = 5;
                                                break;
                                                case 10:
                                                pj2_position = 39;
                                                break;
                                                case 11:
                                                break;
                                                case 12:
                                                pj2.setMoney(pj2.getMoney() + 150);
                                                break;
                                                case 13:
                                                pj2.setMoney(pj2.getMoney() + 100);
                                                break;
                                            }
                                            c_window.close();
                                        }
                                    }//Final del switch
                                }//Final del while pollEvent
                                pj2_image.setPosition(board_positions[pj2_position].x, board_positions[pj2_position].y);
                                c_window.clear(sf::Color::White);
                                c_window.draw(chance_cards.front()->getSprite());
                                c_window.draw(c_accept_button);
                                drawMiniProperties(window, mini_pj1, mini_pj2);
                                c_window.display();
                                window.draw(pj1Money);
                                window.draw(pj2Money);
                                window.draw(pj1_image);
                                window.draw(pj2_image);
                                window.draw(ranura1_button);
                                window.draw(ranura2_button);
                                window.draw(ranura3_button);
                                chance_cards.back() = chance_cards.front();
                                for (int i = 1; i < chance_cards.size() - 1; i++){
                                    chance_cards[i - 1] = chance_cards[i];
                                }
                            }//Final del while isOpen()
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                        }
                        //------------------------------------------------------------------------------------------------------------
                        //------------------------------------------------------------------------------------------------------------
                            //------------------------------------------
                        player_turn = 1;
                            //------------------------------------------
                    }
                } else if (ranura1_button_rect.contains(sf::Mouse::getPosition(window))) {
                    save_window.create(sf::VideoMode(400, 228), "Monopoly");
                    save_window.setPosition(sf::Vector2i(160, 190));
                    while (save_window.isOpen()) {
                        sf::Event wEvent;
                        while (save_window.pollEvent(wEvent)) {
                            switch(wEvent.type) {
                                case sf::Event::Closed:
                                save_window.close();
                                break;
                                case sf::Event::MouseButtonPressed:
                                if (close_button_rect.contains(sf::Mouse::getPosition(save_window))) {
                                    ofstream output("./resources/ranura1.txt");
                                    output << pj1.getName() << "#" << pj1.getMoney() << "#" << pj1_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl
                                    << pj2.getName() << "#" << pj2.getMoney() << "#" << pj2_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl;
                                    output.close();
                                    save_window.close();
                                }
                                break;
                            }
                            text_accept.str("");
                            text_accept << "The game has been saved!" << endl;
                            sf::Text itext(text_accept.str(), font, 22);
                            itext.setPosition(10, 40);
                            itext.setColor(sf::Color::Black);
                            save_window.clear(sf::Color::White);
                            save_window.draw(itext);
                            save_window.draw(close_button);
                            save_window.display();

                            window.clear(sf::Color::Black);
                            window.draw(background);
                            window.draw(pj1Name);
                            window.draw(pj2Name);
                            window.draw(pj1Money);
                            window.draw(pj2Money);
                            window.draw(pj1_image);
                            window.draw(pj2_image);
                            window.draw(dice_image);
                            window.draw(ranura1_button);
                            window.draw(ranura2_button);
                            window.draw(ranura3_button);
                            drawMiniProperties(window, mini_pj1, mini_pj2);
                            window.display();
                        } 
                    }
                } else if (ranura2_button_rect.contains(sf::Mouse::getPosition(window))) {
                    save_window.create(sf::VideoMode(400, 228), "Monopoly");
                    save_window.setPosition(sf::Vector2i(160, 190));
                    while (save_window.isOpen()) {
                        sf::Event wEvent;
                        while (save_window.pollEvent(wEvent)) {
                            switch(wEvent.type) {
                                case sf::Event::Closed:
                                save_window.close();
                                break;
                                case sf::Event::MouseButtonPressed:
                                if (close_button_rect.contains(sf::Mouse::getPosition(save_window))) {
                                    ofstream output("./resources/ranura1.txt");
                                    output << pj1.getName() << "#" << pj1.getMoney() << "#" << pj1_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl
                                    << pj2.getName() << "#" << pj2.getMoney() << "#" << pj2_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl;
                                    output.close();
                                    save_window.close();
                                }
                                break;
                            }
                            text_accept.str("");
                            text_accept << "The game has been saved!" << endl;
                            sf::Text itext(text_accept.str(), font, 22);
                            itext.setPosition(10, 40);
                            itext.setColor(sf::Color::Black);
                            save_window.clear(sf::Color::White);
                            save_window.draw(itext);
                            save_window.draw(close_button);
                            save_window.display();

                            window.clear(sf::Color::Black);
                            window.draw(background);
                            window.draw(pj1Name);
                            window.draw(pj2Name);
                            window.draw(pj1Money);
                            window.draw(pj2Money);
                            window.draw(pj1_image);
                            window.draw(pj2_image);
                            window.draw(dice_image);
                            window.draw(ranura1_button);
                            window.draw(ranura2_button);
                            window.draw(ranura3_button);
                            drawMiniProperties(window, mini_pj1, mini_pj2);
                            window.display();
                        } 
                    }
                } else if (ranura3_button_rect.contains(sf::Mouse::getPosition(window))) {
                    save_window.create(sf::VideoMode(400, 228), "Monopoly");
                    save_window.setPosition(sf::Vector2i(160, 190));
                    while (save_window.isOpen()) {
                        sf::Event wEvent;
                        while (save_window.pollEvent(wEvent)) {
                            switch(wEvent.type) {
                                case sf::Event::Closed:
                                save_window.close();
                                break;
                                case sf::Event::MouseButtonPressed:
                                if (close_button_rect.contains(sf::Mouse::getPosition(save_window))) {
                                    ofstream output("./resources/ranura1.txt");
                                    output << pj1.getName() << "#" << pj1.getMoney() << "#" << pj1_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl
                                    << pj2.getName() << "#" << pj2.getMoney() << "#" << pj2_position;
                                    for (int i = 0; i < mini_pj1.size(); i++)
                                        output << "#" << mini_pj1[i];
                                    output << endl;
                                    output.close();
                                    save_window.close();
                                }
                                break;
                            }
                            text_accept.str("");
                            text_accept << "The game has been saved!" << endl;
                            sf::Text itext(text_accept.str(), font, 22);
                            itext.setPosition(10, 40);
                            itext.setColor(sf::Color::Black);
                            save_window.clear(sf::Color::White);
                            save_window.draw(itext);
                            save_window.draw(close_button);
                            save_window.display();

                            window.clear(sf::Color::Black);
                            window.draw(background);
                            window.draw(pj1Name);
                            window.draw(pj2Name);
                            window.draw(pj1Money);
                            window.draw(pj2Money);
                            window.draw(pj1_image);
                            window.draw(pj2_image);
                            window.draw(dice_image);
                            window.draw(ranura1_button);
                            window.draw(ranura2_button);
                            window.draw(ranura3_button);
                            drawMiniProperties(window, mini_pj1, mini_pj2);
                            window.display();
                        } 
                    }
                }
                break;
            }  

        }//Final del while interno

        money1.str("");
        money2.str("");
        money1 << "$ " << pj1.getMoney();
        money2 << "$ " << pj2.getMoney();
        pj1Money.setString(money1.str());
        pj2Money.setString(money2.str());

        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(pj1Name);
        window.draw(pj2Name);
        window.draw(pj1Money);
        window.draw(pj2Money);
        window.draw(pj1_image);
        window.draw(pj2_image);
        window.draw(dice_image);
        window.draw(ranura1_button);
        window.draw(ranura2_button);
        window.draw(ranura3_button);
        drawMiniProperties(window, mini_pj1, mini_pj2);
        window.display();

        if (pj1.getMoney() <= 0) {
            winner_window.create(sf::VideoMode(400, 228), "Monopoly");
            winner_window.setPosition(sf::Vector2i(160, 190));
            while (winner_window.isOpen()) {
                sf::Event wEvent;
                while (winner_window.pollEvent(wEvent)) {
                    switch(wEvent.type) {
                        case sf::Event::Closed:
                        winner_window.close();
                        window.close();
                        break;
                        case sf::Event::MouseButtonPressed:
                        if (close_button_rect.contains(sf::Mouse::getPosition(winner_window))) {
                            winner_window.close();
                            window.close();
                        }
                        break;
                    }
                    text_accept.str("");
                    text_accept << pj1.getName() << endl << "ha quedado en bancarota." << endl << endl << pj2.getName() << endl << "es el ganador! Felicitaciones!" << endl;
                    sf::Text itext(text_accept.str(), font, 22);
                    itext.setPosition(10, 40);
                    itext.setColor(sf::Color::Black);
                    winner_window.clear(sf::Color::White);
                    winner_window.draw(itext);
                    winner_window.draw(close_button);
                    winner_window.display();

                    window.clear(sf::Color::Black);
                    window.draw(background);
                    window.draw(pj1Name);
                    window.draw(pj2Name);
                    window.draw(pj1Money);
                    window.draw(pj2Money);
                    window.draw(pj1_image);
                    window.draw(pj2_image);
                    window.draw(dice_image);
                    window.draw(ranura1_button);
                    window.draw(ranura2_button);
                    window.draw(ranura3_button);
                    drawMiniProperties(window, mini_pj1, mini_pj2);
                    window.display();
                } 
            }
        } else if (pj2.getMoney() <= 0) {
            winner_window.create(sf::VideoMode(400, 228), "Monopoly");
            winner_window.setPosition(sf::Vector2i(160, 190));
            while (winner_window.isOpen()) {
                sf::Event wEvent;
                while (winner_window.pollEvent(wEvent)) {
                    switch(wEvent.type) {
                        case sf::Event::Closed:
                        winner_window.close();
                        window.close();
                        break;
                        case sf::Event::MouseButtonPressed:
                        if (close_button_rect.contains(sf::Mouse::getPosition(winner_window))) {
                            winner_window.close();
                            window.close();
                        }
                        break;
                    }
                    text_accept.str("");
                    text_accept << pj2.getName() << endl << "ha quedado en bancarota." << endl << endl << pj1.getName() << endl << "es el ganador! Felicitaciones!" << endl;
                    sf::Text itext(text_accept.str(), font, 22);
                    itext.setPosition(20, 40);
                    itext.setColor(sf::Color::Black);
                    winner_window.clear(sf::Color::White);
                    winner_window.draw(itext);
                    winner_window.draw(close_button);
                    winner_window.display();

                    window.clear(sf::Color::Black);
                    window.draw(background);
                    window.draw(pj1Name);
                    window.draw(pj2Name);
                    window.draw(pj1Money);
                    window.draw(pj2Money);
                    window.draw(pj1_image);
                    window.draw(pj2_image);
                    window.draw(dice_image);
                    window.draw(ranura1_button);
                    window.draw(ranura2_button);
                    window.draw(ranura3_button);
                    drawMiniProperties(window, mini_pj1, mini_pj2);
                    window.display();
                } 
            }
        }

    }
    return 0;
}

void selectorRectangles(){

}

vector<sf::IntRect> vectorCards(int j) {
    sf::IntRect t1(sf::Vector2i(641, 62), sf::Vector2i(18, 23));
    sf::IntRect t2(sf::Vector2i(668, 62), sf::Vector2i(18, 23));
    sf::IntRect t3(sf::Vector2i(708, 62), sf::Vector2i(18, 23));
    sf::IntRect t4(sf::Vector2i(735, 62), sf::Vector2i(18, 23));
    sf::IntRect t5(sf::Vector2i(762, 62), sf::Vector2i(18, 23));
    sf::IntRect t6(sf::Vector2i(627, 89), sf::Vector2i(18, 23));
    sf::IntRect t7(sf::Vector2i(654, 89), sf::Vector2i(18, 23));
    sf::IntRect t8(sf::Vector2i(681, 89), sf::Vector2i(18, 23));
    sf::IntRect t9(sf::Vector2i(708, 89), sf::Vector2i(18, 23));
    sf::IntRect t10(sf::Vector2i(735, 89), sf::Vector2i(18, 23));
    sf::IntRect t11(sf::Vector2i(762, 89), sf::Vector2i(18, 23));
    sf::IntRect t12(sf::Vector2i(627, 117), sf::Vector2i(18, 23));
    sf::IntRect t13(sf::Vector2i(654, 117), sf::Vector2i(18, 23));
    sf::IntRect t14(sf::Vector2i(681, 117), sf::Vector2i(18, 23));
    sf::IntRect t15(sf::Vector2i(708, 117), sf::Vector2i(18, 23));
    sf::IntRect t16(sf::Vector2i(735, 177), sf::Vector2i(18, 23));
    sf::IntRect t17(sf::Vector2i(762, 117), sf::Vector2i(18, 23));
    sf::IntRect t18(sf::Vector2i(627, 145), sf::Vector2i(18, 23));
    sf::IntRect t19(sf::Vector2i(654, 145), sf::Vector2i(18, 23));
    sf::IntRect t20(sf::Vector2i(681, 145), sf::Vector2i(18, 23));
    sf::IntRect t21(sf::Vector2i(722, 145), sf::Vector2i(18, 23));
    sf::IntRect t22(sf::Vector2i(749, 145), sf::Vector2i(18, 23));
    sf::IntRect t23(sf::Vector2i(627, 174), sf::Vector2i(18, 23));
    sf::IntRect t24(sf::Vector2i(654, 174), sf::Vector2i(18, 23));
    sf::IntRect t25(sf::Vector2i(681, 174), sf::Vector2i(18, 23));
    sf::IntRect t26(sf::Vector2i(708, 174), sf::Vector2i(18, 23));
    sf::IntRect t27(sf::Vector2i(735, 174), sf::Vector2i(18, 23));
    sf::IntRect t28(sf::Vector2i(762, 174), sf::Vector2i(18, 23));

    vector<sf::IntRect> cards;
    cards.push_back(t1);
    cards.push_back(t2);
    cards.push_back(t3);
    cards.push_back(t4);
    cards.push_back(t5);
    cards.push_back(t6);
    cards.push_back(t7);
    cards.push_back(t8);
    cards.push_back(t9);
    cards.push_back(t10);
    cards.push_back(t11);
    cards.push_back(t12);
    cards.push_back(t13);
    cards.push_back(t14);
    cards.push_back(t15);
    cards.push_back(t16);
    cards.push_back(t17);
    cards.push_back(t18);
    cards.push_back(t19);
    cards.push_back(t20);
    cards.push_back(t21);
    cards.push_back(t22);
    cards.push_back(t23);
    cards.push_back(t24);
    cards.push_back(t25);
    cards.push_back(t26);
    cards.push_back(t27);
    cards.push_back(t28);

    return cards;
}
vector<sf::Sprite> createSprites(){
    vector<sf::Sprite> places;

    sf::Texture t1;
    t1.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    sf::Sprite s1(t1);
    places.push_back(s1);

    sf::Texture t2;
    t2.loadFromFile("./resources/propiedades/moradas/Baltic_ave.png");
    sf::Sprite s2(t2);
    places.push_back(s2);
    
    sf::Texture t3;
    t3.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s3(t3);
    places.push_back(s3);

    sf::Texture t4;
    t4.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s4(t4);
    places.push_back(s4);

    sf::Texture t5;
    t5.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s5(t5);
    places.push_back(s5);

    sf::Texture t6;
    t6.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s6(t6);
    places.push_back(s6);

    sf::Texture t7;
    t7.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s7(t7);
    places.push_back(s7);

    sf::Texture t8;
    t8.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s8(t8);
    places.push_back(s8);

    sf::Texture t9;
    t9.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s9(t9);
    places.push_back(s9);

    sf::Texture t10;
    t10.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s10(t10);
    places.push_back(s10);

    sf::Texture t11;
    t11.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s11(t11);
    places.push_back(s11);

    sf::Texture t12;
    t12.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s12(t12);
    places.push_back(s12);

    sf::Texture t13;
    t13.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s13(t13);
    places.push_back(s13);

    sf::Texture t14;
    t14.loadFromFile("./resources/propiedades/moradas/Mediterranean_ave.png");
    sf::Sprite s14(t14);
    places.push_back(s14);

    return places;
}

vector<sf::Vector2i> boardPosition(){
    vector<sf::Vector2i> positions;
    positions.push_back(sf::Vector2i(530, 535));
    positions.push_back(sf::Vector2i(484, 550));
    positions.push_back(sf::Vector2i(434, 550));
    positions.push_back(sf::Vector2i(384, 550));
    positions.push_back(sf::Vector2i(334, 550));
    positions.push_back(sf::Vector2i(284, 550));
    positions.push_back(sf::Vector2i(234, 550));
    positions.push_back(sf::Vector2i(184, 550));
    positions.push_back(sf::Vector2i(134, 550));
    positions.push_back(sf::Vector2i(84, 550));
    positions.push_back(sf::Vector2i(18, 550));

    positions.push_back(sf::Vector2i(18, 480));
    positions.push_back(sf::Vector2i(18, 430));
    positions.push_back(sf::Vector2i(18, 380));
    positions.push_back(sf::Vector2i(18, 330));
    positions.push_back(sf::Vector2i(18, 280));
    positions.push_back(sf::Vector2i(18, 230));
    positions.push_back(sf::Vector2i(18, 180));
    positions.push_back(sf::Vector2i(18, 130));
    positions.push_back(sf::Vector2i(18, 80));
    positions.push_back(sf::Vector2i(18, 20));

    positions.push_back(sf::Vector2i(79, 20));
    positions.push_back(sf::Vector2i(129, 20));
    positions.push_back(sf::Vector2i(179, 20));
    positions.push_back(sf::Vector2i(229, 20));
    positions.push_back(sf::Vector2i(279, 20));
    positions.push_back(sf::Vector2i(329, 20));
    positions.push_back(sf::Vector2i(379, 20));
    positions.push_back(sf::Vector2i(429, 20));
    positions.push_back(sf::Vector2i(479, 20));
    positions.push_back(sf::Vector2i(550, 20));

    positions.push_back(sf::Vector2i(550, 80));
    positions.push_back(sf::Vector2i(550, 130));
    positions.push_back(sf::Vector2i(550, 180));
    positions.push_back(sf::Vector2i(550, 230));
    positions.push_back(sf::Vector2i(550, 280));
    positions.push_back(sf::Vector2i(550, 330));
    positions.push_back(sf::Vector2i(550, 380));
    positions.push_back(sf::Vector2i(550, 430));
    positions.push_back(sf::Vector2i(550, 480));

    return positions;
}
void drawMiniProperties(sf::RenderWindow& window, vector<int>& pj1, vector<int>& pj2){
    for (int i = 0; i < pj1.size(); i++){
        if (pj1[i] == 1 || pj1[i] == 3) {
            sf::Vector2f pos = ((pj1[i] == 1) ? sf::Vector2f(641, 62) : sf::Vector2f(668, 62));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-cafe.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 6 || pj1[i] == 8 || pj1[i] == 9) {
            sf::Vector2f pos;
            if (pj1[i] == 6){
                pos = sf::Vector2f(708, 62);
            } else {
                pos = ((pj1[i] == 8) ? sf::Vector2f(735, 62) : sf::Vector2f(762, 62));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-celeste.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 11 || pj1[i] == 13 || pj1[i] == 14) {
            sf::Vector2f pos;
            if (pj1[i] == 11){
                pos = sf::Vector2f(627, 89);
            } else {
                pos = ((pj1[i] == 13) ? sf::Vector2f(654, 89) : sf::Vector2f(681, 89));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-rosa.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 16 || pj1[i] == 18 || pj1[i] == 19) {
            sf::Vector2f pos;
            if (pj1[i] == 16){
                pos = sf::Vector2f(708, 89);
            } else {
                pos = ((pj1[i] == 18) ? sf::Vector2f(735, 89) : sf::Vector2f(762, 89));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-naranja.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 21 || pj1[i] == 23 || pj1[i] == 24) {
            sf::Vector2f pos;
            if (pj1[i] == 21){
                pos = sf::Vector2f(627, 117);
            } else {
                pos = ((pj1[i] == 23) ? sf::Vector2f(654, 117) : sf::Vector2f(681, 117));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad_roja.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 26 || pj1[i] == 27 || pj1[i] == 29) {
            sf::Vector2f pos;
            if (pj1[i] == 26){
                pos = sf::Vector2f(708, 117);
            } else {
                pos = ((pj1[i] == 27) ? sf::Vector2f(735, 177) : sf::Vector2f(762, 117));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-amarillo.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 31 || pj1[i] == 32 || pj1[i] == 34) {
            sf::Vector2f pos;
            if (pj1[i] == 31){
                pos = sf::Vector2f(627, 145);
            } else {
                pos = ((pj1[i] == 32) ? sf::Vector2f(654, 145) : sf::Vector2f(681, 145));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-verde.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 37 || pj1[i] == 39) {
            sf::Vector2f pos = ((pj1[i] == 37) ? sf::Vector2f(722, 145) : sf::Vector2f(749, 145));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-azul.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 12|| pj1[i] == 28) {
            sf::Vector2f pos = ((pj1[i] == 12) ? sf::Vector2f(627, 174) : sf::Vector2f(654, 174));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-utiilities.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        } else if (pj1[i] == 5 || pj1[i] == 15 || pj1[i] == 25 || pj1[i] == 35) {
            sf::Vector2f pos;
            switch (pj1[i]){
                case 5:
                pos = sf::Vector2f(681, 174);
                break;
                case 15:
                pos = sf::Vector2f(708, 174);   
                break;
                case 25:
                pos = sf::Vector2f(735, 174);
                break;
                case 35:
                pos = sf::Vector2f(762, 174);
                break;
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y + 209);
            window.draw(remp);    

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-rr.png");
            sf::Sprite temp(t);
            temp.setPosition(pos);
            window.draw(temp);
        }
    }//Final del for

    for (int i = 0; i < pj2.size(); i++){
        if (pj2[i] == 1 || pj2[i] == 3) {
            sf::Vector2f pos = ((pj2[i] == 1) ? sf::Vector2f(641, 62) : sf::Vector2f(668, 62));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-cafe.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 6 || pj2[i] == 8 || pj2[i] == 9) {
            sf::Vector2f pos;
            if (pj2[i] == 6){
                pos = sf::Vector2f(708, 62);
            } else {
                pos = ((pj2[i] == 8) ? sf::Vector2f(735, 62) : sf::Vector2f(762, 62));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-celeste.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 11 || pj2[i] == 13 || pj2[i] == 14) {
            sf::Vector2f pos;
            if (pj2[i] == 11){
                pos = sf::Vector2f(627, 89);
            } else {
                pos = ((pj2[i] == 13) ? sf::Vector2f(654, 89) : sf::Vector2f(681, 89));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-rosa.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 16 || pj2[i] == 18 || pj2[i] == 19) {
            sf::Vector2f pos;
            if (pj2[i] == 16){
                pos = sf::Vector2f(708, 89);
            } else {
                pos = ((pj2[i] == 18) ? sf::Vector2f(735, 89) : sf::Vector2f(762, 89));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-naranja.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 21 || pj2[i] == 23 || pj2[i] == 24) {
            sf::Vector2f pos;
            if (pj2[i] == 21){
                pos = sf::Vector2f(627, 117);
            } else {
                pos = ((pj2[i] == 23) ? sf::Vector2f(654, 117) : sf::Vector2f(681, 117));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad_roja.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 26 || pj2[i] == 27 || pj2[i] == 29) {
            sf::Vector2f pos;
            if (pj2[i] == 26){
                pos = sf::Vector2f(708, 117);
            } else {
                pos = ((pj2[i] == 27) ? sf::Vector2f(735, 177) : sf::Vector2f(762, 117));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-amarillo.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 31 || pj2[i] == 32 || pj2[i] == 34) {
            sf::Vector2f pos;
            if (pj2[i] == 31){
                pos = sf::Vector2f(627, 145);
            } else {
                pos = ((pj2[i] == 32) ? sf::Vector2f(654, 145) : sf::Vector2f(681, 145));
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-verde.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 37 || pj2[i] == 39) {
            sf::Vector2f pos = ((pj2[i] == 37) ? sf::Vector2f(722, 145) : sf::Vector2f(749, 145));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-azul.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 12|| pj2[i] == 28) {
            sf::Vector2f pos = ((pj2[i] == 12) ? sf::Vector2f(627, 174) : sf::Vector2f(654, 174));
            
            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-utiilities.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        } else if (pj2[i] == 5 || pj2[i] == 15 || pj2[i] == 25 || pj2[i] == 35) {
            sf::Vector2f pos;
            switch (pj2[i]){
                case 5:
                pos = sf::Vector2f(681, 174);
                break;
                case 15:
                pos = sf::Vector2f(708, 174);   
                break;
                case 25:
                pos = sf::Vector2f(735, 174);
                break;
                case 35:
                pos = sf::Vector2f(762, 174);
                break;
            }

            sf::Texture r;
            r.loadFromFile("./resources/propiedad-ocupada.png");
            sf::Sprite remp(r);
            remp.setPosition(pos.x, pos.y);
            window.draw(remp);    

            sf::Texture t;
            t.loadFromFile("./resources/propiedad-rr.png");
            sf::Sprite temp(t);
            temp.setPosition(pos.x, pos.y + 209);
            window.draw(temp);
        }
    }//Final del for
}
void loadMiniProperties(vector<sf::Sprite>& minis){
    sf::Texture t1;
    t1.loadFromFile("./resources/propiedad-cafe.png");
    sf::Sprite s1(t1);
    minis.push_back(s1);

    sf::Texture t2;
    t2.loadFromFile("./resources/propiedad-celeste.png");
    sf::Sprite s2(t2);
    minis.push_back(s2);

    sf::Texture t3;
    t3.loadFromFile("./resources/propiedad-rosa.png");
    sf::Sprite s3(t3);
    minis.push_back(s3);

    sf::Texture t4;
    t4.loadFromFile("./resources/propiedad-naranja.png");
    sf::Sprite s4(t4);
    minis.push_back(s4);

    sf::Texture t5;
    t5.loadFromFile("./resources/propiedad_roja.png");
    sf::Sprite s5(t5);
    minis.push_back(s5);

    sf::Texture t6;
    t6.loadFromFile("./resources/propiedad-amarillo.png");
    sf::Sprite s6(t6);
    minis.push_back(s6);

    sf::Texture t7;
    t7.loadFromFile("./resources/propiedad-verde.png");
    sf::Sprite s7(t7);
    minis.push_back(s7);

    sf::Texture t8;
    t8.loadFromFile("./resources/propiedad-azul.png");
    sf::Sprite s8(t8);
    minis.push_back(s8);

    sf::Texture t9;
    t9.loadFromFile("./resources/propiedad-ocupada.png");
    sf::Sprite s9(t9);
    minis.push_back(s9);
}