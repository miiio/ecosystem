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

//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
int Animal::eat_default(Animal * other, QString & text)
{
	//默认规则
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
	if (getTypeId() == other->getTypeId() && //物种
		mSex != other->mSex //性别
		&& getHp_percentage() >= sd->mReproduceHp//血量限制
		&& other->getHp_percentage()  >=sd->mReproduceHp //血量限制
		&&getAge() >= sd->mReproduceAge //年龄限制
		&&  SettingData::getRandNum(1, 100) <= sd->mReproduceProportion //概率
		)
	{
		addHp_percentage(-50);
		other->addHp_percentage(-50); //减少总血量的50%
		text = "\"" + other->getName() + "\"  reproduce with \"" + getName() + "\" !";
		return  SettingData::getRandNum(4, 8); //默认产4~8
	}
	return 0;
}

int Animal::reproduce(Animal * other, SettingData * sd, QString& text)
{
	return reproduce_default(other,sd,text);
}

int Animal::eat(Animal * other, QString& text)
{
	//默认规则
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
	ret=ret&&	setY(setting->value(key + "mY").toInt()); //位置
	ret=ret&&	setAge(setting->value(key + "mAge").toInt()); //年龄
	ret=ret&&	setRank(setting->value(key + "mRank").toInt()); //食物链等级
	ret=ret&&	setName(setting->value(key + "mName").toString()); //名字
	ret=ret&&	setSex(setting->value(key + "mSex").toString()); //性别
	ret=ret&&	setSpeed(sd->mAnimalSetting[getTypeId()].mSpeed); //移动速度
	ret=ret&&	setAttackRange(sd->mAnimalSetting[getTypeId()].mAttackRange);  //攻击范围
	ret=ret&&	setCreatTime(setting->value(key + "mCreatTime").toInt());  //生成的时间，用于计算年龄
	ret=ret&&	setHp(setting->value(key + "mHp_cur").toInt()); //修改血量
	ret=ret&&	setSize(sd->mAnimalSetting[getTypeId()].mSize);//显示的大小
	ret=ret&&	setTotalHp(sd->mAnimalSetting[getTypeId()].mHp); ;//最大血量
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
