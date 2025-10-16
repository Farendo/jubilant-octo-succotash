#include "AI.h"


AI::AI() {};
AI::~AI() {};

int AI::GetRow()
{
	return row;
}

int AI::GetColumn()
{
	return column;
}

void AI::SetVector2(int r, int c)
{
	row = r;
	column = c;
}

std::mt19937& AI::get_generator()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return gen;
}

int AI::RandAI(int number) {
	std::uniform_int_distribution<int> distrib(0, number - 1);
	return distrib(get_generator());
}

bool AI::CheckWinMove(Board& board, CellType AItype) {
	for (int i = 0; i < 3; i++) {
		if (board(i, 0) == AItype && board(i, 1) == AItype && board(i, 2) == 0)
		{
			SetVector2(i + 1, 2 + 1);
			return true;
		}
		if (board(i, 0) == AItype && board(i, 2) == AItype && board(i, 1) == 0)
		{
			SetVector2(i + 1, 1 + 1);
			return true;
		}
		if (board(i, 1) == AItype && board(i, 2) == AItype && board(i, 0) == 0)
		{
			SetVector2(i + 1, 0 + 1);
			return true;
		}
	}

	for (int j = 0; j < 3; j++) {
		if (board(0, j) == AItype && board(1, j) == AItype && board(2, j) == 0)
		{
			SetVector2(2 + 1, j + 1);
			return true;
		}
		if (board(0, j) == AItype && board(2, j) == AItype && board(1, j) == 0)
		{
			SetVector2(1 + 1, j + 1);
			return true;
		}
		if (board(1, j) == AItype && board(2, j) == AItype && board(0, j) == 0)
		{
			SetVector2(0 + 1, j + 1);
			return true;
		}
	}

	if (board(0, 0) == AItype && board(1, 1) == AItype && board(2, 2) == 0)
	{
		SetVector2(2 + 1, 2 + 1);
		return true;
	}
	if (board(0, 0) == AItype && board(2, 2) == AItype && board(1, 1) == 0)
	{
		SetVector2(1 + 1, 1 + 1);
		return true;
	}
	if (board(1, 1) == AItype && board(2, 2) == AItype && board(0, 0) == 0)
	{
		SetVector2(0 + 1, 0 + 1);
		return true;
	}

	if (board(0, 2) == AItype && board(1, 1) == AItype && board(2, 0) == 0)
	{
		SetVector2(2 + 1, 0 + 1);
		return true;
	}
	if (board(0, 2) == AItype && board(2, 0) == AItype && board(1, 1) == 0)
	{
		SetVector2(1 + 1, 1 + 1);
		return true;
	}
	if (board(1, 1) == AItype && board(2, 0) == AItype && board(0, 2) == 0)
	{
		SetVector2(0 + 1, 2 + 1);
		return true;
	}

	return false;
}


bool AI::CheckBlockMove(Board& board) {
	return CheckWinMove(board, board.GetPlayerType());
}

void AI::logicAI(Board& board)
{
	//Реализация первого хода за X
	if (board.isEmptyBoard())
	{
		//тогда мы понимаем что у нас два пути, либо в центр(1), либо в угол(0)
		if (RandAI(2))
		{
			SetVector2(2, 2);
		}
		else
		{
			switch (RandAI(4))
			{
			case 0:
				//лево-верх 
				SetVector2(1, 1);
				break;
			case 1:
				//лево-низ 
				SetVector2(3, 1);
				break;
			case 2:
				//право-верх 
				SetVector2(1, 3);
				break;
			case 3:
				//право-низ 
				SetVector2(3, 3);
				break;
			default:
				break;
			}
		}
		return;
	}

	//если центр свободен, то с шансом в 50% займёт его
	if (RandAI(2) && board(1, 1) == EMPTY) {
		SetVector2(1, 1);
		return;
	}

	//тут проверка на победу AI, если находит такой ход, то ходит туда
	if (CheckWinMove(board, board.GetAIType())) { return; }

	//тут проверка на победу человека, если находит такой ход, то ходит чтобы заблокировать
	if (CheckBlockMove(board)) { return; }

	//тут уже просто рандомный ход
	board.UpdateArrayFreeCells();
	int randomIndex = RandAI(board.GetSizeFreeCells());
	std::pair<int, int > moveAI = board.GetFreeCell(randomIndex);
	SetVector2(moveAI.first + 1, moveAI.second + 1);
}




