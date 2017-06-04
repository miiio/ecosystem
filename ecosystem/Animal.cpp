#include "Animal.h"
#include "SettingData.h"

Animal::Animal(int x, int y, int hp, int age, int rank, QString name,
	QString sex, int speed, int attackrange, int type, int creattime, int size) :
	Organism(x, y, hp, age, rank, name, type, creattime, size),
	mSex(sex), mSpeed(speed), mAttackRange(attackrange)
{

}

Animal::~Animal()
{
}

Animal::Animal()
{
}

int Animal::getAttackRange()
{
	return mHp_cur * mAttackRange / mHp_total;
}

QRect Animal::getRect()
{
	return QRect(mX - getAttackRange(), mY - getAttackRange(), mSize + 2 * getAttackRange(), mSize + 2 * getAttackRange());
}

void Animal::move(int x, int y)
{
	mX = x;
	mY = y;
}

//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
int Animal::eat_default(Animal * other, QString & text)
{
	//默认规则
	if (mRank > other->mRank)
	{
		text = "\"" + mName + "\" eat \"" + other->mName + "\" !";
		mHp_cur = mHp_total + 1;
		return 1;
	}
	else if (mRank < other->mRank)
	{
		text = "\"" + other->mName + "\" eat \"" + mName + "\" !";
		other->mHp_cur = other->mHp_total + 1;
		return 2;
	}
	else return 0;
}

int Animal::eat(Animal * other,QString& text)
{
	//默认规则
	return eat_default(other,text);
}

void Animal::saveInfo(QSettings* setting, QString key)
{
	setting->setValue(key + "mSex", mSex);
	setting->setValue(key + "mX", mX);
	setting->setValue(key + "mY", mY);
	setting->setValue(key + "mHp_cur",mHp_cur);
	setting->setValue(key + "mAge",mAge);
	setting->setValue(key + "mName",mName);
	setting->setValue(key + "mTypeId",mTypeId);
	setting->setValue(key + "mCreatTime", mCreatTime);
}

void Animal::loadInfo(QSettings * setting, QString key, SettingData* sd)
{
	mTypeId = setting->value(key + "mTypeId").toInt();

	mX = setting->value(key + "mX").toInt();
	mY = setting->value(key + "mY").toInt(); //位置

	mAge = setting->value(key + "mAge").toInt(); //年龄
	mRank = setting->value(key + "mRank").toInt(); //食物链等级
	mName = setting->value(key + "mName").toString(); //名字
	mSex = setting->value(key + "mSex").toString(); //性别
	mSpeed = sd->mAnimalSetting[mTypeId].mSpeed; //移动速度
	mAttackRange = sd->mAnimalSetting[mTypeId].mAttackRange;  //攻击范围
	mCreatTime = setting->value(key + "mCreatTime").toInt();  //生成的时间，用于计算年龄
	mHp_cur = setting->value(key + "mHp_cur").toInt(); //修改血量
	mSize = sd->mAnimalSetting[mTypeId].mSize; //显示的大小
	mHp_total = sd->mAnimalSetting[mTypeId].mHp;//最大血量
}

QString Animal::Info()
{
	QString str;
	str += "Name : " + mName + "\n";
	str += "Sex : " + mSex + "\n";
	str += "Hp : " + QString::number(mHp_cur, 10) + "\n";
	str += "Age : " + QString::number(mAge, 10) + "\n";
	str += "Coordinate : " + QString::number(mX, 10) + "," + QString::number(mY, 10);
	return str;
}
