#pragma once
#include "Animal.h"
class Elephant :
	public Animal
{
public:
	Elephant();
	bool isPredator() { return false; }; //�Ƿ��ǲ�ʳ��
	virtual int reproduce(Animal* other, SettingData* sd, QString& text); //��ֳ���򣬷�������
	~Elephant();
};

