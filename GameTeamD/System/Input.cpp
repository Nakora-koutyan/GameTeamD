#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	// ”wŒi“Ç
	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;		//•\¦¸”s‚µ‚½‚ç-1‚ğ•Ô‚·
	/* ƒŠƒ“ƒS‚Ì‰æ‘œ“Ç */
	if ((gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png")) == -1) return -1;
	if ((gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png")) == -1) return -1;
	if ((gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png")) == -1) return -1;
	if ((gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png")) == -1) return -1;

	/*ƒLƒƒƒ‰ƒNƒ^[‚Ì‰æ‘œ“Ç*/

	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;	//•\¦¸”s‚µ‚½‚ç-1‚ğ•Ô‚·

	return 0;
}