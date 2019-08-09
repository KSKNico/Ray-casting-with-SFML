#include "Drawing.h"

void drawWall(sf::RenderWindow &window, Wall &wall) {
	sf::Vertex vertices[2] = {
		sf::Vertex(sf::Vector2f(wall.m_x1, wall.m_y1), sf::Color::White),
		sf::Vertex(sf::Vector2f(wall.m_x2, wall.m_y2), sf::Color::White)
	};
	window.draw(vertices, 2, sf::Lines);
}
void drawWalls(sf::RenderWindow &window, std::vector<Wall> &walls) {
	for (Wall wall : walls) {
		drawWall(window, wall);
	}
}

void drawScene(sf::RenderWindow &window, Particle &particle, std::vector<Wall> &walls) {
	drawWalls(window, walls);
	std::vector<std::vector<float>> points = particle.check(walls);
	float x = particle.getX();
	float y = particle.getY();
	for (std::vector<float> point : points) {
		sf::Vertex vertices[2] = {
			sf::Vertex(sf::Vector2f(x, y), sf::Color::White),
			sf::Vertex(sf::Vector2f(point[0], point[1]), sf::Color::White)
		};
		window.draw(vertices, 2, sf::Lines);
	}
}