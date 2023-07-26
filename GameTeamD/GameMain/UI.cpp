#include "UI.h"

UI::UI()
{
	this->score = 0;
	this->time = 0;
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
	DrawBox(x, y, x + width, y + height, 0xFF00FF, TRUE);

	DrawFormatString(x + 90, 20, 0x000000, "�X�R�A : %d", score);
	DrawFormatString(x + 90, 50, 0x000000, "�^�C�� : %d", time);
	DrawFormatString(x + 90, 80, 0x000000, "�ԃ����S : %d\n�����S : %d\n�������S : %d\n�Ń����S : %d", acqu[0], acqu[1], acqu[2], acqu[3]);;
	DrawFormatString(x + 90, 200, 0x000000, "�X�R�A:%d\n", acqu[0] * 100 + acqu[1] * 200 + acqu[2] * 500 - acqu[3] * 750);
}

