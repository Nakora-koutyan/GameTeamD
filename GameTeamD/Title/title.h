#pragma once
class TITLE
{
public:
	int gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
	int gBackScreen = LoadGraph("Material/Images/Title.png");


	void print();
};

