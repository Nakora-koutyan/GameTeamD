#pragma once
#include "../System/AbstractScene.h"

class RESULT :public AbstractScene
{
private:
	//画像
	int ResultImg;
	//シーン変更値
	bool sceneCHG;
	//分岐
	int sceneFlg;
	//フレームカウント
	int FlmCnt;
	//秒数
	int second;
public:
	//コンストラクタ
	RESULT();

	//デストラクタ
	~RESULT();

	/*void Update() override;
	void Draw()const override;
	AbstractScene* ChangeScene() override;*/
};