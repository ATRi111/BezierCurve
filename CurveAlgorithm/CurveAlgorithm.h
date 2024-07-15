#pragma once
#include"Testframework.h"
#include"Vector3.h"

class CurveAlgorithm : public Algorithm
{
public:
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual Vector3 Calculate(Vector3* controlPoints, int count, float t);
};

struct TestCase_Curve : TestCase
{
	Vector3* controlPoints;
	int count;
	int times;
	//this class takes ownership of controlPoints(shallow copy)
	TestCase_Curve(Vector3* controlPoints, int count, int times);
	~TestCase_Curve();

	void Print() const override;
};

struct TestAnswer_Curve : TestAnswer
{
	static const float Epsilon;
	bool static Match(float a, float b);
	bool static Match(Vector3 a, Vector3 b);
	Vector3* points;
	int count;

	//this class takes ownership of controlPoints(shallow copy)
	TestAnswer_Curve(Vector3* points, int count);
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