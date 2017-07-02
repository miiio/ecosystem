#include "Animal.h"
#include "SettingData.h"

bool Animal::setSpeed(int speed)
{
	if(speed<0)
		return false;
	this->mSpeed = speed;
	return true;
}

bool Animal::setAttackRange(int attackrange)
{
	if(attackrange<0)
		return false;
	mAttackRange = attackrange;
	return true;
}

bool Animal::setSex(QString sex)
{
	if(sex!="male"&&sex!="female")
		return false;
	mSex = sex;
	return true;
}

Animal::~Animal()
{
}

Animal::Animal()
{
}

int Animal::getAttackRange()
{
	return getHp() * mAttackRange / getTotalHp();
}

QRect Animal::getRect()
{
	return QRect(getX() - getAttackRange(), getY() - getAttackRange(), 
		getSize() + 2 * getAttackRange(), getSize() + 2 * getAttackRange());
}

bool Animal::move(int x, int y)
{
	bool ret = setX(x) && setY(y) && setHp(getHp() - 1);
	return ret;
}

//��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
int Animal::eat_default(Animal * other, QString & text)
{
	//Ĭ�Ϲ���
	if (getRank() > other->getRank())
	{
		text = "\"" + getName() + "\" eat \"" + other->getName() + "\" !";
		setHp(getTotalHp());
		other->setHp(0);
		return 1;
	}
	else if (getRank() < other->getRank())
	{
		text = "\"" + other->getName() + "\" eat \"" + getName() + "\" !";
		setHp(0);
		other->setHp(other->getTotalHp());
		return 2;
	}
	else return 0;
}

int Animal::reproduce_default(Animal * other, SettingData* sd, QString & text)
{
	if (getTypeId() == other->getTypeId() && //����
		mSex != other->mSex //�Ա�
		&& getHp_percentage() >= sd->mReproduceHp//Ѫ������
		&& other->getHp_percentage()  >=sd->mReproduceHp //Ѫ������
		&&getAge() >= sd->mReproduceAge //��������
		&&  SettingData::getRandNum(1, 100) <= sd->mReproduceProportion //����
		)
	{
		addHp_percentage(-50);
		other->addHp_percentage(-50); //������Ѫ����50%
		text = "\"" + other->getName() + "\"  reproduce with \"" + getName() + "\" !";
		return  SettingData::getRandNum(4, 8); //Ĭ�ϲ�4~8
	}
	return 0;
}

int Animal::reproduce(Animal * other, SettingData * sd, QString& text)
{
	return reproduce_default(other,sd,text);
}

int Animal::eat(Animal * other, QString& text)
{
	//Ĭ�Ϲ���
	return eat_default(other,text);
}

void Animal::saveInfo(QSettings* setting, QString key)
{
	setting->setValue(key + "mSex", getSex());
	setting->setValue(key + "mX", getX());
	setting->setValue(key + "mY",getY());
	setting->setValue(key + "mHp_cur",getHp());
	setting->setValue(key + "mAge",getAge());
	setting->setValue(key + "mName",getName());
	setting->setValue(key + "mTypeId",getTypeId());
	setting->setValue(key + "mCreatTime", getCreatTime());
	setting->setValue(key + "mRank", getRank());
}

bool Animal::loadInfo(QSettings * setting, QString key, SettingData* sd)
{
	bool ret;
	ret = setTypeId(setting->value(key + "mTypeId").toInt());
	ret=ret&&	setX(setting->value(key + "mX").toInt());
	ret=ret&&	setY(setting->value(key + "mY").toInt()); //λ��
	ret=ret&&	setAge(setting->value(key + "mAge").toInt()); //����
	ret=ret&&	setRank(setting->value(key + "mRank").toInt()); //ʳ�����ȼ�
	ret=ret&&	setName(setting->value(key + "mName").toString()); //����
	ret=ret&&	setSex(setting->value(key + "mSex").toString()); //�Ա�
	ret=ret&&	setSpeed(sd->mAnimalSetting[getTypeId()].mSpeed); //�ƶ��ٶ�
	ret=ret&&	setAttackRange(sd->mAnimalSetting[getTypeId()].mAttackRange);  //������Χ
	ret=ret&&	setCreatTime(setting->value(key + "mCreatTime").toInt());  //���ɵ�ʱ�䣬���ڼ�������
	ret=ret&&	setHp(setting->value(key + "mHp_cur").toInt()); //�޸�Ѫ��
	ret=ret&&	setSize(sd->mAnimalSetting[getTypeId()].mSize);//��ʾ�Ĵ�С
	ret=ret&&	setTotalHp(sd->mAnimalSetting[getTypeId()].mHp); ;//���Ѫ��
	ret = ret&&	setHp(getTotalHp());
	return ret;
}

QString Animal::Info()
{
	QString str;
	str += "Name : " + getName() + "\n";
	str += "Sex : " + getSex() + "\n";
	str += "Hp : " + QString::number(getHp(), 10) + "\n";
	str += "Age : " + QString::number(getAge(), 10) + "\n";
	str += "Coordinate : " + QString::number(getX(), 10) + "," + QString::number(getY(), 10);
	return str;
}
