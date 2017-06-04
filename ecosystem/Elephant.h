#pragma once
#include "Animal.h"
class Elephant :
	public Animal
{
public:
	Elephant();
	Elephant(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);
	~Elephant();
	int eat(Animal* other);
};

