#define _USE_MATH_DEFINES
#include "PointsGenerator.h"
#include<chrono>
#include<unordered_set>
using namespace std;

mt19937 PointsGenerator::engine(std::chrono::system_clock::now().time_since_epoch().count());

void PointsGenerator::Generate(Vector2* controlPoints, int count, float xMin, float xMax, float yMin, float yMax)
{
	unordered_set<Vector2> temp;
	Vector2 center((xMin + xMax) / 2, (yMin + yMax) / 2);
	uniform_real_distribution<float> dx(xMin, xMax);
	uniform_real_distribution<float> dy(yMin, yMax);

	PointComparer comparer(center);
	for (int i = 0; i < count; i++)
	{
		Vector2 v(dx(engine), dy(engine));
		if (v == center || temp.count(v))
			i--;
		else
			temp.insert(v);
	}

	int i = 0;
	for (Vector2 v : temp)
	{
		controlPoints[i] = v;
		i++;
	}
	sort(controlPoints, controlPoints + i,
		[&comparer](const Vector2& a, const Vector2& b) {return comparer.Compare(a, b); });
}

double PointComparer::ToAngle(Vector2 v)
{
	double angle = -atan2(v.x, v.y);
	double _2Pi = 2 * M_PI;
	angle += _2Pi;
	int i = (int)(angle / _2Pi);
	angle -= i * _2Pi;
	return angle;
}

PointComparer::PointComparer(Vector2 center)
	:center(center)
{

}

bool PointComparer::Compare(Vector2 a, Vector2 b) const
{
	double aa = ToAngle(a - center);
	double ab = ToAngle(b - center);
	return aa < ab;
}