#pragma once
#include "Animal.h"
class Cattle :
	public Animal
{
public:
	Cattle();
	bool isPredator() { return false; }; //�Ƿ��ǲ�ʳ��
	/*Cattle(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);*/
	~Cattle();
};

