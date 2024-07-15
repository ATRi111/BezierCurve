﻿#include "CurveAlgorithm.h"
using namespace std;

#pragma region CurveAlgorithm
TestAnswer* CurveAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	TestCase_Curve* p = dynamic_cast<TestCase_Curve*>(t);
	float currentT = 0;
	float deltaT = 1.0f / p->times;
	Vector2* points = new Vector2[p->times];
	for (int i = 0; i < p->times; i++)
	{
		if (timer)
			timer->Start();
		points[i] = Calculate(p->controlPoints, p->count, currentT);
		if (timer)
			timer->Pause();
		currentT += deltaT;
	}
	return new TestAnswer_Curve(points, p->times);
}
Vector2 CurveAlgorithm::Calculate(Vector2* controlPoints, int count, float t)
{
	return Vector2::Zero;
}
#pragma endregion

#pragma region TestCase_Curve
TestCase_Curve::TestCase_Curve(Vector2* controlPoints, int count,int times)
	:count(count), times(times),controlPoints(controlPoints)
{
}
TestCase_Curve::~TestCase_Curve()
{
	delete[] controlPoints;
}
void TestCase_Curve::Print() const
{
	cout << endl;
	cout << "控制点:";
	for (int i = 0; i < count; i++)
	{
		cout << controlPoints[i] << " ";
	}
	cout << "生成点个数:" << times << endl;
}
#pragma endregion

#pragma region TestAnswer_Curve
bool TestAnswer_Curve::Match(float a, float b)
{
	return abs(a - b) < Epsilon;
}
bool TestAnswer_Curve::Match(Vector2 a, Vector2 b)
{
	return Match(a.x, b.x) && Match(a.y, b.y);
}

TestAnswer_Curve::TestAnswer_Curve(Vector2* points, int count)
	:points(points), count(count)
{

}
TestAnswer_Curve::~TestAnswer_Curve()
{
	delete[] points;
}
bool TestAnswer_Curve::Match(TestAnswer* other) const
{
	TestAnswer_Curve* p = dynamic_cast<TestAnswer_Curve*>(other);
	if (!p || count != p->count)
		return false;
	for (int i = 0; i < count; i++)
	{
		if (!Match(points[i], p->points[i]))
			return false;
	}
	return true;
}
void TestAnswer_Curve::Print() const
{
	for (int i = 0; i < count; i++)
	{
		cout << points[i] << " ";
	}
	cout << endl;
}
#pragma endregion