#include "GameController.h"
#include "board.h"
#include "InputController.h"
#include "AI.h"




GM::GM() {};
GM::~GM() {};
void GM::Start()
{
	Board gameBoard;
	InputController IC;
	AI gameAI;


	gameBoard.SetBoardSize(3);

	gameBoard.UpdateBoard();
	while (true)
	{
		system("cls");
		gameBoard.UpdateBoard();

		if (gameBoard.CheckDraw())
		{
			std::cout << "\nDraw :(\n";
			break;
		}

		if (gameBoard.GetPlayerTurn())
		{
			std::cout << "Write row and column(e.g.2  2): ";
			while (!gameBoard.IsValidMove(IC.GetRow(), IC.GetColumn()))
			{
				std::cin >> IC;
				if (!gameBoard.IsValidMove(IC.GetRow(), IC.GetColumn())) {
					std::cout << "You write wrong row or columns.Try again: ";
				}
			}
			gameBoard.SetBoardCell(gameBoard.GetPlayerType(), IC.GetRow(), IC.GetColumn());

			if (gameBoard.CheckWin(gameBoard.GetPlayerType()))
			{
				system("cls");
				gameBoard.UpdateBoard();
				std::cout << "\nGood Job! You Win!\n";
				break;
			}

			gameBoard.SetPlayerTurn();
		}
		else
		{
			do {
				gameAI.logicAI(gameBoard);
			} while (!gameBoard.IsValidMove(gameAI.GetRow(), gameAI.GetColumn()));

			gameBoard.SetBoardCell(gameBoard.GetAIType(), gameAI.GetRow(), gameAI.GetColumn());

			if (gameBoard.CheckWin(gameBoard.GetAIType()))
			{
				system("cls");
				gameBoard.UpdateBoard();
				std::cout << "\nUnlucky! You Lose!\n";
				break;
			}
			gameBoard.SetPlayerTurn();
		}
	}

	if (gameBoard.CheckDraw())
	{
		system("cls");
		gameBoard.UpdateBoard();
		std::cout << "\nDraw :(\n";
	}

	char playAgain;
	std::cout << "\n\n\nPlay again? (y/n): ";
	std::cin >> playAgain;
	if (playAgain == 'y' || playAgain == 'Y') {
		Restart();
	}
	else {
		Close();
	}
}

void GM::Restart()
{
	Start();
}

void GM::Close()
{
	std::exit(0);
}


