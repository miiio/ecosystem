#pragma once
#include "Animal.h"
class Elephant :
	public Animal
{
public:
	Elephant();
	bool isPredator() { return false; }; //是否是捕食者
	virtual int reproduce(Animal* other, SettingData* sd, QString& text); //繁殖规则，返回数量
	~Elephant();
};

