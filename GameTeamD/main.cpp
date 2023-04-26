#include<stdio.h>
#include<DxLib.h>
#include"../GameTeamD/Title/Title.h"
#include"../GameTeamD/GameMain/GameMain.h"
#include"../GameTeamD/GameMain/Stage.h"
#include"../GameTeamD/GameMain/Player.h"
#include"../GameTeamD/GameMain/Apple.h"
#include"../GameTeamD/GameMain/Result.h"
#include"../GameTeamD/Ranking/DrawRanking.h"
#include"../GameTeamD/Ranking/Ranking.h"
#include"../GameTeamD/Help/Help.h"
#include"../GameTeamD/End/Credit.h"
#include"../GameTeamD/End/End.h"
#include"../GameTeamD/System/FpsController.h"
#include"../GameTeamD/System/PadInput.h"
#include"../GameTeamD/System/Collision.h"
#include"../GameTeamD/System/AbstractScene.h"

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

// リンゴの最大数
const int APPLE_MAX = 20;

/**************************************
*　変数の宣言(グローバル変数)
***************************************/
int gOldKey;           // 前回の入力キー
int gNowKey;           // 今回の入力キー
int gKeyFlg;           // 入力キー情報

int gGameMode = E_TITLE;    // ゲームモード

int gTitleImg;         // タイトル画像

int gTitlebgm;         // 

int gScore = 0;        // スコア

int gItemImg[4];       // アイテム画像

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
	SetWindowSize(1280, 720);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//SetLoopSamplePosSoundMem(371945, gMainbgm); //
	SetLoopSamplePosSoundMem(109696, gTitlebgm); //

    TITLE title;

	

	// ゲームループ
	while (ProcessMessage() == 0 && gGameMode != E_CLOSE && !(gKeyFlg & PAD_INPUT_START)) {


		// 画面の初期化
		ClearDrawScreen();

		title.print();

		// 裏画面の内容を表画面に反映する
		ScreenFlip();
	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// プログラムの終了
	return 0;
}