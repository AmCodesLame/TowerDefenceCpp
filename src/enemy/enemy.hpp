#pragma once // Include guards to prevent multiple inclusions

#include <SFML/Graphics.hpp>

class Enemy {
public:

    Enemy();
    void draw(sf::RenderWindow& window);
    int getRegion(float x, float y);

    int currRegion;
    float x,y, dx, dy;

    void static setPathR(std::vector<std::vector<int>> path);
    std::vector<std::vector<int>> static pathRegionEnem;

private:
    
    std::vector<sf::Vector2f> points;
    int t;
    int health;

};