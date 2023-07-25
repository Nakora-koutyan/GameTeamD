#include "UI.h"

UI::UI()
{
	this->score = 0;
	this->time = 60;
	x = 1280 - 300;
	y = 0;
	height = 720;
	width = 300;
}

void UI::Update()
{

}

void UI::Draw() const
{
	DrawBox((int)x, (int)y, (int)x + width, (int)y + height, 0xFF00FF, TRUE);

	DrawFormatString((int)x + 90, 20, 0x000000, "スコア : %d", score);
	DrawFormatString((int)x + 90, 50, 0x000000, "タイム : %d", time);
	DrawFormatString((int)x + 90, 80, 0x000000, "赤リンゴ : %d\n青リンゴ : %d\n金リンゴ : %d\n", acqu[0], acqu[1],acqu[2]);
}
