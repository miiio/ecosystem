#include "Deer.h"

Deer::Deer()
{
	mTypeId = PIXDEER;
}

Deer::Deer(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXDEER,  creattime,  size)
{

}


Deer::~Deer()
{
}

int Deer::eat(Animal * other)
{
	return 1;
}
