#pragma once
#include"../System/AbstractScene.h"
#include"Stage.h"
#include"Player.h"
#include"Apple.h"

class GameMain : public AbstractScene {	//子クラス：GameMain、親クラス：AbstractScene
private:
	int gMainBGM;	//BGMの宣言

	PLAYER player;	//PLAYER型を呼び出すためのクラス変数

	APPLE apple{};	//リンゴとリンゴの配列を呼び出すための配列
public:
	//コンストラクタ
	GameMain();

	// デストラクタ
	virtual ~GameMain();

	// 描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	// 描画に関することを実装する
	virtual void Draw() const override;
};

