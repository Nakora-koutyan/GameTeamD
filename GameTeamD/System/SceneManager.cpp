#include"SceneManager.h"
#include"PadInput.h"

AbstractScene* SceneManager::Update() {
	AbstractScene* p = mScene->Update();
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}

	if (InputControl::PressBotton(XINPUT_BUTTON_BACK))
	{
		return nullptr;
	}

	return p;
}
void SceneManager::Draw() const {
	mScene->Draw();
}