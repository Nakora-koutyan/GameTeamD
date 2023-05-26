#pragma once
#include"DxLib.h"

class UI
{
private:
	float x, y;

	int width;
	int height;

	int score;
	int time;
	int acqu;
public:
	UI();

	void Update();
	void Draw() const;

	void SetTime(int time) { this->time = time; }
	void AddScore(int score) { this->score += score; }
	void AddAcqu(int acqu) { this->acqu = acqu; }
};

