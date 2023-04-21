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

int gGameMode = TITLE;    // ゲームモード

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