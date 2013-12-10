#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "player.h"
#include "board.h"
#include "propertycard.h"
using namespace std;

vector<sf::IntRect> vectorCards(int j);
void selectorRectangles();
vector<sf::Sprite> createSprites();

int main (int argc, char * argv[]) {
    sf::RenderWindow window;
    sf::RenderWindow player_selector;

    Board board;
    vector<PropertyCard> board_places = board.getPlaces();
    vector<sf::Sprite> board_sprites = createSprites();
    cout << "El length es " << board_sprites.size() << endl;

    sf::RenderWindow info_window;
    sf::Texture info_image;
    info_window.create(sf::VideoMode(200, 228), "Information", sf::Style::None);
    info_window.setPosition(sf::Vector2i(260, 245));
    info_window.setVisible(false);
    info_image.loadFromFile("./resources/propiedades/amarillas/atlantic_ave.png");
    sf::Sprite info(info_image);
    info.setPosition(0, 0);

    sf::Texture selector_image;
    if (!selector_image.loadFromFile("./resources/monopoly_tokens_original.png"))
        return EXIT_FAILURE;
    sf::Sprite selector(selector_image);

    // player_selector.create(sf::VideoMode(800, 610), "Monopoly");
    // player_selector.setPosition(sf::Vector2i(0, 0));
    // while (player_selector.isOpen()) {
    //     sf::Event Event;

    //     while (player_selector.pollEvent(Event)) {

    //         switch (Event.type) {
    //             case sf::Event::Closed:
    //                 player_selector.close();
    //                 break;
    //         }
    //         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    //             selector.setPosition(selector.getPosition().x, selector.getPosition().y + 10);
    //         } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    //             selector.setPosition(selector.getPosition().x, selector.getPosition().y - 10);
    //         } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    //             selector.setPosition(selector.getPosition().x - 10, selector.getPosition().y);
    //         } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    //             selector.setPosition(selector.getPosition().x + 10, selector.getPosition().y);
    //         }

    //         player_selector.clear(sf::Color::Black);
    //         player_selector.draw(selector);
    //         player_selector.display();
    //     }
    // }    

    //************************************************************************************************************
    //Creo lo referente a los dos jugadores
    //Pido los nombres de los jugadores
    std::string name1;
    std::string name2;
    std::cout << "Ingrese el nombre del primer jugador:" << std::endl;
    std::cin >> name1;
    std::cout << endl;
    std::cout << "Ingrese el nombre del segundo jugador:" << std::endl;
    std::cin >> name2;
    std::cout << endl;

    //Creacion de la fuente para los textos desplegados
    sf::Font font;
    if(!font.loadFromFile("./resources/Action Man.ttf")) {
        std::cout << "No encontre el font!" << std::endl;
    }

    Player pj1(name1, 1);
    Player pj2(name2, 2);

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

    sf::Text pj1Money(money1.str(), font, 15);
    sf::Text pj2Money(money2.str(), font, 15);
    pj1Money.setPosition(635, 30);
    pj2Money.setPosition(635, 240);
    pj1Money.setColor(sf::Color(0, 255, 0));
    pj2Money.setColor(sf::Color(0, 255, 0));
    pj1Money.setStyle(sf::Text::Bold);
    pj2Money.setStyle(sf::Text::Bold);
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

    // sf::RectangleShape cuadrado;
    // cuadrado.setSize(sf::Vector2f(120.f, 120.f));
    // cuadrado.setFillColor(sf::Color::White);
    // sf::IntRect cuadro(cuadrado.getPosition().x, cuadrado.getPosition().y, cuadrado.getSize().x, cuadrado.getSize().y);
    sf::Texture dice_background;
    dice_background.loadFromFile("./resources/dados.png");
    sf::Sprite dice_image(dice_background);
    sf::RectangleShape diceCuadrado;
    diceCuadrado.setFillColor(sf::Color::White);
    sf::IntRect dice_rect();

    //---------------------------------------------------------------------
    int auxiliar = 0;
    int cardIndex = 0;
    //---------------------------------------------------------------------
    while (window.isOpen()) {
        sf::Event Event;

        while (window.pollEvent(Event)) {

            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    cardIndex = board.compare(window, info_window, auxiliar);
                    cout << "cardIndex es " << cardIndex << endl; 
                    if (cardIndex != -1){
                        info_window.setPosition(sf::Vector2i(260, 245));
                        info_window.setVisible(true);
                        info_window.clear(sf::Color::White);
                        info_window.draw(board_places[cardIndex].getSprite());
                        cout << endl;
                        info_window.display();
                    } else {
                        info_window.setVisible(false);
                    }
                    break;
            }  

        }//Final del while interno

        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(pj1Name);
        window.draw(pj2Name);
        window.draw(pj1Money);
        window.draw(pj2Money);
        window.draw(diceCuadrado);
        window.display();
    }
    return 0;
}

void selectorRectangles(){
    
}

vector<sf::IntRect> vectorCards(int j)
{
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