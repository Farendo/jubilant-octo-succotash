#include "Tamagochi.h"
#include <algorithm>

using namespace std;

Tamagochi::Tamagochi() : cheerfulness(defCheerfulness), maxCheerfulness(defMaxCheerfulness), HP(defHP), maxHP(defMaxHP) {};
Tamagochi::Tamagochi(float ratio) {
	HP = defHP * ratio;
	maxHP = defMaxHP * ratio;
	cheerfulness = defCheerfulness * ratio;
	maxCheerfulness = defMaxCheerfulness * ratio;
};
Tamagochi::~Tamagochi() {};

int Tamagochi::GetHP() { return HP; }
int Tamagochi::GetCheerfulness() { return cheerfulness; }
int Tamagochi::GetMaxHP() { return maxHP; }
int Tamagochi::GetMaxCheerfulness() { return maxCheerfulness; }
bool Tamagochi::isAlive() { return HP > 0 && cheerfulness > 0; }


Cat::Cat() : Tamagochi() {};
Cat::Cat(float catRatio) : Tamagochi(catRatio) {};
Cat::~Cat() {};

void Cat::feedTamagochi() {
	HP = min(maxHP, HP + balanceHP);
	cheerfulness = max(0, cheerfulness - balanceCheer);
};
void Cat::playWithTamagochi() {
	cheerfulness = min(maxCheerfulness, cheerfulness + balanceCheer);
	HP = max(0, HP - balanceHP);
};
void Cat::playSound() {
	cout << "Meow";
};

Dog::Dog() : Tamagochi() {};
Dog::Dog(float dogRatio) : Tamagochi(dogRatio) {};
Dog::~Dog() {};

void Dog::feedTamagochi() {
	HP = min(maxHP, HP + balanceHP);
	cheerfulness = max(0, cheerfulness - balanceCheer);
};
void Dog::playWithTamagochi() {
	cheerfulness = min(maxCheerfulness, cheerfulness + balanceCheer);
	HP = max(0, HP - balanceHP);
};
void Dog::playSound() {
	cout << "Gav";
};


Fish::Fish() : Tamagochi() {};
Fish::Fish(float fishRatio) : Tamagochi(fishRatio) {};
Fish::~Fish() {};

void Fish::feedTamagochi() {
	HP = min(maxHP, HP + balanceHP);
	cheerfulness = max(0, cheerfulness - balanceCheer);
};
void Fish::playWithTamagochi() {
	cheerfulness = min(maxCheerfulness, cheerfulness + balanceCheer);
	HP = max(0, HP - balanceHP);
};
void Fish::playSound() {
	cout << "Bool'";
};


void ClearConsole() {
	for (int i = 0; i < 50; i++) {
		cout << '\n';
	}
}

void FooGame(Tamagochi& pet)
{
	int enter = 0;
	while (pet.isAlive())
	{
		ClearConsole();
		cout << "Stats: " << '\n' << pet.GetHP() << " HP / " << pet.GetMaxHP() << '\n' << pet.GetCheerfulness() << " Cheerfulness / " << pet.GetMaxCheerfulness() << '\n' << '\n';
		cout << "What you want to do?\n" << "1. Play with your pet\n" << "2. Feed your pet\n" << "3. stroke your pet\n";
		cin >> enter;
		switch (enter)
		{
		case 1:
			pet.playWithTamagochi();
			break;
		case 2:
			pet.feedTamagochi();
			break;
		case 3:
			pet.playSound();
			cin.ignore();
			cin.get();
			break;
		default:
			cout << "Wrong choose";
			break;
		}
	}
	ClearConsole();
	cout << "Your pet died\n";
	pet.playSound();
	cout << "\nPress Enter to close game";
	cin.ignore();
	cin.get();
}
