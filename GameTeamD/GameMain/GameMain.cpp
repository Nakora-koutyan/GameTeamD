#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"
#include"../Title/title.h"
#include "../System/Input.h"

GameMain::GameMain()
{
	// BGM�Ǎ�
	int gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");

	// gMainBGM������ĂȂ��Ȃ痬��
	if (CheckSoundMem(gMainBGM) != 1)
	{
		SetLoopSamplePosSoundMem(371945, gMainBGM);
		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
	}

}

GameMain::~GameMain()	//�f�X�g���N�^
{
	DeleteSoundMem(gMainBGM);
}


AbstractScene* GameMain::Update() //�Q�[�����C���̃A�b�v�f�[�g
{
	player.Update();	//�v���C���[�̍X�V




	if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {
		return new TITLE;	//
	}

	return this;	//���݂̃V�[����Ԃ�(�Q�[�����C��)
}

void GameMain::Draw() const {
	player.Draw();

	DrawString(300, 10, "GameMain", 0xFFFFFF);

}