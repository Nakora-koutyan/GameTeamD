#pragma once
#include "../System/AbstractScene.h"

class END : public AbstractScene
{
private:
	int Count;
	//画像ハンドル格納用変数
	//int Endimg;
public:

	static int End;

	END();
	//デストラクタ
	~END() {};
	//SceneManager用
	//void Update() override;				//描画以外の更新処理
	//void Draw()const override;			//描画の更新処理
	//AbstractScene* ChangeScene() override;//シーンの変更処理
};