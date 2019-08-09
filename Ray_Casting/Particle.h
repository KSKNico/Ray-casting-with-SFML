#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H


#include <vector>
#include "Ray.h"
#include <math.h>
#include <algorithm>

#define PI 3.14159

class Particle {
private:
	float m_x;
	float m_y;
	int m_number_of_rays;
	std::vector<Ray> m_ray_vector;
public:
	Particle(float x, float y, int number_of_rays);
	// Returns the points each ray and wall have in common, only returns the closest point
	std::vector<std::vector<float>> check(std::vector<Wall> &walls);

	float const distance(float x1, float y1, float x2, float y2);

	float const getX();

	float const getY();

	void const rotateVector(std::vector<float> &vector, float angle);
};

#endif