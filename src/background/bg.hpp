#pragma once // Include guards to prevent multiple inclusions

#include <SFML/Graphics.hpp>

class Background {
public:
    Background();
    void draw(sf::RenderWindow& window);
    void drawPath(sf::RenderWindow& window);
    void updateBgPos();
    std::vector<std::vector<int>> getPathRegion();
    void init();
    void drawInventory(sf::RenderWindow& window);

private:
    std::vector<std::vector<int>> pathRegion;
    sf::Texture inventoryTexture;
    sf::Sprite inventorySprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RectangleShape backgroundRect;
    sf::Texture pathTexture;
    sf::Sprite pathSprite;
    sf::RenderTexture renderTexture;
    sf::Vector2f bgpos = sf::Vector2f(0,0);

};