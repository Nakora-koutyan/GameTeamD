#include<stdio.h>
#include"DxLib.h"
#include"Title/Title.h"
#include"GameMain/GameMain.h"
#include"GameMain/Stage.h"
#include"GameMain/Player.h"
#include"GameMain/Apple.h"
#include"GameMain/Result.h"
#include"Ranking/Ranking.h"
#include"Help/Help.h"
#include"End/Credit.h"
#include"End/End.h"
#include"System/FpsController.h"
#include"System/PadInput.h"
#include"System/Collision.h"
#include"System/AbstractScene.h"
#include"System/Input.h"
#include"System/SceneManager.h"


#define FRAMERATE 60.0

/**************************************
*　列挙型の宣言
***************************************/
enum mode {
	E_TITLE,
	E_INIT,
	E_MAIN,
	E_RANKING,
	E_HELP,
	E_INPUTNAME,
	E_RESULT,
	E_END,
	E_CLOSE
};
/**************************************
*　変数の宣言
***************************************/


/**************************************
*　変数の宣言(グローバル変数)
***************************************/
//int gGameMode = E_TITLE;    // ゲームモード

int gTitlebgm;         // 

int gScore = 0;        // スコア



/**************************************
*　プログラムの開始
***************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//LONGLONG nowTime = GetNowHiPerformanceCount();
	//LONGLONG oldTime = nowTime;
	//LONGLONG fpsCheckTime;
	//double deltaTime = 0;
	//int fpsCounter = 0;
	//int fps = 0;

	//// ループ前にFPS計測を初期化
	//fpsCheckTime = GetNowHiPerformanceCount();
	//fps = 0;
	//fpsCounter = 0;

	// タイトルを設定
	SetMainWindowText("pick up apples");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// ウィンドウサイズ設定	
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT,32);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//SetLoopSamplePosSoundMem(371945, gMainbgm); 
	SetLoopSamplePosSoundMem(109696, gTitlebgm); 

	M_INPUT M{};

	PLAYER Player;

	APPLE apple{};

	Player.Update();

	GameMain stage;

	TITLE T;

	FpsController FPS;
	
	M.Input();

	FpsController FPSC(FRAMERATE, 800);

	// ゲームループ
	while (ProcessMessage() == 0 ) {

		FPS.Get();

		// ゲームモードと画面遷移の制御
		/*switch (gGameMode) {
		case E_TITLE:
			T.print();
			break;
		case E_INIT:
			GameInit();
			break;
		case E_MAIN:
			DrawMain();
			break;
		case E_RANKING:
			DrawRanking();
			break;
		case E_INPUTNAME:
			InputName();
			break;
		case E_END:
			DrawOver();
			break;
		case E_CLOSE:
			DrawEnd();
			break;
		}*/

		// 画面の初期化
		ClearDrawScreen();
		FPSC.All();

		InputControl::Update();

		Player.Update();

		DrawGraph(0, 0, M.gBackScreen, 0);

		DrawString(20, 20, "debug...", GetColor(255, 255, 255));

		// リンゴ表示確認用
		//apple.IMAGES_RINGO();

		//T.print();
		SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TITLE()));

		printf("整数値を入力してください＞");
		while (sceneMng.Update() != nullptr) {
			sceneMng.Draw();
		}

		//プレイヤー画像表示関数の宣言
		Player.Draw();

		//// FPSの表示
		//SetFontSize(16);
		//DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec", fps, deltaTime);

		//// 1ループ時点のシステム時間を取得
		//oldTime = nowTime;
		//nowTime = GetNowHiPerformanceCount();

		//// 1ループの時間経過を求める
		//deltaTime = (nowTime - oldTime) / 1000000.0F;

		//// 1秒間のFPSを計測する、1秒ごとに初期化する
		//fpsCounter++;
		//if (nowTime - fpsCheckTime > 1000000) {
		//	fps = fpsCounter;
		//	fpsCounter = 0;
		//	fpsCheckTime = nowTime;
		//}

		 //裏画面の内容を表画面に反映する
		ScreenFlip();
	}
	// プログラムの終了
	return 0;
}