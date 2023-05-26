#include"SceneManager.h"
#include"PadInput.h"

AbstractScene* SceneManager::Update() {
	AbstractScene* p = mScene->Update();	//シーンの切り替え(thisの上書き)
	//pはNew	//mSceneはOld
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}

	if (InputControl::PressBotton(XINPUT_BUTTON_BACK))
	{
		return nullptr;	//強制終了
	}

	return p;
}
void SceneManager::Draw() const {
	mScene->Draw();		//現在のシーンの描画
}