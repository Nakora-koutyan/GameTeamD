#pragma once
#include "../System/AbstractScene.h"

class HELP : public AbstractScene
{
private:
	//�摜�n���h���i�[�p�ϐ�
	//int Helpimg;
	//�V�[���ύX�l
	bool sceneCHG;
	//����
	int sceneFlg;
public:
	HELP();

	//�f�X�g���N�^
	~HELP() {};

	//�����o�֐�
	//void Update()override;					//�`��ȊO�̍X�V����
	//void Draw() const override;				//�`��̍X�V����
	//AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};