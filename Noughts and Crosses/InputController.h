#pragma once
#include<iostream>

class InputController {
private:
	int row = -1, column = -1;
public:
	InputController();
	~InputController();
	friend std::istream& operator>>(std::istream& in, InputController& IC);
	int GetRow();
	int GetColumn();
	void SetVector2(int newRow, int newColumn);
};