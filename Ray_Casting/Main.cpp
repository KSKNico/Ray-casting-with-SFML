#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Wall.h"
#include "Ray.h"
#include "Drawing.h"
#include <vector>
#include <random>
#include <chrono>

float randomGenerator(size_t min, size_t max) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

	return (float)dist(rng);
}


int main()
{
	int number_of_rays = 100;
	int number_of_walls = 15;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Ray casting", sf::Style::Close);
	// sf::CircleShape shape(400.f);
	
	std::vector<Wall> walls{
		Wall{5.0f, 5.0f, 5.0f, 795.0f},
		Wall{5.0f, 5.0f, 795.0f, 5.0f},
		Wall{5.0f, 795.0f, 795.0f, 795.0f},
		Wall{795.0f, 5.0f, 795.0f, 795.0f},
	};

	for (int i = 0; i < number_of_walls; i++) {
		walls.push_back(Wall{ randomGenerator(10, 795), randomGenerator(10, 795), 
			randomGenerator(10, 795), randomGenerator(10, 795) });
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2i position = sf::Mouse::getPosition(window);
		Particle particle{ (float)position.x, (float)position.y,  number_of_rays};

		window.clear();
		drawWalls(window, walls);
		drawScene(window, particle, walls);

		window.display();
	}

	return 0;
}

