#include"SceneManager.h"
#include"PadInput.h"

AbstractScene* SceneManager::Update() {
	AbstractScene* p = mScene->Update();	//�V�[���̐؂�ւ�(this�̏㏑��)
	//p��New	//mScene��Old
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}

	if (InputControl::PressBotton(XINPUT_BUTTON_BACK))
	{
		return nullptr;	//�����I��
	}

	return p;
}
void SceneManager::Draw() const {
	mScene->Draw();		//���݂̃V�[���̕`��
}