#pragma once
class HELP
{
public:
	//画像ハンドル格納用変数
	static int mImageHandle;

	//メンバ関数
	void HELP_Initialize();	//初期化
	void HELP_Finalize();	//終了
	void HELP_Update();		//更新
	void HELP_Draw();		//描画
};