#include<stdio.h>
#include<DxLib.h>

/**************************************
*　列挙型の宣言
***************************************/
enum mode {
	TITLE,
	INIT,
	MAIN,
	RANKING,
	HELP,
	INPUTNAME,
	RESULT,
	END,
	CLOSE
};
/**************************************
*　変数の宣言
***************************************/
// 画面領域の大きさ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// 自機の初期値の定数
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 20;//63
const int PLAYER_HEIGHT = 60;//120
const int PLAYER_SPEED = 5;
const int PLAYER_HP = 1000;
const int PLAYER_FUEL = 20000;
const int PLAYER_BARRIER = 3;
const int PLAYER_BARRIERUP = 10;

// 敵機の最大数
const int ENEMY_MAX = 8;

// アイテムの最大値
const int ITEM_MAX = 3;

/**************************************
*　変数の宣言(グローバル変数)
***************************************/
int gOldKey;           // 前回の入力キー
int gNowKey;           // 今回の入力キー
int gKeyFlg;           // 入力キー情報

int gGameMode = TITLE;    // ゲームモード

int gTitleImg;         // タイトル画像
int gTitlebgm;
int gMenuImg;          // メニュー画像
int gConeImg;          // メニューカーソル画像

int gScore = 0;        // スコア
int gRankingImg;       // ランキング画面背景

int gItemImg[2];       // アイテム画像

int gWaitTime = 0;      // 待ち時間
int gEndImg;            // エンド画像

int gMileage;          // 走行距離
int gEnemyCount[4];    // 敵カウント
int gEnemyImg[4];      // 敵キャラ画像

int gStageImg;         // ステージ画像(道路)

int gCarImg;           // 車の画像
int gBarrierImg;       // バリアの画像

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

	gTitleImg = LoadGraph("images/Title.png");

	gTitlebgm = LoadSoundMem("Sounds/Title.wav");
	int gMainbgm = LoadSoundMem("Sounds/Main.wav");

	SetLoopSamplePosSoundMem(371945, gMainbgm);
	SetLoopSamplePosSoundMem(109696, gTitlebgm);
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);

	// ゲームループ
	while (ProcessMessage() == 0 && gGameMode != CLOSE && !(gKeyFlg & PAD_INPUT_START)) {


		// 画面の初期化
		ClearDrawScreen();

		DrawGraph(0, 0, gTitleImg, 0);

		// 裏画面の内容を表画面に反映する
		ScreenFlip();
	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// プログラムの終了
	return 0;
}