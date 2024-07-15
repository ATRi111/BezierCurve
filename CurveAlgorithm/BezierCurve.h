#pragma once
#include"CurveAlgorithm.h"

class BezierCurve : public CurveAlgorithm 
{
	Vector3 Calculate(Vector3* controlPoints, int count, float t) override;
};