#pragma once
#include "Animal.h"
class Chick :
	public Animal
{
public:
	Chick();
	bool isPredator() { return false; }; //是否是捕食者
	/*Chick(int x, int y, int hp, int age, int rank, QString name,
		QString sex, int speed, int attackrange, int creattime, int size);*/
	~Chick();
};

