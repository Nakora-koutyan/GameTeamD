#pragma once
class M_INPUT
{
public:
	int gMainBGM; /*LoadSoundMem("Material/Sounds/BGM/GameMain.wav");*/
	int gBackScreen;
	int gApple[4]; // ƒŠƒ“ƒS	if((gPlayerImg = LoadGraph("Material/Images/charactorWalk02.png"))==-1)return -1;

	int Input();
};