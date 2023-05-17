#include<stdio.h>
#include"DxLib.h"
#include"Title.h"

void TITLE::print()
{
	if (CheckSoundMem(gTitleBGM) != 1)
	{
		SetLoopSamplePosSoundMem(109696, gTitleBGM);
		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	}

	if (gGameMode == E_TITLE);
	{
		if (GetKeyDown(PAD_INPUT_DOWN)) {
			if (++g_MenuNumber > 3) g_MenuNumber = 0;
			DrawBox(300, 300, 400, 400, 0xFFFFFF, 1);
			//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
		}
		if (GetKeyDown(PAD_INPUT_UP)) {
			if (--g_MenuNumber < 0) g_MenuNumber = 3;
			//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
		}

		DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);

		if (GetKeyDown(PAD_INPUT_A)) {
			switch (g_MenuNumber)
			{
			case 0:
				gGameMode = E_INIT;
				DrawFormatString(300, 100, 0xFFFFFF, "init");
				break;
			case 1:
				gGameMode = E_RANKING;
				break;
			case 2:
				gGameMode = E_HELP;
				break;
			case 3:
				gGameMode = E_END;
				break;
			}
		}

		DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
	}
	if (gGameMode == E_INIT) {
		DrawFormatString(300, 10, 0xFFFFFF, "init");
	}
	if (gGameMode == E_RANKING) {
		DrawFormatString(300, 10, 0xFFFFFF, "rank");
	}
	if (gGameMode == E_HELP) {
		DrawFormatString(300, 10, 0xFFFFFF, "help");
	}
	if (gGameMode == E_END) {
		DrawFormatString(300, 10, 0xFFFFFF, "end");
	}
}