
#include "Matrix4x4.h"
#include <Novice.h>
#include <iostream>
#include <math.h>
#define USE_MATH_DEFINES

const char kWindowTitle[] = "GC1D_ワタナベ_リョウイチ";
Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip) {
	return {
	    2.0f / (right - left),
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    2.0f / (top - bottom),
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    1.0f / (farClip - nearClip),
	    0.0f,
	    (left + right) / (left - right),
	    (top + bottom) / (bottom - top),
	    nearClip / (nearClip - farClip),
	    1.0f,
	};
}

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	float cotHalfFovV = 1.0f / std::tan(fovY / 2.0f);

	return {
	    (cotHalfFovV / 1280 * 720),
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    cotHalfFovV,
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    farClip / (farClip - nearClip),
	    1.0f,
	    0.0f,
	    0.0f,
	    -(nearClip*farClip) / (farClip-nearClip),
	    0.0f};
}

Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth) {
	return {
	    width / 2.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    -height / 2.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    0.0f,
	    maxDepth - minDepth,
	    0.0f,
	    left + width / 2.0f,
	    top + height / 2.0f,
	    minDepth,
	    1.0f,
	};
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	// Calculation* calculation = new Calculation();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		///
		/// ↓更新処理ここから
		///
		Matrix4x4 orthographicMatrix =
		    MakeOrthographicMatrix(-160.f, 160.f, 200.0f, 300.0f, 0.0f, 1000.0f);

		Matrix4x4 perspectiveFovMatrix = MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);

		Matrix4x4 viewportMatrix = MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		// calculation->VectorScreenPrintf(0, 0, );
		 MatrixScreenPrintf(0, 0, orthographicMatrix, "orthographicMatrix");
		ScreenPrintf(0, kRowHeight * 5, perspectiveFovMatrix, "perspectiveFovMatrix");
		ScreenPrintf(0, kRowHeight * 10, viewportMatrix, "viewportMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
			// delete calculation;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
