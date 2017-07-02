
#include "Organism.h"


Organism::Organism()
{
	setPreDirection(((rand() % (8 + 1)) + 0)); //随机生成0~8中的一个方向
}

QRect Organism::getRect()
{
	return QRect(mX, mY, mSize, mSize);
}


Organism::~Organism()
{
}



bool Organism::setX(int x)
{
	if (x < 0)
		return false;
	this->mX = x;
	return true;
}

bool Organism::setY(int y)
{
	if (y < 0)
		return false;
	this->mY = y;
	return true;
}

bool Organism::setPreDirection(int pre)
{
	if (pre < 0 || pre>8)
		return false;
	this->mPre = pre;
	return true;
}

bool Organism::setTotalHp(int hp_total)
{
	if (hp_total < 0)
		return false;
	this->mHp_total = hp_total;
	return true;
}

bool Organism::setHp(int hp_cur)
{
	if (hp_cur<0) 
		this->mHp_cur = 0; //血量低于0直接设为0
	else
		this->mHp_cur = hp_cur>mHp_total ? mHp_total : hp_cur; //血量溢出
	return true;
}

bool Organism::setAge(int age)
{
	if (age < 0)
		return false;
	this->mAge = age;
	return true;
}

bool Organism::setRank(int rank)
{
	this->mRank = rank;
	return true;
}

bool Organism::setTypeId(int typeId)
{
	this->mTypeId = typeId;
	return true;
}

bool Organism::setSize(int size)
{
	if (size < 0)
		return false;
	this->mSize = size;
	return true;
}

bool Organism::setCreatTime(int creattime)
{
	if (creattime < 0)
		return false;
	this->mCreatTime = creattime;
	return true;
}
bool Organism::setName(QString name)
{
	this->mName = name;
	return true;
}

bool Organism::addHp(int addhp)
{
	return setHp(getHp()+addhp);
}

bool Organism::addHp_percentage(int percentage)
{
	return setHp(getHp()+getTotalHp()*percentage / 100);
}
