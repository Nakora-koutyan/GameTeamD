#include "Result.h"
#include "Dxlib.h"

//コンストラクタ
RESULT::RESULT()
{
	ResultImg = LoadGraph("Material/Images/BackImage.png");
	FlmCnt = 0;
	second = 0;
}

//デストラクタ
RESULT::~RESULT()
{
	DeleteGraph(ResultImg);
}

AbstractScene* RESULT::Update()
{
	FlmCnt++;
	second = FlmCnt / 28;
	if (second >= 60)
	{
		//スコアがランキングの最下位以上で名前入力
		
		//スコアがランキングの最下位以下でランキング

	}

	return this;
}

void RESULT::Draw() const
{
	//背景
	DrawGraph(0, 0, ResultImg, FALSE);
}
