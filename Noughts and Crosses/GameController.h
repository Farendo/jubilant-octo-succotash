#pragma once
#include <cstdlib>
#include <iostream>

class GM {
private:
	bool playerTurn = true;
	bool ShouldExit = false;

public:
	GM();
	~GM();

	bool GetPlayerTurn();
	void SetPlayerTurn();

	void Start();
	void Restart();
	void Close();
};