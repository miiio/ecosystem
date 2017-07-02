#include "Tiger.h"
#include<qdebug.h>

Tiger::Tiger()
{
	setTypeId(PIXTIGER);
}


//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
int Tiger::eat(Animal * other, QString & text)
{
	int _hp = this->getHp_percentage() - other->getHp_percentage(); //血量差(百分比)
	if (typeid(other) == typeid(Tiger)) //同类
	{
		if (abs(_hp) < 20)
		{
			addHp_percentage(-10);
			other->addHp_percentage(-10); //都减少10%的血量
			return 0;
		}
		else 
		{
			//血量少的一方减血
			if(getHp()<other->getHp())
				addHp_percentage(-20);
			else
				other->addHp_percentage(-20);
		}
	}

	if (typeid(other) == typeid(Lion))  //老虎与狮子的扑食规则
	{
		qDebug("!!!");
		if (abs(_hp) < 20) //血量差小于20%  则没有发生扑食
		{
			return 0; 
		}
		else if (_hp > 0) //血量比other高
		{

			text = "\"" + getName() + "\" eat \"" + other->getName() + "\" !";
			setHp(getTotalHp());
			other->setHp(0);
			return 1;
		}
		else
		{
			text = "\"" + other->getName() + "\" eat \"" + getName() + "\" !";
			other->setHp(other->getTotalHp()); 
			setHp(0);
			return 0;
		}
		
		return 2;
	}
	int result = eat_default(other, text);
	if (result == 1 &&( getHp_percentage() > 90 || getAge()<5)) //吃掉别的动物 且当前90%血量以上或年龄未满5
	{
		result = 0;
	}
	return result;
}

Tiger::~Tiger()
{
}
