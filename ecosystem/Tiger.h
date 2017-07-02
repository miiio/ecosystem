#pragma once
#include "Animal.h"
#include "Lion.h"
class Tiger :
	public Animal
{
public:
	Tiger();
	bool isPredator() { return true; }; //是否是捕食者
	int eat(Animal* other, QString& text); 
	~Tiger(); 
};

