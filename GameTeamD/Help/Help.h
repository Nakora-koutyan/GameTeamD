#pragma once
#include "../System/AbstractScene.h"

class HELP : public AbstractScene
{
private:
	//画像ハンドル格納用変数
	//int Helpimg;
	//シーン変更値
	bool sceneCHG;
	//分岐
	int sceneFlg;
public:
	HELP();

	//デストラクタ
	~HELP() {};

	//メンバ関数
	//void Update()override;					//描画以外の更新処理
	//void Draw() const override;				//描画の更新処理
	//AbstractScene* ChangeScene() override;	//シーンの変更処理
};