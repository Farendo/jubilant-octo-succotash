#include "Tamagochi.h"
#include <iostream>

using namespace std;

int main() {
	int enter = 0;
	while (true) {
		ClearConsole();
		cout << "choose ur animal:\n" << "1. Cat\n" << "2. Dog\n" << "3. Fish\n";
		cin >> enter;
		switch (enter)
		{
		case 1:
		{
			const float catRatio = 1.0;
			Cat c(catRatio);
			FooGame(c);
			break;
		}
		case 2:
		{
			const float dogRatio = 1.2;
			Dog d(dogRatio);
			FooGame(d);
			break;
		}
		case 3:
		{
			const float fishRatio = 0.8;
			Fish f(fishRatio);
			FooGame(f);
			break;
		}
		default:
			cout << "Wrong animal\n";
			cout << "Press Enter to continue";
			cin.ignore();
			cin.get();
			break;
		}
	}
	return 0;
}