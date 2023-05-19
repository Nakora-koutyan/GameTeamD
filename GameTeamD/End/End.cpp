#include "End.h"
#include "Dxlib.h"

//初期化
void END::End_Initialize()
{
	E_count = 0;	//フレームカウント
	E_second = 0;	//秒数

	//画像のロード
	//mImageHandle=LoadGraph();
};

//更新
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

//描画
void END::End_Draw()
{
	//背景
	//DrawGraph(0,0,mImageHandle,FALSE);

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