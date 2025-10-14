#pragma once
#include <ctime>
#include <random>
#include "board.h"

class AI
{
private:
	int row = -1, column = -1;
public:
	AI();
	~AI();
	int GetRow();
	int GetColumn();
	void SetVector2(int r, int c);
	int	RandAI(int number);

	bool CheckWinMove(Board& board, CellType AItype);
	bool CheckBlockMove(Board& board);

	void logicAI(Board& board);
};
