#include "Ray.h"
Ray::Ray(float x, float y, std::vector<float> direction) : m_x{ x }, m_y{ y }, m_direction{ direction } {}

std::vector<float> Ray::check(Wall &wall) {
	float x_dir = m_x + m_direction[0];
	float y_dir = m_y + m_direction[1];
	float den = (m_x - x_dir)*(wall.m_y1 - wall.m_y2) - (m_y - y_dir)*(wall.m_x1 - wall.m_x2);
	if (den == 0) {
		return std::vector<float> {-1.0f, -1.0f};
	}
	float t = ((m_x - wall.m_x1) * (wall.m_y1 - wall.m_y2) - (m_y - wall.m_y1) * (wall.m_x1 - wall.m_x2))/den;
	float u = -((m_x - x_dir) * (m_y - wall.m_y1) - (m_y - y_dir) * (m_x - wall.m_x1))/den;

	if (t >= 0 && u <= 1 && u >= 0) {
		return std::vector<float> {
			m_x+t*(x_dir - m_x), 
			m_y+t*(y_dir - m_y)
		};
	}
	else 
	{
		return std::vector<float> {-1.0f, -1.0f};
	}
}