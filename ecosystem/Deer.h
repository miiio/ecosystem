#pragma once
#include "Animal.h"
class Deer :
	public Animal
{
public:
	Deer();
	Deer(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Deer();
	int eat(Animal* other);
};

