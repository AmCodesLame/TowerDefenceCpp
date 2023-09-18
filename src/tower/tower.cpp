#include <iostream>
#include "tower.hpp"
#include <cmath>


float dist(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

Tower::Tower(){
    x=730; y=960;
}

void Tower::sendCoordinates(std::vector<std::vector<float>> coord){
    enemyCoordinatesEn = coord;
}

void Tower::getClosestEnemy(){
    if(enemyCoordinatesEn.size()>0){
        pointToEnemyIndex=0;
        int iteration=0;
        float minDist=dist(x,y,enemyCoordinatesEn[0][0], enemyCoordinatesEn[0][1]);
        for(auto i:enemyCoordinatesEn){
            float currDist = dist(x,y,i[0],i[1]);
            // std::cout<<"i: "<<i[0]<<" "<<i[1]<<std::endl;
            if (currDist < minDist){
                minDist = currDist;
                pointToEnemyIndex=iteration;
                closestEnemyX = i[0];
                closestEnemyY = i[1];
            };
            iteration++;
        }
    }
}

float Tower::getAngle(){
    float angleRadians = std::atan2(y-closestEnemyY, x-closestEnemyX);
    float angleDegrees = angleRadians * 180.0 / M_PI;
    return angleDegrees;
}

void Tower::draw(sf::RenderWindow& window) {

    // std::cout<<"closest coords: "<<closestEnemyX<<" "<<closestEnemyY<<std::endl;

    

    sf::Vector2u windowSize = window.getSize(); 
    sf::RectangleShape tower(sf::Vector2f(64,64));
    sf::Texture towerTexture;
    towerTexture.loadFromFile("tower32.png");
    tower.setTexture(&towerTexture);
    tower.setPosition(x,y);
    tower.setOrigin(32.0f,32.0f);



    rotationAngle = getAngle();
    // std::cout<<"angle: "<<rotationAngle<<std::endl;
    tower.setRotation(180-rotationAngle);

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    distFromMouse = dist(x,y,mousePosition.x,mousePosition.y);
    bool clicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    if(distFromMouse<10 && clicked && !purchased){
        x = mousePosition.x;
        y=mousePosition.y;
        touched=true;
    }
    if(touched && !(distFromMouse<10 && clicked)) purchased=true;


    window.draw(tower);

}