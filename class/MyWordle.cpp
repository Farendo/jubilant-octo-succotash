#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



class MyWordle
{
	size_t rows;
	size_t columns;
	vector<vector<char>> WordleCell;
	char RandomChar()
	{
		int randNum = 97 + rand() % 26;
		return static_cast<char> (randNum);
	}
	void initializeWordle()
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				WordleCell[i][j] = RandomChar();
			}
		}
	}
	bool FindHorizontal(const string& word)
	{
		if (word.length() > columns) {
			return false;
		}
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j <= columns - word.length(); j++)
			{
				bool found = true;
				for (size_t k = 0; k < word.length(); k++)
				{
					if (WordleCell[i][j + k] != word[k])
					{
						found = false;
						break;
					}
				}
				if (found) {
					return true;
				}
			}
		}
		return false;
	}

	bool FindVertical(const string& word)
	{
		if (word.length() > rows) {
			return false;
		}
		for (size_t j = 0; j < columns; j++)
		{
			for (size_t i = 0; i <= rows - word.length(); i++)
			{
				bool found = true;
				for (size_t k = 0; k < word.length(); k++)
				{
					if (WordleCell[i + k][j] != word[k])
					{
						found = false;
						break;
					}
				}

				if (found) {
					return true;
				}
			}
		}
		return false;
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
		cout << endl;
		for (size_t i = 0; i < WordleCell.size(); i++)
		{
			for (size_t j = 0; j < WordleCell[0].size(); j++)
			{
				cout << WordleCell[i][j] << " | ";
			}
			cout << endl;
		}
	}

	bool FindWord(const string& word)
	{
		return FindHorizontal(word) || FindVertical(word);
	}
};




int main() {
	srand(time(nullptr));
	size_t rows, columns;
	string word;
	cout << "Write count rows: ";
	cin >> rows;
	cout << "\nWrite count columns: ";
	cin >> columns;
	MyWordle a(rows, columns);
	a.PrintWordle();
	while (true)
	{
		cout << "\nEnter word (or 'exit' for exit ;D): ";
		cin >> word;

		if (word == "exit") {
			break;
		}

		if (a.FindWord(word)) {
			cout << "Word: " << word << " Was found\n";
		}
		else {
			cout << "Word: " << word << " Dont found\n";
		}
	}
	return 0;

}