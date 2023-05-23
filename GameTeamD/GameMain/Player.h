#pragma once
#include"DxLib.h"
#include"../System/Collision.h"

//初期値設定
#define PLAYER_WALK_SPEED	4		//歩行スピードの初期値
#define PLAYER_DASH_SPEED	7		//ダッシュスピードの初期値

//プレイヤーの初期状態
#define PLAYER_STATE_IDOL	0		//プレイヤーの直立状態
#define PLAYER_STATE_WALK	1		//プレイヤーの歩行状態
#define PLAYER_STATE_DASH	2		//プレイヤーのダッシュ状態

#define ANIMATION_INTERVAL 10		//アニメーション切り替えの間隔

class PLAYER
{
private:
	enum PLAYER_STATE
	{
		IDOL = 0,
		WALK,
		DASH
	};

	//プレイヤーの状態宣言
	int PlayerState;				//プレイヤーの現在の状態を制御

	//プレイヤー画像用の配列・変数宣言
	int ImageStand;					//直立画像用変数
	int ImagesDash[6];				//ダッシュ画像用配列
	int ImagesWalk[8];				//歩行画像用配列
	int Image;						//画像

	//画像切り替えに関する変数宣言
	int AnimTimer;					//アニメーション画像切り替え用タイマー
	int AnimInterval;				//アニメーション切り替え間隔
	int AnimType;					//アニメーションタイプ

	float speed;					//プレイヤーのスピード値

private:

	void DashAnimation();			//走行アニメーション
	void WalkAnimation();			//歩行アニメーション

public:
	//コンストラクタ
	PLAYER();

	//デストラクタ
	~PLAYER();

	//プレイヤーの現在の状態の更新
	void Update();

	//描画
	void Draw() const;

	//状態のリセット
	void Reset();
;
};