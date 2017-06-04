#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf();
	Wolf(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Wolf();
	int eat(Animal* other);
};

