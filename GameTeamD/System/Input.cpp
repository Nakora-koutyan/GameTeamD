#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int M_INPUT::Input() {

	// 背景読込
	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;		//表示失敗したら-1を返す
	//if ((gRankingImg = LoadGraph("Material/Images/Ranking.png")) == -1) return -1;		//表示失敗したら-1を返す

	/* リンゴの画像読込 */
	if ((gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png")) == -1) return -1;
	if ((gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png")) == -1) return -1;
	if ((gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png")) == -1) return -1;
	if ((gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png")) == -1) return -1;

	/*キャラクターの画像読込*/

	if ((gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav")) == -1) return -1;	//表示失敗したら-1を返す

	return 0;
}