#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



class MyWordle
{
	int rows;
	int columns;
	vector<vector<char>> WordleCell;
	char RandomChar()
	{
		int randNum = 97 + rand() % 26;
		return static_cast<char> (randNum);
	}
	void initializeWordle()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				WordleCell[i][j] = RandomChar();
			}
		}
	}
public:
	MyWordle() : rows(3), columns(3), WordleCell(rows, vector<char>(columns))
	{
		initializeWordle();
	};
	MyWordle(size_t _rows, size_t _columns) : rows(_rows < 3 ? 3 : _rows), columns(_columns < 3 ? 3 : _columns), WordleCell(rows, vector<char>(columns))
	{
		initializeWordle();
	};

	void PrintWordle() {
		for (int i = 0; i < WordleCell.size(); i++)
		{
			for (int j = 0; j < WordleCell[0].size(); j++)
			{
				cout << WordleCell[i][j] << ' ';
			}
			cout << endl;
		}
	}
};




int main() {
	srand(time(nullptr));
	MyWordle a(5, 10);
	a.PrintWordle();
	return 0;
}