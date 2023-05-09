#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;
	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;
	/* ƒŠƒ“ƒS‚Ì‰æ‘œ“Ç */
	if ((gRedApple = LoadGraph("Material/Images/Apple5.png")) == -1) return -1;
	if ((gBlueApple = LoadGraph("Material/Images/Apple03.png")) == -1) return -1;
	if ((gGoldApple = LoadGraph("Material/Images/Apple01.png")) == -1) return -1;
	if ((gPoisonApple = LoadGraph("Material/Images/Apple02.png")) == -1) return -1;
}