#pragma once
#include"Testframework.h"
#include"Vector3.h"
#include"Curve.h"
#include<random>

std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distrbution(5, 9);

TestCase_Curve* GenerateTestCase()
{
	int count = distrbution(engine);
	int times = distrbution(engine);
	Vector3* controlPoints = new Vector3[count];
	PointsGenerator::Generate(controlPoints, count, -10, 10, -10, 10);
	return new TestCase_Curve(controlPoints, count, times);
}