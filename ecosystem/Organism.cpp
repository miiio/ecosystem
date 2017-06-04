
#include "Organism.h"

Organism::Organism()
{
	mPre = ((rand() % (8 + 1)) + 0); //随机生成0~8中的一个方向
}

Organism::Organism(int x, int y, int hp, int age, int rank, 
	QString name,int type,int creattime,int size)
	:mX(x), mY(y), mHp_total(hp), mAge(age), mHp_cur(hp)
	, mRank(rank), mName(name),mTypeId(type),mCreatTime(creattime)
	,mSize(size)
{
	mPre = ((rand() % (8 + 1)) + 0); //随机生成0~8中的一个方向
}

QRect Organism::getRect()
{
	return QRect(mX,mY,mSize, mSize);
}


Organism::~Organism()
{
}
