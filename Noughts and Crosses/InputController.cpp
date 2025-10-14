#include "InputController.h"


InputController::InputController() {};
InputController::~InputController() {};

std::istream& operator>>(std::istream& in, InputController& IC)
{
    int r, c;
    in >> r >> c;
    IC.SetVector2(r, c);
    return in;
}
int InputController::GetRow()
{
    return row;
}

int InputController::GetColumn()
{
    return column;
}

void InputController::SetVector2(int newRow, int newColumn)
{
    row = newRow;
    column = newColumn;
}


