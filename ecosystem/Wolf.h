#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf();
	bool isPredator() { return true; }; //�Ƿ��ǲ�ʳ��
	int eat(Animal* other, QString& text);
	~Wolf();
};

