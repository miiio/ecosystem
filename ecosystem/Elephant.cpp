#include "Elephant.h"

Elephant::Elephant()
{
	mTypeId = PIXELEPHANT;
}

Elephant::Elephant(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXELEPHANT,  creattime,  size)
{

}


Elephant::~Elephant()
{
}

int Elephant::eat(Animal * other)
{
	return 1;
}
