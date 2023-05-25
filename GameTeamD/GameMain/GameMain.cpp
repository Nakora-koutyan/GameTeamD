#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"
#include"../Title/title.h"
#include "../System/Input.h"

GameMain::GameMain()
{
	// BGM読込
	int gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");

	// gMainBGMが流れてないなら流す
	if (CheckSoundMem(gMainBGM) != 1)
	{
		SetLoopSamplePosSoundMem(371945, gMainBGM);
		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
	}
	/* 画像読込 */
	gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png");
	gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png");
	gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png");
	gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png");

}

GameMain::~GameMain()	//デストラクタ
{
	DeleteSoundMem(gMainBGM);

	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(gAppleImg[i]);
	}
}


AbstractScene* GameMain::Update() //ゲームメインのアップデート
{
	player.Update();	//プレイヤーの更新
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i].AppleControl(); // リンゴの移動処理

		if (HitBoxPlayer(&player, &apple[i]) == TRUE)
		{
			apple[i].flg = FALSE;
		}
	}

	CreateApple(); // リンゴの生成処理

	if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {
		return new TITLE;	//
	}

	return this;	//現在のシーンを返す(ゲームメイン)
}

void GameMain::Draw() const {
	player.Draw();

	DrawString(300, 10, "GameMain", 0xFFFFFF);

}

int GameMain::CreateApple()
{

	for (int i = 0; i < APPLE_MAX; i++) {
		if (apple[i].flg == FALSE) {
			apple[i] = {};
			apple[i].flg = TRUE; // 画像をONにする
			apple[i].type = AppleProd(); // 乱数で確率出す
			apple[i].img = gAppleImg[apple[i].type]; // リンゴの画像を代入
			apple[i].SetLocation(Location{ float(GetRand(6) * 150 + 100), 0}); // レーン数X  // y軸を0に設定


			switch (apple[i].type)
			{
			case 0:
				// 赤リンゴ出現
				apple[i].speed = 1;
				apple[i].magnification = 1.1;
				break;

			case 1:
				// 青リンゴ出現
				apple[i].speed = 3;
				apple[i].magnification = 1.1;
				break;

			case 2:
				// 金リンゴ出現
				apple[i].speed = 5;
				apple[i].magnification = 1.1;
				break;

			case 3:
				// 毒リンゴ出現
				apple[i].speed = 0.5;
				apple[i].magnification = 0.9;
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
}