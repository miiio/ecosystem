#include "Wolf.h"

Wolf::Wolf()
{
	mTypeId = PIXWOLF;
}

Wolf::Wolf(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXWOLF,  creattime,  size)
{

}


Wolf::~Wolf()
{
}

int Wolf::eat(Animal * other)
{
	return 1;
}
