#pragma once
#include <cstdlib>
#include <iostream>

class GM {
private:
	bool playerTurn = true;

public:
	GM();
	~GM();

	bool GetPlayerTurn();
	void SetPlayerTurn();

	void Start();
	void Restart();
	void Close();
};