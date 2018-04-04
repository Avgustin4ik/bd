#pragma once
#include "BezierCurve.h"
#include "Condition.h"
template<typename T>
class AssistBZ :
	public BezierCurve
{
public:
using CONDITIONS = BoundaryConditions<VertexCondition<T>>;
	AssistBZ() {};
	~AssistBZ() {};
	AssistBZ(const Vertex2D<T> &point)
	{
		VertexCondition<float32> cnd;
		cnd.point = point;
		cnd.vector = Vector2D<T>(1.0, 0.0);
		condition.addCondition(cnd);

	}

	vector<BezierCurve<T>> &curveVec;
	CONDITIONS condition;
protected:
	Vertex2D<T> computeMiddlePoint()
	{
		float k1, k2, b1, b2;
	}
};

