#include "GameController.h"
#include "board.h"
#include "InputController.h"
#include "AI.h"




GM::GM() {};
GM::~GM() {};

bool GM::GetPlayerTurn()
{
	return playerTurn;
}

void GM::SetPlayerTurn()
{
	playerTurn = !playerTurn;
}

void GM::Start()
{
	Board gameBoard;
	InputController IC;
	AI gameAI;

	playerTurn = gameBoard.RandTurn();

	gameBoard.SetBoardSize(3);
	gameBoard.characterInitialization(GetPlayerTurn());
	gameBoard.UpdateBoard();
	while (!ShouldExit)
	{
		system("cls");
		gameBoard.UpdateBoard();

		if (gameBoard.CheckDraw())
		{
			std::cout << "\nDraw :(\n";
			break;
		}

		if (GetPlayerTurn())
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

			SetPlayerTurn();
		}
		else
		{
			gameAI.logicAI(gameBoard);

			gameBoard.SetBoardCell(gameBoard.GetAIType(), gameAI.GetRow(), gameAI.GetColumn());

			if (gameBoard.CheckWin(gameBoard.GetAIType()))
			{
				system("cls");
				gameBoard.UpdateBoard();
				std::cout << "\nUnlucky! You Lose!\n";
				break;
			}
			SetPlayerTurn();
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
	ShouldExit = true;
}


