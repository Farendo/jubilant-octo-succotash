#pragma once

#include <iostream>

class Tamagochi {
protected:
	const int defCheerfulness = 50, defMaxCheerfulness = 150, defHP = 50, defMaxHP = 100;
	int cheerfulness, maxCheerfulness, HP, maxHP;

public:
	Tamagochi();
	Tamagochi(float ratio);
	virtual ~Tamagochi();

	virtual void feedTamagochi() = 0;
	virtual void playWithTamagochi() = 0;
	virtual void playSound() = 0;

	int GetHP();
	int GetCheerfulness();
	int GetMaxHP();
	int GetMaxCheerfulness();
	bool isAlive();
};

class Cat : public Tamagochi {
protected:
	const int balanceHP = 15, balanceCheer = 10;

public:
	Cat();
	Cat(float catRatio);
	~Cat();


	void feedTamagochi() override;
	void playWithTamagochi() override;
	void playSound() override;
};

class Dog : public Tamagochi {
protected:
	const int balanceHP = 20, balanceCheer = 25;

public:
	Dog();
	Dog(float dogRatio);
	~Dog();

	void feedTamagochi() override;
	void playWithTamagochi() override;
	void playSound() override;
};

class Fish : public Tamagochi {
protected:
	const int balanceHP = 8, balanceCheer = 5;
public:
	Fish();
	Fish(float fishRatio);
	~Fish();

	void feedTamagochi() override;
	void playWithTamagochi() override;
	void playSound() override;
};

void ClearConsole();
void FooGame(Tamagochi& pet);
