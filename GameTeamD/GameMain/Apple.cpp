#include"Apple.h"

int RINGO()
{
	int red, blue, gold, poison;
	red = DrawCircle(0, 0, 80, 0xff0000, TRUE);
	blue = DrawCircle(100, 100, 80, 0x00ff00, TRUE);
	gold = DrawCircle(200, 200, 80, 0xffd700, TRUE);
	poison = DrawCircle(300, 300, 80, 0xff00ff, TRUE);

	DrawGraph(100, 300, red, FALSE);
	DrawGraph(200, 300, blue, FALSE);
	DrawGraph(300, 300, gold, FALSE);
	DrawGraph(400, 300, poison, FALSE);

	return 0;
}


