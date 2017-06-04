#include "System.h"

int System::getRandNum(int a, int b)
{
	return (rand() % (a ? b : b + 1)) + a;
}

//�����Ƿ��������������
bool System::checkXYForCreat(int x, int y, int attackrange, int size)
{
	if (x < 0 || x >= mSettingData.mMapWidth - size || y < 0 || y >= mSettingData.mMapHeight - size)return false;
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
	{
		if (!*it)continue;
		int range = __max(attackrange, IT->getAttackRange()); //�����Ϲ�����Χ��֤���ɵ�λ���ǰ�ȫ��
		if (abs(IT->mX - x) <= (IT->mX > x ? size : IT->mSize) + range
			&& abs(IT->mY - y) <= (IT->mY > y ? size : IT->mSize) + range)
			return false;
	}
	return true;
}
System::System()
{
	//��ʼ��Pixmap
	mPixmaps[0] = QPixmap(":/ecosystem/Resources/background.jpg");
	mPixmaps[1] = QPixmap(":/ecosystem/Resources/cattle.png");
	mPixmaps[2] = QPixmap(":/ecosystem/Resources/chick.png");
	mPixmaps[3] = QPixmap(":/ecosystem/Resources/deer.png");
	mPixmaps[4] = QPixmap(":/ecosystem/Resources/elephant.png");
	mPixmaps[5] = QPixmap(":/ecosystem/Resources/lion.png");
	mPixmaps[6] = QPixmap(":/ecosystem/Resources/pig.png");
	mPixmaps[7] = QPixmap(":/ecosystem/Resources/tiger.png");
	mPixmaps[8] = QPixmap(":/ecosystem/Resources/wolf.png");
	mPixmaps[9] = QPixmap(":/ecosystem/Resources/bone.png");
	mPixmaps[10] = QPixmap(":/ecosystem/Resources/grass.png");

	mAnimals = new QVector<Animal*>();
	mGrass = new QVector<Grass*>();

	count = 0; //��ʱ��
}

System::~System()
{
	//�ͷ��ڴ�
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
		delete *it;
	for (auto it = mGrass->begin(); it != mGrass->end(); it++)
		delete *it;
	mGrass->clear();
	mAnimals->clear();
	delete mAnimals;
	delete mGrass;
}

void System::moveXY(Animal* ap, int x, int y, int attackrange)
{

	//--------����ݵ���ײ
	if (ap->mTypeId != PIXLION &&ap->mTypeId != PIXTIGER &&ap->mTypeId != PIXWOLF
		&& ap->mHp_cur<(ap->mHp_total / 100 * SettingData::mGrassHpLimit)) //��ʳ�⶯����Ѫ������x%
	{
		for (auto it = mGrass->begin(); it != mGrass->end(); it++) //���� ��
			if (ap->getRect().intersects(IT->getRect())) //��ײ
			{
				ap->mHp_cur += (ap->mHp_total / 100 * SettingData::mGrassAdd); //�ظ�40%Ѫ��
				if (ap->mHp_cur > ap->mHp_total)ap->mHp_cur = ap->mHp_total; //Ѫ�����
				IT->mHp_cur--; //�ݵ�Ѫ��-1
			}
	}
	//--------����������ײ

	bool flag = false; //����Ƿ�����ʳ�¼�
	bool flag2 = false; //����Ƿ���ͬ�ȼ�������ײ
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++) //�������ж���
	{
		if (*it == ap)continue;
		int range = __max(attackrange, IT->getAttackRange()); //ȡ����֮�乥����Χ���
		if (ap->mRank == IT->mRank)range = 0; //��ͬ�ȵȼ������迼�ǹ�����Χ

		//ͨ�������ж���ײ
		if (abs(IT->mX - x) <= (IT->mX > x ? ap->mSize : IT->mSize) + range
			&& abs(IT->mY - y) <= (IT->mY > y ? ap->mSize : IT->mSize) + range)
		{
			// ---------------��ʳ�¼�---------------
			QString text;
			int result = ap->eat(IT,text); //��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
			print(text);
			if (result == 1)//ap �Ե� it
			{
				deadAnimals.push_back(*it);
				flag = true;
			}
			else if (result == 2) //it �Ե� ap
			{
				deadAnimals.push_back(ap);
				flag = true;
				break;
			}
			else
			{ 
				//---------------��ֳ�¼�---------------
				if (ap->mSex != IT->mSex && //�Ա�
					ap->mHp_cur * 100 >= ap->mHp_total*mSettingData.mReproduceHp  //Ѫ������
					&& IT->mHp_cur * 100 >= IT->mHp_total*mSettingData.mReproduceHp //Ѫ������
					&&ap->mAge >= mSettingData.mReproduceAge //��������
					&&  getRandNum(1, 100) <= mSettingData.mReproduceProportion //����
					)
				{
					born.push_back({ ap->mTypeId, getRandNum(4, 8),ap->mX,ap->mY }); //����born
					IT->mHp_cur = IT->mHp_total / 2;
					ap->mHp_cur = ap->mHp_total / 2;
					print("\"" + IT->mName + "\"  reproduce with \"" + ap->mName + "\" !");
				}
				flag2 = true;
			}
			//ap �� it��ײ
		}
	}

	if (flag2&&!flag) //�����ƶ�
	{
		return;
	}
	else
	{
		ap->move(x, y);
		if ((ap->mTypeId == 5 || ap->mTypeId == 7 || ap->mTypeId == 8))
			ap->mHp_cur--; //��ʳ��ÿ�μ���Ѫ��
		else
		{
			ap->mHp_cur--;
			if (ap->mHp_cur >= ap->mHp_total)
				ap->mHp_cur = ap->mHp_total;
		}

		ap->mAge = (count - ap->mCreatTime) / mSettingData.mAge;
		if (ap->mHp_cur <= 0 || ap->mAge >= mSettingData.mDeadAGe)//5,7,8Ϊ��ʳ��
		{
			print("\"" + ap->mName + "\" dead!");
			deadAnimals.push_back(ap);
		}
	}
}


bool System::run()
{
	count++;
	deadAnimals.clear();
	born.clear();
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
	{
		int X = IT->mX;
		int Y = IT->mY;
		int& Pre = IT->mPre;
		int x, y, speed = IT->mSpeed;
		int tmpdir;
		do
		{
			if (getRandNum(1, 10) <= 5) //Ϊ�������ƶ��ķ�Χ��50%�ļ����ظ���һ�εķ���
				tmpdir = Pre;
			else
				tmpdir = getRandNum(0, 8);
			x = X + speed*Direction[tmpdir][0], y = Y + speed*Direction[tmpdir][1];
		} while (x < 0 || x >= mSettingData.mMapWidth - IT->mSize || y < 0 || y >= mSettingData.mMapHeight - IT->mSize);
		moveXY(*it, x, y, IT->mAttackRange);
		Pre = tmpdir;
	}
	//���������Ĳ�
	for (auto it = mGrass->begin(); it != mGrass->end();)
	{
		if (IT->mHp_cur <= 0)
		{
			if (selectedPointer == *it) //��ѡ�еĶ���������
			{
				selectedPointer = NULL;
				textEdit_animalInfo->setText("dead...");
			}
			delete *it;
			*it = NULL;
			it = mGrass->erase(it);
		}
		else
			++it;
	}

	//������Ҫ�����Ķ���
	for (IT_A it = mAnimals->begin(); it != mAnimals->end();)
	{
		bool need = false;
		for (IT_A it2 = deadAnimals.begin(); it2 != deadAnimals.end(); it2++)
			if (*it == *it2)
			{
				bones.push_back({ IT->mX, IT->mY, count + mSettingData.mBoneTime ,IT->mSize });
				need = true;
				break;
			}
		if (need)
		{
			if (selectedPointer == *it) //��ѡ�еĶ���������
			{
				selectedPointer = NULL;
				textEdit_animalInfo->setText("dead...");
			}
			delete *it;
			*it = NULL;
			it = mAnimals->erase(it);
		}
		else
			it++;
	}
	//������Ҫ��ֳ�Ķ���
	for (QVector<Born>::iterator it = born.begin(); it != born.end(); it++)
	{
		for (int i = 0; i < it->n; i++)
		{
			creatAnimal(it->type, it->x,it->y);
		}
	}

	//ά�ֲݵ�����
	if (mGrass->size() < SettingData::mGrassNum)
	{
		int n = SettingData::mGrassNum - mGrass->size();
		while (n--)
			creatGrass();
	}

	return getSize() > 0;
}

void System::setOutputTextEdit(QTextEdit * te)
{
	textEdit_output = te;
}

void System::setAnimalInfoTextEdit(QTextEdit * te)
{
	textEdit_animalInfo = te;
}

void System::creatAnimal_xy(int animalType, int x, int y)
{
	switch (animalType)
	{
	case PIXCATTLE: 
		mAnimals->push_back(_CREAT(Cattle)); 
		break;
	case PIXCHICK:
		mAnimals->push_back(_CREAT(Chick));
		break;
	case PIXDEER:
		mAnimals->push_back(_CREAT(Deer));
		break;
	case PIXELEPHANT:
		mAnimals->push_back(_CREAT(Elephant));
		break;
	case PIXLION:
		mAnimals->push_back(_CREAT(Lion));
		break;
	case PIXPIG:
		mAnimals->push_back(_CREAT(Pig));
		break;
	case PIXTIGER:
		mAnimals->push_back(_CREAT(Tiger));
		break;
	case PIXWOLF:
		mAnimals->push_back(_CREAT(Wolf));
		break;
	}
	//mAnimals->push_back(new Animal(
	//	x, y, //λ��
	//	mSettingData.mAnimalSetting[animalType].mHp //���Ѫ��
	//	, 0 //����
	//	, PIXRANK[animalType] //ʳ�����ȼ�
	//	, PIXNAMES[animalType] + "_" + QString::number(count) //����
	//	, getRandNum(1, 2) == 1 ? "male" : "female", //�Ա�
	//	mSettingData.mAnimalSetting[animalType].mSpeed, //�ƶ��ٶ�
	//	mSettingData.mAnimalSetting[animalType].mAttackRange  //������Χ
	//	, animalType //����
	//	, count //���ɵ�ʱ�䣬���ڼ�������
	//	, mSettingData.mAnimalSetting[animalType].mSize //��ʾ�Ĵ�С
	//	));

	}

//�������� ���������������
void System::creatAnimal(int animalType)
{
	if (getSize() >= mSettingData.mAnimalLimit)return;
	int x, y;
	do
	{
		x = getRandNum(0, mSettingData.mMapWidth);
		y = getRandNum(0, mSettingData.mMapHeight);
	} while (!checkXYForCreat(x, y, 10, mSettingData.mAnimalSetting[animalType].mSize));

	creatAnimal_xy(animalType,x,y);
}

//��������֮��ľ���
double System::getDist(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

//��(x,y)��������
void System::creatAnimal(int animalType, int x, int y)
{
	if (getSize() >= mSettingData.mAnimalLimit)return;
	int rx, ry;
	int cnt = 0;
	do
	{
		rx = getRandNum(0, mSettingData.mMapWidth-40);
		ry = getRandNum(0, mSettingData.mMapHeight-40);
		if (getDist(rx, ry, x, y) > mSettingData.mBornRange)
		{
			if (cnt > 100)return; //����100��֮��û�ҵ�λ��
			cnt++;
			continue;
		}
	} while (!checkXYForCreat(rx, ry, 10, mSettingData.mAnimalSetting[animalType].mSize));

	creatAnimal_xy(animalType, rx, ry);
}

//��������,�������� ���������������
void System::creatAnimal(int animalType, int n)
{
	while (n--)
		creatAnimal(animalType);
}

//����һ�Ų�
void System::creatGrass()
{
	int x, y;
	while(1)
	{
		x = getRandNum(0, mSettingData.mMapWidth- SettingData::mGrassSize);
		y = getRandNum(0, mSettingData.mMapHeight- SettingData::mGrassSize);
		QRect tmp = QRect(x,y, SettingData::mGrassSize, SettingData::mGrassSize);
		bool flag = true;
		for (auto it = mGrass->begin(); it != mGrass->end(); it++)
			if (tmp.intersects((*it)->getRect()))
			{
				flag = false;
				break;
			}
		if (flag)	break;
	}
	mGrass->push_back(new Grass(x,y));
}

void System::setSettingData(SettingData setting)
{
	mSettingData = setting;
}

void System::show(QPainter* painter)
{
	painter->setRenderHint(QPainter::Antialiasing, true);
	// ���Ʊ���
	painter->drawPixmap(QRect(mSettingData.mapPadding, mSettingData.mapPadding,
		mSettingData.mMapWidth, mSettingData.mMapHeight), mPixmaps[PIXBG]);

	//����������־
	for (QVector<Bone>::iterator it = bones.begin(); it != bones.end();)
	{
		if (count <= it->endtime)
		{
			painter->drawPixmap(QRect(it->x + mSettingData.mapPadding, it->y + mSettingData.mapPadding,
				it->size, it->size), mPixmaps[PIXBONE]);
			it++;
		}
		else
			it = bones.erase(it);
	}

	//���Ʋ�
	for (auto it = mGrass->begin(); it != mGrass->end(); it++)
	{
		painter->drawPixmap(QRect(IT->mX + mSettingData.mapPadding, IT->mY + mSettingData.mapPadding,
			IT->mSize, IT->mSize), mPixmaps[IT->mTypeId]);

		if (*it == selectedPointer) //Ϊ��ǰѡ�еĶ�����
		{
			painter->setPen(QColor("red"));
			painter->drawRect(mSettingData.mapPadding + IT->mX - 3, mSettingData.mapPadding + IT->mY - 3, IT->mSize + 5, 5 + IT->mSize);
		}
	}

	//���ƶ���
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
	{
		painter->drawPixmap(QRect(IT->mX + mSettingData.mapPadding, IT->mY + mSettingData.mapPadding,
			IT->mSize, IT->mSize), mPixmaps[IT->mTypeId]);

		if (*it == selectedPointer) //Ϊ��ǰѡ�еĶ�����
		{
			painter->setPen(QColor("red"));
			painter->drawRect(mSettingData.mapPadding + IT->mX - 3, mSettingData.mapPadding + IT->mY - 3, IT->mSize + 5, 5 + IT->mSize);
		}
	}

	if (selectedPointer) //�����ǰ�б�ѡ��Ķ���Ҷ���û��
	{
		textEdit_animalInfo->setText(selectedPointer->Info());
	}
}

void System::print(QString text)
{
	if (text.length() <= 0)return;
	if (textEdit_output)
	{
		textEdit_output->insertPlainText("\n[ " + QString::number(count, 10) + " ] : " + text);

		QTextCursor cursor = textEdit_output->textCursor();
		cursor.movePosition(QTextCursor::End);
		textEdit_output->setTextCursor(cursor);
	}
}

void System::select(int x, int y)
{
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
	{
		if (x >= IT->mX && (x - IT->mX) <= IT->mSize &&
			y >= IT->mY && (y - IT->mY) <= IT->mSize)
		{
			selectedPointer = *it;
			return;
		}
	}
	//��
	for (auto it = mGrass->begin(); it != mGrass->end(); it++)
	{
		if (x >= IT->mX && (x - IT->mX) <= IT->mSize &&
			y >= IT->mY && (y - IT->mY) <= IT->mSize)
		{
			selectedPointer = *it;
			return;
		}
	}
}

//��ȡָ�������������Ϣ�������ڷ���NULL
QString System::getOrganismInfo(int x, int y)
{
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
	{
		if (x >= IT->mX && (x - IT->mX) <= IT->mSize &&
			y >= IT->mY && (y - IT->mY) <= IT->mSize)
			return IT->Info();
	}

	for (auto it = mGrass->begin(); it != mGrass->end(); it++)
	{
		if (x >= IT->mX && (x - IT->mX) <= IT->mSize &&
			y >= IT->mY && (y - IT->mY) <= IT->mSize)
			return IT->Info();
	}
	return NULL;
}

int System::getSize()
{
	return mAnimals->size();
	return 0;
}

void System::saveStatus(QString path)
{
	QSettings setting(path, QSettings::IniFormat);//���������ļ�
	setting.clear(); //!!
	mSettingData.saveToFile(path);
	setting.beginGroup("status");

	//����
	setting.setValue("mAnimals_num", QVariant(mAnimals->size()));
	setting.setValue("mGrass_num", QVariant(mGrass->size()));
	setting.setValue("bones_num", QVariant(bones.size()));
	setting.setValue("count", QVariant(count));
	setting.setValue("selected", -1);

	//�������ж���
	int i = 0;
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++, i++)
	{
		if (*it == selectedPointer)
			setting.setValue("selected", i);
		QString key = "Animal_" + QString::number(i, 10) + "_";
		IT->saveInfo(&setting, key); //���涯����Ϣ
	}
	//�������еĲ�
	i = 0;
	for (auto it = mGrass->begin(); it != mGrass->end(); it++, i++)
	{
		if (*it == selectedPointer)
			setting.setValue("selected", i);
		QString key = "Grass_" + QString::number(i, 10) + "_";
		IT->saveInfo(&setting, key); //������Ϣ
	}

	//�����������
	i = 0;
	for (auto it = bones.begin(); it != bones.end(); it++, i++)
	{
		QString str = "bones_" + QString::number(i, 10) + "_";
		setting.setValue(str + "x", it->x);
		setting.setValue(str + "y", it->y);
		setting.setValue(str + "endtime", it->endtime);
		setting.setValue(str + "size", it->size);
	}
	setting.endGroup();

}

void System::loadStatus(QString path)
{
	//---------------------------------���------------------------------------
	for (IT_A it = mAnimals->begin(); it != mAnimals->end(); it++)
		if (*it)	delete *it;
	for (auto it = mGrass->begin(); it != mGrass->end(); it++)
		if (*it)	delete *it;
	mAnimals->clear();
	mGrass->clear();
	for (IT_A it = deadAnimals.begin(); it != deadAnimals.end(); it++)
		if (*it)	delete *it;
	deadAnimals.clear();
	bones.clear();
	born.clear();
	//---------------------------------���------------------------------------


	//����settingdata
	mSettingData = SettingData();
	mSettingData.loadFromFile(path);
	//���붯��״̬
	QSettings setting(path, QSettings::IniFormat);//���������ļ�
	setting.beginGroup("status");
	count = setting.value("count").toInt();
	int Animals_num = setting.value("mAnimals_num").toInt(); 
	int Grass_num = setting.value("mGrass_num").toInt();

	//-------------------------����ÿһ���������Ϣ-------------------------
	for (int i = 0; i < Animals_num; i++)
	{
		QString key = "Animal_" + QString::number(i, 10) + "_";
		Animal* animal = new Animal();
		animal->loadInfo(&setting, key,&mSettingData); 
		mAnimals->push_back(animal);
	}	
	//-------------------------����ÿһ���������Ϣ-------------------------

	//-------------------------����ݵ���Ϣ-------------------------
	for (int i = 0; i < Grass_num; i++)
	{
		QString key = "Grass_" + QString::number(i, 10) + "_";
		Grass* grass = new Grass(0,0);
		grass->loadInfo(&setting, key, &mSettingData);
		mGrass->push_back(grass);
	}
	//-------------------------����ݵ���Ϣ-------------------------


	int selectId = setting.value("selected").toInt();
	if (selectId != -1)  selectedPointer = mAnimals->at(selectId);
	else  selectedPointer = NULL;

	for (int i = 0; i < setting.value("bones_num").toInt(); i++)
	{
		QString str = "bones_" + QString::number(i, 10) + "_";
		bones.push_back({ setting.value(str + "x").toInt(), setting.value(str + "y").toInt(),
			setting.value(str + "endtime").toInt(), setting.value(str + "size").toInt() });
	}
	setting.endGroup();
}
