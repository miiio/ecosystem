#pragma once
#include "Animal.h"
#include "Lion.h"
class Tiger :
	public Animal
{
public:
	Tiger();
	bool isPredator() { return true; }; //�Ƿ��ǲ�ʳ��
	int eat(Animal* other, QString& text); 
	~Tiger(); 
};

