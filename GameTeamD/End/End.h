#pragma once
#include "../System/AbstractScene.h"

class END : public AbstractScene
{
private:
	//�t���[���J�E���g
	int Count;
	//�摜�n���h���i�[�p�ϐ�
	int EndImg;
public:
	//�I��
	static int End;
	//�R���X�g���N�^
	END();
	//�f�X�g���N�^
	~END();
	//SceneManager�p
	//void Update() override;				//�`��ȊO�̍X�V����
	//void Draw()const override;			//�`��̍X�V����
	//AbstractScene* ChangeScene() override;//�V�[���̕ύX����
};