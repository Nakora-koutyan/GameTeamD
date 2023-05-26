#include "Help.h"
#include "Dxlib.h"
#include"../System/PadInput.h"
#include"../GameMain/GameMain.h"
#include"../Title/Title.h"

//コンストラクタ
HELP::HELP()
{
	//画像のロード
	//HelpImg=LoadGraph();
	sceneCHG = false;
	sceneFlg = 0;
};

//更新処理
//void HELP::Update()
//{
//	//Bボタン入力でゲームメインへ
//	if (InputControl::PressBotton(XINPUT_BUTTON_B))
//	{
//		sceneCHG = true;
//		sceneFlg = 1;
//	}
//	//Aボタン入力でタイトルへ
//	else if (InputControl::PressBotton(XINPUT_BUTTON_A))
//	{
//		sceneCHG = true;
//		sceneFlg = 2;
//	}
//};

//描画処理
//void HELP::Draw() const
//{
//
//
//	//背景
//	//DrawGraph(0,0,M.gHelpImg,FALSE);
//
//	//操作説明(仮)
//	DrawString(0, 0, "　　　　　　　操作説明　　　　　　　", GetColor(255, 0, 0));
//	DrawString(0, 20, "左スティックでプレイヤーを移動して", GetColor(255, 0, 0));
//	DrawString(0, 40, "落ちてくるリンゴをキャッチしよう", GetColor(255, 0, 0));
//	DrawString(0, 60, "たくさんキャッチしてランキング1位を目指せ", GetColor(255, 0, 0));
//
//	//画面遷移方法を記載
//	DrawString(0, 80, "Bボタン入力でゲームメインへ", GetColor(255, 0, 0));
//	DrawString(0, 100, "Aボタン入力でタイトルへ", GetColor(255, 0, 0));
//};

//終了処理
//AbstractScene* HELP::ChangeScene()
//{
//	if (sceneCHG) 
//	{
//		if (sceneFlg == 1) 
//		{
//			return new GameMain;
//		}
//		if (sceneFlg == 2)
//		{
//			return new Title;
//		}
//	}
//
//	return this;
//
//};