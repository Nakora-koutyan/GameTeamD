#include"Apple.h"

int APPLE::RINGO()
{
	M_INPUT M;

	M.Input();

	DrawGraph(100, 200, M.gRedApple, FALSE);
	DrawGraph(200, 200, M.gBlueApple, FALSE);
	DrawGraph(300, 200, M.gGoldApple, FALSE);
	DrawGraph(400, 200, M.gPoisonApple, FALSE);


	/*int red, blue, gold, poison;
	red = DrawCircle(0, 0, 80, 0xff0000, TRUE);
	blue = DrawCircle(100, 100, 80, 0x00ff00, TRUE);
	gold = DrawCircle(200, 200, 80, 0xffd700, TRUE);
	poison = DrawCircle(300, 300, 80, 0xff00ff, TRUE);
	*/

	return 0;
}


