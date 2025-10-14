#pragma once
#include <iostream>
#include <vector>
#include <ctime>

enum CellType
{
    EMPTY,
    CROSS,
    NOUGHT
};

class Board
{
    std::vector<std::vector<CellType>> board;
    size_t boardSize = 3;
    CellType playerType = EMPTY;
    CellType aiType = EMPTY;
    bool playerTurn = true;

public:
    Board();
    ~Board();

    CellType& operator()(int row, int col);


    CellType GetAIType();
    CellType GetPlayerType();
    void UpdateBoard();
    void SetBoardCell(CellType type, int Row, int Columns);
    void SetBoardSize(size_t BS);
    size_t GetBoardSize();
    bool GetPlayerTurn();
    void SetPlayerTurn();
    bool RandTurn();
    bool CheckWin(CellType type);
    bool CheckDraw();
    bool IsValidMove(int r, int c);
    bool isEmptyBoard();
    std::vector<std::vector<CellType>>& GetBoard();
};