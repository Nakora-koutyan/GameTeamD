#pragma once
#include"../System/AbstractScene.h"
#include"Stage.h"
#include"Player.h"
#include"Apple.h"

class GameMain : public AbstractScene {	//子クラス：GameMain、親クラス：AbstractScene
private:
	int gMainBGM;	//BGMの宣言
	int gBackScreen;

	int gRingoSE;      // リンゴのSE
	int gPoisonRingoSE;  // 毒リンゴのSE


	PLAYER player;	//PLAYER型を呼び出すためのクラス変数

	APPLE apple[APPLE_MAX];	//リンゴとリンゴの配列を呼び出すための配列

	int gAppleImg[4];
public:

	int AppleCount[4];

	// 描画に関することを実装する
	virtual void Draw() const override;


	//コンストラクタ
	GameMain();

	// デストラクタ
	virtual ~GameMain();

	// 描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	

	int CreateApple();   // リンゴの生成処理

	int AppleProd();     // リンゴの生成率

	int HitBoxPlayer(BoxCollider* p, APPLE* a);  // 当たり判定
};

