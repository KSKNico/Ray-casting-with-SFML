#include "Particle.h"


Particle::Particle(float x, float y, int number_of_rays) : m_x{ x }, m_y{ y }, m_number_of_rays{ number_of_rays } {
	m_ray_vector.reserve(m_number_of_rays);
	float rotation_angle = 360.0f / number_of_rays;
	std::vector<float> direction = { 1.0f, 0.0f };
	for (int i = 0; i < number_of_rays; i++) {
		rotateVector(direction, rotation_angle);
		Ray ray(m_x, m_y, direction);
		m_ray_vector.push_back(ray);
	}
}



std::vector<std::vector<float>> Particle::check(std::vector<Wall> &walls) {
	std::vector<std::vector<float>> points;
	std::vector<float> result{ -1.0f, -1.0f };
	for (Ray ray : m_ray_vector) {
		float record = 100000.0f;
		for (Wall wall : walls) {
			std::vector<float> point = ray.check(wall);
			if (point[0] == -1.0f && point[1] == -1.0f) {

			}
			else {
				float distance = Particle::distance(m_x, m_y, point[0], point[1]);
				if (record > distance) {
					record = distance;
					result = point;
				}
			}
		}
		if (result[0] != -1.0f && result[1] != -1.0f) {
			points.push_back(result);
		}
	}
	return points;
}

float const Particle::distance (float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float const Particle::getX() {
	return m_x;
}

float const Particle::getY() {
	return m_y;
}

void const Particle::rotateVector(std::vector<float> &vector, float angle) {
	vector[0] = vector[0] * cos(angle * PI / 180.0f) - vector[1] * sin(angle * PI / 180.0f);
	vector[1] = vector[0] * sin(angle * PI / 180.0f) + vector[1] * cos(angle * PI / 180.0f);
}