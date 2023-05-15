#pragma once

#include "DxLib.h"

class InputControl
{
protected:
	static int key_flg;
	static int now_key;
	static int old_key;

public:
	InputControl()
	{
		key_flg = 0;
		now_key = 0;
		old_key = 0;
	}

	static void Update();			//更新
	static int GetKey(int key);		//キー情報取得
	static int GetKeyDown(int key);	//キー押下状態取得
};

