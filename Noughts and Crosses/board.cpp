#include "board.h"
#include "InputController.h"

Board::Board()
{
	board.resize(boardSize, std::vector<CellType>(boardSize, EMPTY));
};
Board::~Board() {};


CellType& Board::operator()(int row, int col)
{
	return board[row][col];
}

void Board::characterInitialization(bool turn)
{
	if (turn)
	{
		playerType = CROSS;
		aiType = NOUGHT;
	}
	else
	{
		playerType = NOUGHT;
		aiType = CROSS;
	}
}

void Board::UpdateBoard()
{
	std::cout << "Noughts and Crosses\n";
	std::cout << '\n';

	if (GetPlayerType() == CROSS)
		std::cout << "You play: X\n\n";
	else
		std::cout << "You play: O\n\n";

	for (size_t i = 0; i < boardSize; i++) {
		for (size_t j = 0; j < boardSize; j++) {
			if (j == 0)
			{
				switch (board[i][j])
				{
				case EMPTY:
					std::cout << ' ' << ' ' << " | ";
					break;
				case NOUGHT:
					std::cout << ' ' << 'O' << " | ";
					break;
				case CROSS:
					std::cout << ' ' << 'X' << " | ";
					break;
				default:
					break;
				}
			}
			else if (j == boardSize - 1)
			{
				switch (board[i][j])
				{
				case EMPTY:
					std::cout << ' ' << ' ';
					break;
				case NOUGHT:
					std::cout << 'O' << ' ';
					break;
				case CROSS:
					std::cout << 'X' << ' ';
					break;
				default:
					break;
				}
			}
			else
			{
				switch (board[i][j])
				{
				case EMPTY:
					std::cout << ' ' << " | ";
					break;
				case NOUGHT:
					std::cout << 'O' << " | ";
					break;
				case CROSS:
					std::cout << 'X' << " | ";
					break;
				default:
					break;
				}
			}
		}
		if (i < boardSize - 1)
			std::cout << "\n---+---+---";
		std::cout << '\n';
	}
}

void Board::SetBoardCell(CellType type, int row, int columns)
{
	board[row - 1][columns - 1] = type;
}
void Board::SetBoardSize(size_t BS)
{
	boardSize = BS;
}
bool Board::RandTurn()
{
	srand(time(nullptr));
	return rand() % 2;
}
bool Board::CheckWin(CellType type)
{
	bool leftD = true, rightD = true;

	for (size_t i = 0; i < boardSize; i++)
	{
		leftD &= (board[boardSize - i - 1][i] == type);
	}
	if (leftD == true)
		return true;

	for (size_t i = 0; i < boardSize; i++)
	{
		rightD &= (board[i][i] == type);
	}
	if (rightD == true)
		return true;

	for (size_t i = 0; i < boardSize; i++)
	{
		bool rows = true, cols = true;
		for (size_t j = 0; j < boardSize; j++)
		{
			rows = rows && (board[i][j] == type);
			cols = cols && (board[j][i] == type);
		}

		if (rows || cols)
			return true;
	}

	return false;
}
bool Board::CheckDraw()
{
	for (size_t i = 0; i < boardSize; i++) {
		for (size_t j = 0; j < boardSize; j++) {
			if (board[i][j] == EMPTY)
				return false;
		}
	}
	return true;
}


bool Board::IsValidMove(int r, int c)
{
	r--;
	c--;
	if ((r >= 0 && r < boardSize) && (c >= 0 && c < boardSize) && board[r][c] == EMPTY)
		return true;
	return false;

}

CellType Board::GetPlayerType() { return playerType; }
CellType Board::GetAIType() { return aiType; }
size_t Board::GetBoardSize() { return boardSize; }

std::vector<std::vector<CellType>>& Board::GetBoard()
{
	return board;
}

bool Board::isEmptyBoard()
{
	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			if (board[i][j] != EMPTY)
				return false;
		}
	}
	return true;
}


void Board::UpdateArrayFreeCells()
{
	freeCells.clear();
	freeCells.reserve(GetBoardSize() * GetBoardSize());
	for (int i = 0; i < GetBoardSize(); i++)
	{
		for (int j = 0; j < GetBoardSize(); j++)
		{
			if (board[i][j] == EMPTY)
			{
				freeCells.emplace_back(i, j);
			}
		}
	}
}

int Board::GetSizeFreeCells()
{
	return freeCells.size();
}

std::pair<int, int> Board::GetFreeCell(int count)
{
	return freeCells[count];
}