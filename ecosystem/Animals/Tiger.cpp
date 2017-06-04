#include "Tiger.h"

Tiger::Tiger()
{
	mTypeId = PIXTIGER;
}

Tiger::Tiger(int x, int y, int hp, int age, int rank, QString name, 
	QString sex, int speed, int attackrange, int creattime, int size)

	:Animal( x,  y,  hp,  age,  rank,  name,
		 sex,  speed,  attackrange, PIXTIGER,  creattime,  size)
{

}


Tiger::~Tiger()
{
}

int Tiger::eat(Animal * other)
{
	return 1;
}
