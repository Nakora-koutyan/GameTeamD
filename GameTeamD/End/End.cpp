#include "End.h"
#include "Dxlib.h"
#include"../System/Input.h"


<<<<<<< HEAD
int END::E_count;
int END::E_second;
int END::mImageHandle;
//初期化
void END::End_Initialize()
=======
//初期化
END::END()
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
{
	float E_count = 0;	//フレームカウント
	float E_second = 0;	//秒数

	//画像のロード
<<<<<<< HEAD
	//mImageHandle=LoadGraph();
=======
	//Endimg=LoadGraph();
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
};

//更新
<<<<<<< HEAD
void END::End_Update()
{
	//E_countを1フレームごとに加算
	E_count++;

	//E_countの値を秒にして取得
	E_second = E_count / 60;

	//5秒経つと終了(gGameModeをE_CLOSEに変更)
	if (E_second == 5)
	{
		
	}

};
=======
//void END::Update()
//{
//	//5秒経つと終了(gGameModeをE_CLOSEに変更)
//	if (300 < Count++)
//	{
//		End = 99;
//	}
//};
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)

//描画
void END::End_Draw()
{

	M_INPUT M{};

	M.Input();

	//背景
	DrawGraph(0,0, M.gEndImg, FALSE);

	//感謝
	DrawString(0, 0, "Thank you for playing", GetColor(255, 0, 0));

	//クレジット（素材の利用許諾など）

};

//終了
void END::End_Finalize()
{
	//画像の解放(要らないかも)
	//DeleteGraph(mImageHandle);
};