#pragma once
#include"Testframework.h"
#include"Vector2.h"
#include"Curve.h"
#include<random>

std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distrbution(5, 8);

TestCase_Curve* GenerateTestCase()
{
	int count = distrbution(engine);
	int times = distrbution(engine);
	Vector2* controlPoints = new Vector2[count];
	PointsGenerator::Generate(controlPoints, count, -10, 10, -10, 10);
	return new TestCase_Curve(controlPoints, count, times);
}

void Test(std::string path, int times, int printTimes, const std::function<Algorithm* ()>& CreateSolution, bool guarenteed = false)
{
	TestSerializer_Curve serializer;
	TestSet set = TestSet(serializer.DeserializeFrom(path));
	set.CreateSolution = CreateSolution;

	set.AccuracyTest(printTimes, guarenteed);
	set.TimeTest(times);

	set.DeleteAnswers();
	set.DeleteCases();
	std::cout << std::endl;
}

void TestBezierCurveAlgorithm(std::string path, int times)
{
	std::cout << "贝塞尔曲线:" << std::endl;
	Test(path, times, 0, BezierCurveAlgorithm::CreateBezierCurveAlgorithm, true);
}

//调用此函数会导致存放答案的文件被修改
void GenerateAnswers(std::string path)
{
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	for (int i = 0; i < 100; i++)
	{
		cases.push_back(GenerateTestCase());
	}
	TestSet set(cases, answers, BezierCurveAlgorithm::CreateBezierCurveAlgorithm);
	set.GenerateAnswers();
	TestSerializer_Curve s;
	s.SerializeTo(path, set);
}