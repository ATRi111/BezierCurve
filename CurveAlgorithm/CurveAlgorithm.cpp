#include "CurveAlgorithm.h"
#include<iomanip>
#include<string>
using namespace std;

#pragma region CurveAlgorithm
TestAnswer* CurveAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	TestCase_Curve* p = dynamic_cast<TestCase_Curve*>(t);
	float currentT = 0;
	float deltaT = 1.0f / (p->times - 1);
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
	for (int i = 0; i < count; i++)
	{
		cout << fixed << setprecision(2) << controlPoints[i] << " ";
	}
	cout << endl;
	cout << "要求均匀生成" << times << "个点" << endl;
}
#pragma endregion

#pragma region TestAnswer_Curve
const float TestAnswer_Curve::Epsilon = 0.01f;

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
		cout << fixed << setprecision(2) << points[i] << " ";
	}
	cout << endl;
}
#pragma endregion

#pragma region TestSerializer_Curve
void TestSerializer_Curve::Serialize(std::ofstream& stream, const TestSet& set) const
{
	for (int i = 0; i < set.cases.size(); i++)
	{
		TestCase_Curve* c = dynamic_cast<TestCase_Curve*>(set.cases[i]);
		TestAnswer_Curve* a = dynamic_cast<TestAnswer_Curve*>(set.answers[i]);
		if (c && a)
		{
			stream << c->count << " ";
			for (int i = 0; i < c->count; i++)
			{
				stream << c->controlPoints[i] << " ";
			}
			stream << c->times << " ";
			for (int i = 0; i < a->count; i++)
			{
				stream << a->points[i] << " ";
			}
			stream << endl;
		}
	}
}

TestSet TestSerializer_Curve::Deserialize(std::ifstream& stream) const
{
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	string s;
	while (getline(stream, s))
	{
		int count, times;
		Vector2* controlPoints;
		Vector2* points;
		vector<string> ss = Split(s, ' ');
		int i = 0;

		count = stoi(ss[i]);
		i++;
		controlPoints = new Vector2[count];
		for (int j = 0; j < count; j++)
		{
			controlPoints[j] = Vector2::FromString(ss[i]);
			i++;
		}
		times = stoi(ss[i]);
		i++;
		cases.emplace_back(new TestCase_Curve(controlPoints, count, times));

		points = new Vector2[times];
		for (int j = 0; j < times; j++)
		{
			points[j] = Vector2::FromString(ss[i]);
			i++;
		}
		answers.emplace_back(new TestAnswer_Curve(points, times));
	}
	return TestSet(cases, answers, Algorithm::CreateDefault);
}
#pragma endregion