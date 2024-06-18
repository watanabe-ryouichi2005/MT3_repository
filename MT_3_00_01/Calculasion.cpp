
#include "Calculasion.h"
#include<Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

static const int kColumWidth = 60;
static const int kRowHeight = 20;

Calculation::Calculation() {
	v1_ = { 1.0f,3.0f,-5.0f };
	v2_ = { 4.0f,-1.0f,2.0f };
	k_ = { 4.0f };
	resultAdd_ = { Add(v1_, v2_) };
	resultSubtract_ = { Subtract(v1_, v2_) };
	resultMultiply_ = { Multiply(k_, v1_) };
	resultDot_ = { Dot(v1_, v2_) };
	resultLength_ = { Length(v1_) };
	resultNormalize_ = { Normalize(v2_) };


}
void Calculation::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);


}
Vector3 Calculation::Add(const Vector3& v1, const Vector3& v2) {
	return { v1.x + v2.x,v1.y + v2.y,v1.z + v2.z

	};
}

Vector3 Calculation::Subtract(const Vector3& v1, const Vector3& v2)
{
	return { v1.x - v2.x,v1.y - v2.y,v1.z - v2.z

	};
}
Vector3 Calculation::Multiply(float Scaler, const Vector3& v) {
	return{ Scaler * v.x,Scaler * v.y,Scaler * v.z };
}
float Calculation::Dot(const Vector3& v1, const Vector3& v2) {
	return { v1.x * v2.x + v1.y * v2.y + v1.z * v2.z
	};

}
float Calculation::Length(const Vector3& v) {
	float answer = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return answer;
}
Vector3 Calculation::Normalize(const Vector3& v) {
	float answer = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	Vector3 backnum = { v.x,v.y,v.z };
	if (answer != 0.0f)
	{
		backnum = { v.x / answer,v.y / answer,v.z / answer };
	}
	return backnum;
}

Vector3 Calculation::GetAdd() { return resultAdd_; }

Vector3 Calculation::GetSubtract() {
	return resultSubtract_; 

}

Vector3 Calculation::GetMultiply() { 
	return resultMultiply_; }
float Calculation::GetDot() { return resultDot_; }
float Calculation::GetLength() { return resultLength_; }



