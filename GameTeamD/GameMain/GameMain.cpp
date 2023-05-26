#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"
#include"../Title/title.h"
#include "../System/Input.h"
#define TIMELIMIT = 60;


GameMain::GameMain()
{
	// BGM読込
	gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
	gGameBackScreen = LoadGraph("Material/Images/BackImage.png");

	// gMainBGMが流れてないなら流す
	if (CheckSoundMem(gMainBGM) != 1)
	{
		SetLoopSamplePosSoundMem(371945, gMainBGM);
		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
	}

	//背景画像読込
	gGameBackScreen = LoadGraph("Material/Images/BackImage.png");
	gTimeOver = LoadGraph("Material/Images/TimeOver.png");
	/* リンゴ画像読込 */
	gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png");
	gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png");
	gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png");
	gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png");
	/* リンゴ落下SE */
	gRingoSE = LoadSoundMem("Material/Sounds/SE/パワーアップ.wav");
	gPoisonRingoSE = LoadSoundMem("Material/Sounds/SE/毒状態.wav");

	AppleCount[0] = 0;
	AppleCount[1] = 0;
	AppleCount[2] = 0;
	AppleCount[3] = 0;

	//残り時間を描画する
	TimeOver = FALSE;
}

GameMain::~GameMain()	//デストラクタ
{
	DeleteSoundMem(gMainBGM);

	for (int i = 0; i < 4; i++) {
		DeleteGraph(gAppleImg[i]);
	}
}

AbstractScene* GameMain::Update() //ゲームメインのアップデート
{
	player.Update();	//プレイヤーの更新

	CreateApple();

	for(int i=0; i<APPLE_MAX;i++)
	{
		apple[i].AppleControl();

		if (HitBoxPlayer(&player, &apple[i]) == TRUE)
		{
			apple[i].flg = FALSE;
			if (apple[i].img!=gAppleImg[3]) // 毒リンゴ取ってないとき
			{
				if (CheckSoundMem(gRingoSE) == 0)
				{	
					PlaySoundMem(gRingoSE, DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem(123, gRingoSE);
				}
			}
			else // 毒リンゴを取ったとき
			{
				PlaySoundMem(gPoisonRingoSE, DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem(255, gPoisonRingoSE);
			}
			/* 取ったリンゴをカウント */
			if (apple[i].type == 0)      // 取ったリンゴが赤だったとき
			{
				AppleCount[0]++;           // 赤リンゴの数に1加算
			}
			else if (apple[i].type == 1)  // 取ったリンゴが青だったとき
			{
				AppleCount[1]++;		   // 青リンゴの数に1加算
			}
			else if (apple[i].type == 2)  // 取ったリンゴが金だったとき
			{
				AppleCount[2]++;		   // 金リンゴの数に1加算
			}
			else						   // 取ったリンゴが毒だったとき
			{
				AppleCount[3]++;		    // 毒リンゴの数に1加算
			}
		}
	}

	if(FlmCnt++ % 60)second += 1;

	if (second >= 60) TimeOver = TRUE;

	//if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {
	//	return new TITLE;	//
	//}

	ui.SetTime(second);
	ui.AddAcqu(AppleCount);

	return this;	//現在のシーンを返す(ゲームメイン)
}

void GameMain::Draw() const 
{

	DrawGraph(0, 0, gGameBackScreen, FALSE);

	player.Draw();
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i].Draw();
	}
	DrawString(300, 10, "GameMain", 0xFFFFFF);

	if (TimeOver)
	{
		DrawGraph(0, 0, gTimeOver, FALSE);
	}
	DrawFormatString(900, 100, 0xffffff, "%3d");

	ui.Draw();
}

int GameMain::CreateApple()
{

	for (int i = 0; i < APPLE_MAX; i++) {
		if (apple[i].flg == FALSE) {
			apple[i] = {};
			apple[i].flg = TRUE; // 画像をONにする
			apple[i].type = AppleProd(); // 乱数で確率出す
			apple[i].img = gAppleImg[apple[i].type]; // リンゴの画像を代入
			apple[i].SetLocation(Location{ float(GetRand(6) * 120 + 100), 0}); // レーン数X  // y軸を0に設定


			switch (apple[i].type)
			{
			case 0:
				// 赤リンゴ出現
				apple[i].speed = 1;           // スピードを設定
				apple[i].magnification = 1.1; // 当たり判定の倍率設定
				//apple[i].count += 1;		  // カウントに１加算
				//apple[i].point += 100;	  // ポイントに100加算
				break;

			case 1:
				// 青リンゴ出現
				apple[i].speed = 3;			  // スピードを設定
				apple[i].magnification = 1.1; // 当たり判定の倍率設定
				//apple[i].point += 200;        // ポイントに200加算
				break;						  
				
			case 2:
				// 金リンゴ出現
				apple[i].speed = 5;			  // スピードを設定
				apple[i].magnification = 1.1; // 当たり判定の倍率設定
				//apple[i].point += 500;        // ポイントに500加算
				break;

			case 3:
				// 毒リンゴ出現
				apple[i].speed = 0.5;		  // スピードを設定
				apple[i].magnification = 0.9; // 当たり判定の倍率設定
				//apple[i].point -= 750;		  // ポイントに750減算
				break;
			}


			// 成功
			return TRUE;
		}
	}

	// 失敗
	return FALSE;
}

int GameMain::AppleProd()     // リンゴの生成率
{

	int rand = GetRand(19);
	if (rand < 11) {
		return 0;
	}
	else if (rand < 16) {
		return 1;
	}
	else if (rand < 18) {
		return 2;
	}
	else {
		return 3;
	}
}

int GameMain::HitBoxPlayer(BoxCollider* p, APPLE* a)
{	// x,yは中心座標とする
	int sx1 = p->GetLocation().x - (p->GetErea().width / 2);
	int sy1 = p->GetLocation().y - (p->GetErea().height / 2);
	int sx2 = sx1 + p->GetErea().width;
	int sy2 = sy1 + p->GetErea().height;

	/* 赤、青、金,毒リンゴの当たり判定*/
	int ax1 = a->GetLocation().x - (a->GetErea().width / 2 * a->magnification);
	int ay1 = a->GetLocation().y - (a->GetErea().height / 2 * a->magnification);
	int ax2 = ax1 + a->GetErea().width * a->magnification;
	int ay2 = ay1 + a->GetErea().height * a->magnification;

	if (sx1 < ax2 && ax1 < sx2 && sy1 < ay2 && ay1 && sy2)
	{
		return TRUE;
	}
	return FALSE;
	/*DrawGraph(0, 0, gGameBackScreen,0);
	player.Draw();
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i].Draw();
	}
	DrawFormatString(100, 100, 0xffffff, "%f", player.Speed);*/
}