#pragma once
#include"../System/AbstractScene.h"
#include"Stage.h"
#include"Player.h"
#include"Apple.h"

class GameMain : public AbstractScene {	//�q�N���X�FGameMain�A�e�N���X�FAbstractScene
private:
	int gMainBGM;	//BGM�̐錾
	int gBackScreen;

	int gRingoSE;      // �����S��SE
	int gPoisonRingoSE;  // �Ń����S��SE


	PLAYER player;	//PLAYER�^���Ăяo�����߂̃N���X�ϐ�

	APPLE apple[APPLE_MAX];	//�����S�ƃ����S�̔z����Ăяo�����߂̔z��

	int gAppleImg[4];
public:

	int AppleCount[4];

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


	//�R���X�g���N�^
	GameMain();

	// �f�X�g���N�^
	virtual ~GameMain();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	

	int CreateApple();   // �����S�̐�������

	int AppleProd();     // �����S�̐�����

	int HitBoxPlayer(BoxCollider* p, APPLE* a);  // �����蔻��
};

