#include "Lion.h"

Lion::Lion()
{
	setTypeId(PIXLION);
}


//��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
int Lion::eat(Animal * other, QString & text)
{
	int _hp = this->getHp_percentage() - other->getHp_percentage(); //Ѫ����(�ٷֱ�)
	if (typeid(other) == typeid(Lion)) //ͬ��
	{
		if (abs(_hp) < 20)
		{
			addHp_percentage(-10);
			other->addHp_percentage(-10); //������10%��Ѫ��
		}
		else
		{
			//Ѫ���ٵ�һ����Ѫ
			if (getHp()<other->getHp())
				addHp_percentage(-20);
			else
				other->addHp_percentage(-20);
		}
		return 0;
	}

	if (typeid(other) == typeid(Tiger))  //�ϻ���ʨ��ֱ�ӵ���ʳ����
	{
		if (abs(_hp) < 20) //Ѫ����С��20%  ��û�з�����ʳ
		{
			return 0;
		}
		else if (_hp > 0) //Ѫ����other��
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
	if (result == 1 && (getHp_percentage() > 90 || getAge()<5)) //�Ե���Ķ��� �ҵ�ǰ90%Ѫ�����ϻ�����δ��5
	{
		result = 0;
	}
	return result;
}

Lion::~Lion()
{
}
