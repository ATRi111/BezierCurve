#include "BezierCurve.h"

Vector3 BezierCurve::Calculate(Vector3* controlPoints, int count, float t)
{
    if (count == 1)
        return *controlPoints;
    if (count == 2)
        return Lerp(controlPoints[0], controlPoints[1], t);

    Vector3* points = new Vector3[count - 1];
    for (int i = 0; i < count - 1; i++)
    {
        points[i] = Lerp(controlPoints[i], controlPoints[i + 1], t);
    }
    Vector3 ret = Calculate(points, count - 1, t);
    delete[] points;
    return ret;
}