#include "Lion.h"

Lion::Lion()
{
	mTypeId = PIXLION;
}

Lion::Lion(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXLION,  creattime,  size)
{

}


Lion::~Lion()
{
}

int Lion::eat(Animal * other)
{
	return 1;
}
