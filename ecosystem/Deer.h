#pragma once
#include "Animal.h"
class Deer :
	public Animal
{
public:
	Deer();
	bool isPredator() { return false; }; //�Ƿ��ǲ�ʳ��
	int eat(Animal* other, QString& text);
	~Deer();
};

