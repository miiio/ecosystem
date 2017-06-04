#pragma once
#include "Animal.h"
class Tiger :
	public Animal
{
public:
	Tiger();
	Tiger(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Tiger();
	int eat(Animal* other);
};

