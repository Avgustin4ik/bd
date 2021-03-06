#pragma once
#include <math.h>
#include <vector>
#include "Matrix.h"
#include "cppoptlib\meta.h"
#include "cppoptlib\problem.h"
#include "cppoptlib\solver\bfgssolver.h"




typedef float float32;
typedef double float64;
const float32 INF = 0.0;
const float32 EPS = powf(10, -6);
const float32 MAX_SPLIT = 100;
typedef unsigned int uint;
const float64 PI = 3.141592653589793238462643;
const float32 LEFT_BORDER = 0.0;
const float32 RIGHT_BORDER = 1.0;

#define EQUAL2EPS(X,Y,DELTA) ABS(X-Y)<=DELTA ? Y : X
#define RAD(X) X*PI/180			//������� � �������
#define DEG(X) X*180/PI			//������� � �������
struct Configuration
{
public:
	const float32 curvature_eps;
	const uint iterations_limit;
	float32 h;//���������� ��������� ��� ���������� �����������	
	float32 alpha;//����������� ����������
	Configuration() :iterations_limit(200), h(0.001), alpha(0.1), curvature_eps(0.001) {};
	~Configuration() {};
};
