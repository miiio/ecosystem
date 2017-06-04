#pragma once
#include "Animal.h"
class Lion :
	public Animal
{
public:
	Lion();
	Lion(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Lion();
	int eat(Animal* other);
};

