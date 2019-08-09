#pragma once
#ifndef RAY_H
#define RAY_H
#include "Wall.h"
#include <vector>
class Ray {
private:
	float m_x;
	float m_y;
	std::vector<float> m_direction;
public:
	Ray(float x, float y, std::vector<float> direction);
	std::vector<float> check(Wall &wall);
};

#endif