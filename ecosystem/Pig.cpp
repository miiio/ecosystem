#include "Pig.h"

Pig::Pig()
{
	mTypeId = PIXPIG;
}

Pig::Pig(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXPIG,  creattime,  size)
{

}


Pig::~Pig()
{
}

int Pig::eat(Animal * other)
{
	return 1;
}
