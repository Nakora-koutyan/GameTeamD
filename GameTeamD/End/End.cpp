#include "End.h"
#include "Dxlib.h"
#include"../System/Input.h"

int END::End;

//コンストラクタ
END::END()
{
	End = 0;
	Count = 0;

	//画像のロード
	EndImg=LoadGraph("Material/Images/BackImage.png");
};

END::~END()
{
	DeleteGraph(EndImg);
}

//SceneManager用
//更新
//void END::Update()
//{
//	//5秒経つと終了
//	if (300 < Count++)
//	{
//		End = 99;
//	}
//};

//描画
//void END::Draw() const
//{
//
//	M_INPUT M{};
//
//	M.Input();
//
//	//背景
//	DrawGraph(0,0, M.gEndImg, FALSE);
//
//	//感謝
//	DrawString(0, 0, "Thank you for playing", GetColor(255, 0, 0));
//
//	//クレジット（素材の利用許諾など）
//
//};

//SceneManager用
//AbstractScene* END::ChangeScene()
//{
//	return this;
//};