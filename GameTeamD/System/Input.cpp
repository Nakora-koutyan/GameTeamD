#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	// �w�i�Ǎ�
	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;		//�\�����s������-1��Ԃ�
	/* �����S�̉摜�Ǎ� */
	if ((gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png")) == -1) return -1;
	if ((gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png")) == -1) return -1;
	if ((gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png")) == -1) return -1;
	if ((gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png")) == -1) return -1;

	/*�L�����N�^�[�̉摜�Ǎ�*/

	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;	//�\�����s������-1��Ԃ�

	return 0;
}