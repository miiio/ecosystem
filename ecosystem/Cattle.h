#pragma once
#include "Animal.h"
class Cattle :
	public Animal
{
public:
	Cattle();
	Cattle(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Cattle();
	int eat(Animal* other);
};

