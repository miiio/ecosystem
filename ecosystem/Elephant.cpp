#include "Elephant.h"

Elephant::Elephant()
{
	setTypeId(PIXELEPHANT);
}

int Elephant::reproduce(Animal * other, SettingData * sd, QString & text)
{
	//����ÿ̥һ��ֻ��һֻ
	if (reproduce_default(other, sd, text))
	{
		if (SettingData::getRandNum(1, 100) < 95)
			return 1;
		else
			return SettingData::getRandNum(2,3); //�ٷ�֮��ļ�����2~3ֻ
	}
	else
		return 0; //�����Ϲ���
}

Elephant::~Elephant()
{
}
