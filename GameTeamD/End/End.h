#pragma once
#include "../System/AbstractScene.h"

class END : public AbstractScene
{
private:
	int Count;
	//�摜�n���h���i�[�p�ϐ�
	//int Endimg;
public:

	static int End;

	END();
	//�f�X�g���N�^
	~END() {};
	//SceneManager�p
	//void Update() override;				//�`��ȊO�̍X�V����
	//void Draw()const override;			//�`��̍X�V����
	//AbstractScene* ChangeScene() override;//�V�[���̕ύX����
};