#pragma once
#include "AbstractScene.h"
class END:public AbstractScene
{
public:
	//変数
	static int E_count;
	static int E_second;

	//画像ハンドル格納用変数
	static int mImageHandle;

	//メンバ関数
	void End_Initialize();	//初期化
	void End_Finalize();	//終了
	void End_Update();		//更新
	void End_Draw();		//描画
};