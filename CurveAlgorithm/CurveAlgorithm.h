#pragma once
#include"Testframework.h"
#include"Vector2.h"

class CurveAlgorithm : public Algorithm
{
public:
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual Vector2 Calculate(Vector2* controlPoints, int count, float t);
};

struct TestCase_Curve : TestCase
{
	Vector2* controlPoints;
	int count;
	int times;
	//this class takes ownership of controlPoints(shallow copy)
	TestCase_Curve(Vector2* controlPoints, int count, int times);
	~TestCase_Curve();

	void Print() const override;
};

struct TestAnswer_Curve : TestAnswer
{
	static const float Epsilon;
	bool static Match(float a, float b);
	bool static Match(Vector2 a, Vector2 b);
	Vector2* points;
	int count;

	//this class takes ownership of controlPoints(shallow copy)
	TestAnswer_Curve(Vector2* points, int count);
	~TestAnswer_Curve();
	bool Match(TestAnswer* other) const override;
	void Print() const override;
};

class TestSerializer_Curve : public TestSerializer
{
public:
	virtual void Serialize(std::ofstream& stream, const TestSet& set) const override;
	virtual TestSet Deserialize(std::ifstream& stream) const override;
};