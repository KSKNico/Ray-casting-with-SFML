#pragma once
#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "Wall.h"
#include "Ray.h"
#include "Particle.h"
#include <SFML/Graphics.hpp>

void drawWall(sf::RenderWindow &window, Wall &wall);
void drawWalls(sf::RenderWindow &window, std::vector<Wall> &walls);
//void drawRay(sf::RenderWindow &window, Ray &ray);
//void drawParticle(sf::RenderWindow &window, Particle &particle);
void drawScene(sf::RenderWindow &window, Particle &particle, std::vector<Wall> &walls);

#endif