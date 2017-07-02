#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf();
	bool isPredator() { return true; }; //是否是捕食者
	int eat(Animal* other, QString& text);
	~Wolf();
};

