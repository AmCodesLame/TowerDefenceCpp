// Background.cpp
#include <iostream>
#include "bg.hpp"

Background::Background(){

    backgroundRect.setFillColor(sf::Color::Blue);
    backgroundTexture.loadFromFile("grasstile128.jpg");
    backgroundTexture.setRepeated(true);

    backgroundSprite.setTexture(backgroundTexture);
    inventoryTexture.loadFromFile("inventory128.png");
    inventorySprite.setTexture(inventoryTexture);
    inventorySprite.setPosition(630,900);

    

    pathTexture.loadFromFile("wooden64.jpg");
    sf::Vector2u pathTextureSize = pathTexture.getSize();
    int pathx= (int)pathTextureSize.x;
    int pathy= (int)pathTextureSize.y;


    std::vector<int> region1 = {0,200,512-pathx,264}; // x1,y1,x2,y2
    std::vector<int> region2 = {512-pathx,200,512,840-pathy}; // x1,y1,x2,y2
    std::vector<int> region3 = {512-pathx,840-pathy,1728-pathx,840}; // x1,y1,x2,y2

    std::vector<int> region4 = {1728-pathx,456,1728,840}; // x1,y1,x2,y2
    std::vector<int> region5 = {960+pathx,456-pathy,1728, 456}; // x1,y1,x2,y2
    std::vector<int> region6 = {960,136,960+pathx, 456}; // x1,y1,x2,y2
    std::vector<int> region7 = {960,136-pathy,2024, 136}; // x1,y1,x2,y2

    pathRegion.push_back(region1);
    pathRegion.push_back(region2);
    pathRegion.push_back(region3);
    pathRegion.push_back(region4);
    pathRegion.push_back(region5);
    pathRegion.push_back(region6);
    pathRegion.push_back(region7);
}

void Background::drawPath(sf::RenderWindow& window){
    renderTexture.create(window.getSize().x, window.getSize().y);
    renderTexture.clear(sf::Color::Transparent);

    for(int i=0; i<pathRegion.size(); ++i){
        for (float x = pathRegion[i][0]; x < pathRegion[i][2]; x += pathTexture.getSize().x) {
            for (float y = pathRegion[i][1]; y < pathRegion[i][3]; y += pathTexture.getSize().y) {
                sf::Sprite tile(pathTexture);
                tile.setPosition(x, y);
                renderTexture.draw(tile);
            }
        }
    }
    


}


void Background::draw(sf::RenderWindow& window) {

    sf::Vector2u windowSize = window.getSize(); 
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));




    

    drawPath(window);
    if (backgroundTexture.getSize().x > 0 && backgroundTexture.getSize().y > 0) {
        window.draw(backgroundSprite);
        // window.draw(pathSprite);
        renderTexture.display();
        sf::Sprite filledRegion(renderTexture.getTexture());
        window.draw(filledRegion);
        window.draw(inventorySprite);

        

    } else {
        window.draw(backgroundRect);
    }
}



std::vector<std::vector<int>> Background::getPathRegion(){
    return pathRegion;
}