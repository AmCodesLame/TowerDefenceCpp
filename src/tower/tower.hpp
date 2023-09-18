#pragma once // Include guards to prevent multiple inclusions

#include <SFML/Graphics.hpp>

class Tower {
public:
    Tower();
    void draw(sf::RenderWindow& window);
    int getRegion(float x, float y);
    void sendCoordinates(std::vector<std::vector<float>> coord);
    void getClosestEnemy();

    int currRegion;
    float x,y, dx, dy;
    float distFromMouse;
    float rotationAngle;

    

private:
    
    float getAngle();


    std::vector<std::vector<float>>enemyCoordinatesEn;
    std::vector<std::vector<int>> pathRegionEnem;
    std::vector<sf::Vector2f> points;
    int t;
    bool isSelected;    
    bool purchased=false;
    bool touched = false;
    int pointToEnemyIndex=0;
    int closestEnemyX, closestEnemyY;


};