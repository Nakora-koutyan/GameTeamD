#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;
	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;

}