#include "Chick.h"

Chick::Chick()
{
	mTypeId = PIXCHICK;
}

Chick::Chick(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXCHICK,  creattime,  size)
{

}


Chick::~Chick()
{
}

int Chick::eat(Animal * other)
{
	return 1;
}
