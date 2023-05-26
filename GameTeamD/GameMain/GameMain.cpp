#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"
#include"../Title/title.h"
#include "../System/Input.h"
#define TIMELIMIT = 60;


GameMain::GameMain()
{
	// BGM�Ǎ�
	gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
	gGameBackScreen = LoadGraph("Material/Images/BackImage.png");

	// gMainBGM������ĂȂ��Ȃ痬��
	if (CheckSoundMem(gMainBGM) != 1)
	{
		SetLoopSamplePosSoundMem(371945, gMainBGM);
		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
	}

	//�w�i�摜�Ǎ�
	gGameBackScreen = LoadGraph("Material/Images/BackImage.png");
	gTimeOver = LoadGraph("Material/Images/TimeOver.png");
	/* �����S�摜�Ǎ� */
	gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png");
	gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png");
	gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png");
	gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png");
	/* �����S����SE */
	gRingoSE = LoadSoundMem("Material/Sounds/SE/�p���[�A�b�v.wav");
	gPoisonRingoSE = LoadSoundMem("Material/Sounds/SE/�ŏ��.wav");

	AppleCount[0] = 0;
	AppleCount[1] = 0;
	AppleCount[2] = 0;
	AppleCount[3] = 0;

	//�c�莞�Ԃ�`�悷��
	TimeOver = FALSE;
}

GameMain::~GameMain()	//�f�X�g���N�^
{
	DeleteSoundMem(gMainBGM);

	for (int i = 0; i < 4; i++) {
		DeleteGraph(gAppleImg[i]);
	}
}

AbstractScene* GameMain::Update() //�Q�[�����C���̃A�b�v�f�[�g
{
	player.Update();	//�v���C���[�̍X�V

	CreateApple();

	for(int i=0; i<APPLE_MAX;i++)
	{
		apple[i].AppleControl();

		if (HitBoxPlayer(&player, &apple[i]) == TRUE)
		{
			apple[i].flg = FALSE;
			if (apple[i].img!=gAppleImg[3]) // �Ń����S����ĂȂ��Ƃ�
			{
				if (CheckSoundMem(gRingoSE) == 0)
				{	
					PlaySoundMem(gRingoSE, DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem(123, gRingoSE);
				}
			}
			else // �Ń����S��������Ƃ�
			{
				PlaySoundMem(gPoisonRingoSE, DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem(255, gPoisonRingoSE);
			}
			/* ����������S���J�E���g */
			if (apple[i].type == 0)      // ����������S���Ԃ������Ƃ�
			{
				AppleCount[0]++;           // �ԃ����S�̐���1���Z
			}
			else if (apple[i].type == 1)  // ����������S���������Ƃ�
			{
				AppleCount[1]++;		   // �����S�̐���1���Z
			}
			else if (apple[i].type == 2)  // ����������S�����������Ƃ�
			{
				AppleCount[2]++;		   // �������S�̐���1���Z
			}
			else						   // ����������S���ł������Ƃ�
			{
				AppleCount[3]++;		    // �Ń����S�̐���1���Z
			}
		}
	}

	if(FlmCnt++ % 60)second += 1;

	if (second >= 60) TimeOver = TRUE;

	//if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {
	//	return new TITLE;	//
	//}

	ui.SetTime(second);
	ui.AddAcqu(AppleCount);

	return this;	//���݂̃V�[����Ԃ�(�Q�[�����C��)
}

void GameMain::Draw() const 
{

	DrawGraph(0, 0, gGameBackScreen, FALSE);

	player.Draw();
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i].Draw();
	}
	DrawString(300, 10, "GameMain", 0xFFFFFF);

	if (TimeOver)
	{
		DrawGraph(0, 0, gTimeOver, FALSE);
	}
	DrawFormatString(900, 100, 0xffffff, "%3d");

	ui.Draw();
}

int GameMain::CreateApple()
{

	for (int i = 0; i < APPLE_MAX; i++) {
		if (apple[i].flg == FALSE) {
			apple[i] = {};
			apple[i].flg = TRUE; // �摜��ON�ɂ���
			apple[i].type = AppleProd(); // �����Ŋm���o��
			apple[i].img = gAppleImg[apple[i].type]; // �����S�̉摜����
			apple[i].SetLocation(Location{ float(GetRand(6) * 120 + 100), 0}); // ���[����X  // y����0�ɐݒ�


			switch (apple[i].type)
			{
			case 0:
				// �ԃ����S�o��
				apple[i].speed = 1;           // �X�s�[�h��ݒ�
				apple[i].magnification = 1.1; // �����蔻��̔{���ݒ�
				//apple[i].count += 1;		  // �J�E���g�ɂP���Z
				//apple[i].point += 100;	  // �|�C���g��100���Z
				break;

			case 1:
				// �����S�o��
				apple[i].speed = 3;			  // �X�s�[�h��ݒ�
				apple[i].magnification = 1.1; // �����蔻��̔{���ݒ�
				//apple[i].point += 200;        // �|�C���g��200���Z
				break;						  
				
			case 2:
				// �������S�o��
				apple[i].speed = 5;			  // �X�s�[�h��ݒ�
				apple[i].magnification = 1.1; // �����蔻��̔{���ݒ�
				//apple[i].point += 500;        // �|�C���g��500���Z
				break;

			case 3:
				// �Ń����S�o��
				apple[i].speed = 0.5;		  // �X�s�[�h��ݒ�
				apple[i].magnification = 0.9; // �����蔻��̔{���ݒ�
				//apple[i].point -= 750;		  // �|�C���g��750���Z
				break;
			}


			// ����
			return TRUE;
		}
	}

	// ���s
	return FALSE;
}

int GameMain::AppleProd()     // �����S�̐�����
{

	int rand = GetRand(19);
	if (rand < 11) {
		return 0;
	}
	else if (rand < 16) {
		return 1;
	}
	else if (rand < 18) {
		return 2;
	}
	else {
		return 3;
	}
}

int GameMain::HitBoxPlayer(BoxCollider* p, APPLE* a)
{	// x,y�͒��S���W�Ƃ���
	int sx1 = p->GetLocation().x - (p->GetErea().width / 2);
	int sy1 = p->GetLocation().y - (p->GetErea().height / 2);
	int sx2 = sx1 + p->GetErea().width;
	int sy2 = sy1 + p->GetErea().height;

	/* �ԁA�A��,�Ń����S�̓����蔻��*/
	int ax1 = a->GetLocation().x - (a->GetErea().width / 2 * a->magnification);
	int ay1 = a->GetLocation().y - (a->GetErea().height / 2 * a->magnification);
	int ax2 = ax1 + a->GetErea().width * a->magnification;
	int ay2 = ay1 + a->GetErea().height * a->magnification;

	if (sx1 < ax2 && ax1 < sx2 && sy1 < ay2 && ay1 && sy2)
	{
		return TRUE;
	}
	return FALSE;
	/*DrawGraph(0, 0, gGameBackScreen,0);
	player.Draw();
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i].Draw();
	}
	DrawFormatString(100, 100, 0xffffff, "%f", player.Speed);*/
}