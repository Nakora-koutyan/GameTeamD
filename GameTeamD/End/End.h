#pragma once
<<<<<<< HEAD
class END
=======
#include "DxLib.h"
#include "../System/AbstractScene.h"

class END : public AbstractScene
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
{
public:
	//変数
	static int E_count;
	static int E_second;

	//画像ハンドル格納用変数
	static int mImageHandle;

<<<<<<< HEAD
	//メンバ関数
	void End_Initialize();	//初期化
	void End_Finalize();	//終了
	void End_Update();		//更新
	void End_Draw();		//描画
=======
	END();
	//デストラクタ
	~END() {};
	//SceneManager用
	//void Update() override;		//描画以外の更新処理
	//void Draw()const override;		//描画の更新処理
	//AbstractScene* ChangeScene() override;
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
};