#include "Wolf.h"

Wolf::Wolf()
{
	setTypeId(PIXWOLF);
}

//��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
int Wolf::eat(Animal * other, QString & text)
{
	if (typeid(other) == typeid(Wolf)) //ͬ��
	{
		if (SettingData::getRandNum(1, 2)==1)
		{
			other->addHp_percentage(-10);
			return 0;
		}
		else
		{
			addHp_percentage(-10);
			return 0;
		}
	}
	return eat_default(other,text);
}

Wolf::~Wolf()
{
}
