#pragma once
#include"../System/AbstractScene.h"
#include"Stage.h"
#include"Player.h"
#include"Apple.h"

class GameMain : public AbstractScene {	//�q�N���X�FGameMain�A�e�N���X�FAbstractScene
private:
	int gMainBGM;	//BGM�̐錾

	PLAYER player;	//PLAYER�^���Ăяo�����߂̃N���X�ϐ�

	APPLE apple{};	//�����S�ƃ����S�̔z����Ăяo�����߂̔z��
public:
	//�R���X�g���N�^
	GameMain();

	// �f�X�g���N�^
	virtual ~GameMain();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};

