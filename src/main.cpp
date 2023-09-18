#include <SFML/Graphics.hpp>
#include <sstream> // For string manipulation
#include <iostream>
#include "background/bg.hpp"
#include "enemy/enemy.hpp"
#include "tower/tower.hpp"
#include <random>


Background bg;
std::vector<std::vector<int>> pathR = bg.getPathRegion();
std::vector<std::vector<int>> Enemy::pathRegionEnem = pathR;

int main(){

    std::vector<std::vector<float>> enemyCoordinates {0};
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "test window");

    // Enemy::setPathR(pathR);
    Enemy en[10];
    Tower to;



    sf::Font font;
    font.loadFromFile("arial/arial_bold.ttf");


    sf::Text text;
    text.setFont(font);          // Set the font
    text.setCharacterSize(24);   // Set the character size (in pixels)
    text.setFillColor(sf::Color::Red); // Set the text color
    text.setPosition(100, 100); // Set the text's position (x, y)


    for(auto i:pathR){
        std::cout<<"Region: ";
        for(int j=0; j<i.size(); ++j){
            std::cout<<i[j]<<" ";
        }
        std::cout<<std::endl;
    }

    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    sf::Time elapsedTime2 = sf::Time::Zero;
    int enemyCount=0;
    float randTime = 1 + rand() % (10);

    to.sendCoordinates(enemyCoordinates);
    while (window.isOpen()){



        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Get the mouse position
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);





        // Measure elapsed time since the last action
        
        sf::Time interval = sf::seconds(randTime); 
        sf::Time frameTime = clock.restart();
        elapsedTime += frameTime;
        elapsedTime2 += frameTime;

        if(elapsedTime2>=sf::seconds(1.0f)){
            to.getClosestEnemy();
            to.sendCoordinates(enemyCoordinates);
        }
        // Check if the desired interval has passed
        if (elapsedTime >= interval) {
            // Perform your action here
            enemyCount = std::min(enemyCount+1, 10);
            randTime = 2 + rand() % (6);

            // Reset the elapsed time
            elapsedTime = sf::Time::Zero;
        }




        std::stringstream ss;
        ss << "X: " << mousePosition.x << " | Y: " << mousePosition.y<<"| angle: "<<to.rotationAngle<<" | dx: "<<en[0].dx <<" | dy: "<<en[0].dy;
        text.setString(ss.str());

        window.clear();
        // window.draw(shape);
        bg.draw(window);
        for(int i=0; i<enemyCount; i++){
            en[i].draw(window);
            std::vector<float> coord =  {en[i].x, en[i].y};
            enemyCoordinates.push_back(coord);
        }
        to.draw(window);

        window.draw(text);

        window.display();
    }

}