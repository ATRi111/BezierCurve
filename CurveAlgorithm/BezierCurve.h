#pragma once
#include"CurveAlgorithm.h"

class BezierCurveAlgorithm : public CurveAlgorithm 
{
public:
	static BezierCurveAlgorithm* CreateBezierCurveAlgorithm();
	Vector3 Calculate(Vector3* controlPoints, int count, float t) override;
};