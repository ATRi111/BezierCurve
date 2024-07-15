#pragma once
#include"CurveAlgorithm.h"

class BezierCurveAlgorithm : public CurveAlgorithm 
{
public:
	static BezierCurveAlgorithm* CreateBezierCurveAlgorithm();
	Vector2 Calculate(Vector2* controlPoints, int count, float t) override;
};