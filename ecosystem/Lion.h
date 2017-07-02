#pragma once
#include "Animal.h"
#include "Tiger.h"
class Lion :
	public Animal
{
public:
	Lion();
	bool isPredator() { return true; }; //是否是捕食者
	int eat(Animal* other, QString& text);  //默认调用默认规则，子类可覆盖该方法
	~Lion();
};

