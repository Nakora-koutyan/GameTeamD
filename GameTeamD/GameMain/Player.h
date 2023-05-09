#pragma once
#include "../System/Collision.h"

#define BUTTONS 16
#define WALK_SPEED 3
#define DASH_SPEED 7
#define ANIMATION_INTERVAL 10

enum class PLAYER_STATE {
	IDOL = 0,
	WALK,
	DASH
};

class Player :public Collision
{
private:
	bool TrunFlag;
	bool stickRollFlag;
	PLAYER_STATE PlayerState; //プレイヤーの現在の状態を制御

	int ImageStand;		//画像用変数
	int ImageDamage;	//画像用変数
	int ImagesDash[6];	//画像用配列
	int ImagesWalk[8];	//画像用配列
	int Image;
	int AnimTimer;		//画像切り替え用タイマー
	int AnimInterval;	//アニメーション切り替えの間隔

	float Speed;


	int GuideFont;
	int DamageSE;
	int WalkSE;
	int DashSE;

private:
	void DashAnimation();
	void WalkAnimation();
	bool DamageAnimation();

public:
	//コンストラクタ
	Player();

	//デストラクタ
	~Player();

	//更新
	void UpDate();

	//描画
	void Draw()const;

	void Reset();
};