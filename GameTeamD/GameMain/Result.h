#pragma once
#include "../System/AbstractScene.h"

class RESULT :public AbstractScene
{
private:
	//�摜
	int ResultImg;
	//�V�[���ύX�l
	bool sceneCHG;
	//����
	int sceneFlg;
	//�t���[���J�E���g
	int FlmCnt;
	//�b��
	int second;
public:
	//�R���X�g���N�^
	RESULT();

	//�f�X�g���N�^
	~RESULT();

	/*void Update() override;
	void Draw()const override;
	AbstractScene* ChangeScene() override;*/
};