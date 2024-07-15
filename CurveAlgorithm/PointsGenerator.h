#pragma once
#include"Vector3.h"
#include<vector>
#include<random>

class PointsGenerator
{
public:
	static std::mt19937 engine;
	static void Generate(Vector3* controlPoints, int count, float xMin, float xMax,float yMin,float yMax);
};

class PointComparer
{
public:
	double static ToAngle(Vector3 v);

	Vector3 center;

	PointComparer(Vector3 center);
	bool Compare(Vector3 a, Vector3 b) const;
};