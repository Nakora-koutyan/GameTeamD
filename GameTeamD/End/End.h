#pragma once
#include "../System/AbstractScene.h"

class END : public AbstractScene
{
private:
	//フレームカウント
	int Count;
	//画像ハンドル格納用変数
	int EndImg;
public:
	//終了
	static int End;
	//コンストラクタ
	END();
	//デストラクタ
	~END();
	//SceneManager用
	//void Update() override;				//描画以外の更新処理
	//void Draw()const override;			//描画の更新処理
	//AbstractScene* ChangeScene() override;//シーンの変更処理
};