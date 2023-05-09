#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	// ”wŒi“Ç
	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;
	/* ƒŠƒ“ƒS‚Ì‰æ‘œ“Ç */
	if ((gApple[0] = LoadGraph("Material/Images/Apple_Red.png")) == -1) return -1;
	if ((gApple[1] = LoadGraph("Material/Images/Apple_Green.png")) == -1) return -1;
	if ((gApple[2] = LoadGraph("Material/Images/Apple_Gold.png")) == -1) return -1;
	if ((gApple[3] = LoadGraph("Material/Images/Apple_Poison.png")) == -1) return -1;

	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;
	if ((gTitleBGM = LoadSoundMem("Material/Sounds/BGM/Title.wav")) == -1) return -1;
}