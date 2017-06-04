#pragma once
#include "Animal.h"
class Pig :
	public Animal
{
public:
	Pig();
	Pig(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Pig();
	int eat(Animal* other);
};

