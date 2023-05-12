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
// 画面領域の大きさ
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


/**************************************
*　変数の宣言(グローバル変数)
***************************************/

int gGameMode = E_TITLE;    // ゲームモード

/**************************************
*　プログラムの開始
***************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
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

    M_INPUT M;

	G_PLAYER Box;

	APPLE apple;
	
	M.Input();

	TITLE title;

	
	// ゲームループ
	while (ProcessMessage() == 0 && gGameMode != E_CLOSE) {


		// 画面の初期化
		ClearDrawScreen();

		DrawGraph(0, 0, M.gBackScreen, 0);

		DrawString(20, 20, "debug...", GetColor(255, 255, 255));

		// リンゴ表示確認用
		apple.IMAGES_RINGO();

		title.print();

		Box.PlayerImages();

		 //裏画面の内容を表画面に反映する
		ScreenFlip();
	}

	//delete player;

	// DXライブラリ使用の終了処理
	DxLib_End();

	// プログラムの終了
	return 0;
}