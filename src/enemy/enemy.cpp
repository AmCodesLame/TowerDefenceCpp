#include <iostream>
#include "enemy.hpp"
#include <cmath>

void Enemy::setPathR(std::vector<std::vector<int>> path){
    pathRegionEnem = path;
}



Enemy::Enemy(){
    x=10.0f; y=216.0;
    t=0;
    health=5;
    points = {
        {464,216}, 
        {464,792},
        {1680,792},
        {1680,408},
        {976,408},
        {976,88},
        {2047,88}
    };
}

int Enemy::getRegion(float x, float y){
    int reg=0;
    for(auto i: pathRegionEnem){
        if(x>=i[0] && x<i[2] && y>=i[1] && y<i[3]){
            return reg;
        }
        reg++;
    }
    return -1;
}

float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

void Enemy::draw(sf::RenderWindow& window) {


    sf::RectangleShape enemy(sf::Vector2f(32.0f,32.0f));
    


    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


    
    sf::Vector2f currpos = enemy.getPosition();
    float dist =  distance(x,y,points[t].x, points[t].y);
    if ((int)x!=points[t].x || (int)y!=points[t].y) {
        sf::Vector2f direction;
        direction.x = points[t].x - x;
        direction.y=points[t].y-y;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction = direction / length;
        
        dx = direction.x / 20.0f;
        dy = direction.y / 20.0f;

        if(dist<0.5) t++;

    }

    x =x+dx;
    y =(y + dy);

    enemy.setPosition(x,y);

    sf::Vector2u windowSize = window.getSize(); 

    window.draw(enemy);
    
}

