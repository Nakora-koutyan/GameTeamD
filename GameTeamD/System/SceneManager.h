#pragma once
#include "AbstractScene.h"

// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ��𐮗�����
class SceneManager : public AbstractScene {
private:
	AbstractScene* mScene; // ���݂̃V�[��

public:
	// �R���X�g���N�^
	SceneManager(AbstractScene* scene) :mScene(scene) {}

	// �f�X�g���N�^
	~SceneManager() {
		delete mScene;
	}
	//
	AbstractScene* Update() override;

	// �`��Ɋւ��邱�Ƃ���������
	void Draw() const override;
};