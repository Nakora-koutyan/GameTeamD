#pragma once
#include "AbstractScene.h"

// シーンマネージャークラス
// 各シーンの切り替えを整理する
class SceneManager : public AbstractScene {
private:
	AbstractScene* mScene; // 現在のシーン

public:
	// コンストラクタ
	SceneManager(AbstractScene* scene) :mScene(scene) {}

	// デストラクタ
	~SceneManager() {
		delete mScene;
	}
	//
	AbstractScene* Update() override;

	// 描画に関することを実装する
	void Draw() const override;
};