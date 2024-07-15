#include "BezierCurve.h"

BezierCurveAlgorithm* BezierCurveAlgorithm::CreateBezierCurveAlgorithm()
{
    return new BezierCurveAlgorithm();
}

Vector2 BezierCurveAlgorithm::Calculate(Vector2* controlPoints, int count, float t)
{
    if (count == 1)
        return *controlPoints;
    if (count == 2)
        return Lerp(controlPoints[0], controlPoints[1], t);

    Vector2* points = new Vector2[count - 1];
    for (int i = 0; i < count - 1; i++)
    {
        points[i] = Lerp(controlPoints[i], controlPoints[i + 1], t);
    }
    Vector2 ret = Calculate(points, count - 1, t);
    delete[] points;
    return ret;
}