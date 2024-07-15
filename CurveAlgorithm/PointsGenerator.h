#pragma once
#include"Vector2.h"
#include<vector>
#include<random>

class PointsGenerator
{
public:
	static std::mt19937 engine;
	static void Generate(Vector2* controlPoints, int count, float xMin, float xMax,float yMin,float yMax);
};

class PointComparer
{
public:
	double static ToAngle(Vector2 v);

	Vector2 center;

	PointComparer(Vector2 center);
	bool Compare(Vector2 a, Vector2 b) const;
};