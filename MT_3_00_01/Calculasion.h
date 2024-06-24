#pragma once
#include <Vector3.h>
class Calculation
{

public://関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Calculation();
	/// <summary>
	/// 三次元変換計算関数の出力結果
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="vector"></param>
	/// <param name="label"></param>
	void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

	/// <summary>
	/// 加算
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	/// <summary>
	/// 減算
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);

	/// <summary>
	/// スカラー倍
	/// </summary>
	/// <param name="scalar"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	Vector3 Multiply(float scalar, const Vector3& v);

	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	
	float Dot (const Vector3& v1, const Vector3& v2);

	/// <summary>
	/// 長さ(ノルム)
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	float Length(const Vector3& v);

	/// <summary>
	/// 正規化
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	Vector3 Normalize(const Vector3& v);
	
Vector3 GetAdd();
Vector3 GetSubtract();
Vector3 GetMultiply();
float GetDot();
float GetLength();
Vector3 GetNormalize();

private: // メンバー変数
	Vector3 v1_;
	Vector3 v2_;
	float k_;

	Vector3 resultAdd_;
	Vector3 resultSubtract_;
	Vector3 resultMultiply_;
	float resultDot_;
	float resultLength_;
	Vector3 resultNormalize_;
};