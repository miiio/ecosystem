#pragma once
#include "Animal.h"
class Deer :
	public Animal
{
public:
	Deer();
	bool isPredator() { return false; }; //是否是捕食者
	int eat(Animal* other, QString& text);
	~Deer();
};

