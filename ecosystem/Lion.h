#pragma once
#include "Animal.h"
#include "Tiger.h"
class Lion :
	public Animal
{
public:
	Lion();
	bool isPredator() { return true; }; //�Ƿ��ǲ�ʳ��
	int eat(Animal* other, QString& text);  //Ĭ�ϵ���Ĭ�Ϲ�������ɸ��Ǹ÷���
	~Lion();
};

