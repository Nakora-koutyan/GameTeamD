#include "Help.h"
#include "Dxlib.h"
<<<<<<< HEAD
#include"../System/Input.h"
=======
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)

//初期化処理
void HELP::HELP_Initialize()
{
	//画像のロード
	//mImageHandle=LoadGraph();
};

//更新処理
void HELP::HELP_Update()
{
	//Bボタン入力でゲームメインへ

	//Aボタン入力でタイトルへ

};

//描画処理
void HELP::HELP_Draw()
{

<<<<<<< HEAD
	M_INPUT M{};

	M.Input();

	//背景
	DrawGraph(0,0,M.gHelpImg,FALSE);
=======

	//背景
	//DrawGraph(0,0,M.gHelpImg,FALSE);
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)

	//操作説明(仮)
	DrawString(0, 0, "　　　　　　　操作説明　　　　　　　", GetColor(255, 0, 0));
	DrawString(0, 20, "左スティックでプレイヤーを移動して", GetColor(255, 0, 0));
	DrawString(0, 40, "落ちてくるリンゴをキャッチしよう", GetColor(255, 0, 0));
	DrawString(0, 60, "たくさんキャッチしてランキング1位を目指せ", GetColor(255, 0, 0));

	//画面遷移方法を記載
	DrawString(0, 80, "Bボタン入力でゲームメインへ", GetColor(255, 0, 0));
	DrawString(0, 100, "Aボタン入力でタイトルへ", GetColor(255, 0, 0));
};

//終了処理
void HELP::HELP_Finalize()
{
	//画像の解放
	//DeleteGraph(mImageHandle);
};