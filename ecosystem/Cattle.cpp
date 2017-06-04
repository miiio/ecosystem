#include "Cattle.h"

Cattle::Cattle()
{
	mTypeId = PIXCATTLE;
}

Cattle::Cattle(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXCATTLE,  creattime,  size)
{

}


Cattle::~Cattle()
{
}

int Cattle::eat(Animal * other)
{
	return 1;
}
