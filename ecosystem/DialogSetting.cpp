#include "DialogSetting.h"  
#define tti text().toInt()
DialogSetting::DialogSetting(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	//控件数组
}
int getRandNum(int a, int b)
{
	return (rand() % (a ? b : b + 1)) + a;
}

void DialogSetting::btnSaveClick()
{
	QString file_name = QFileDialog::getSaveFileName(this,
		tr("Save"),
		"",
		tr("sd (*.sd)"),
		0);
	if (!file_name.isNull())
	{
		getSettingData().saveToFile(file_name);
		QMessageBox::information(this, "notice", "Save!");
	}
}
void DialogSetting::btnLoadClick()
{
	QString file_name = QFileDialog::getOpenFileName(this,
		tr("Load"),
		"",
		tr("sd (*.sd)"),
		0);
	if (!file_name.isNull())
	{
		SettingData tmp;
		tmp.loadFromFile("config.sd");
		setControls(tmp);
		QMessageBox::information(this, "notice", "Load!");
	}
}
void DialogSetting::btnRandClick()
{
	//随机分配数量
	ui.spinBox_number_1->setValue(getRandNum(0, 20));
	ui.spinBox_number_2->setValue(getRandNum(0, 20));
	ui.spinBox_number_3->setValue(getRandNum(0, 20));
	ui.spinBox_number_4->setValue(getRandNum(0, 20));
	ui.spinBox_number_5->setValue(getRandNum(0, 20));
	ui.spinBox_number_6->setValue(getRandNum(0, 5));
	ui.spinBox_number_7->setValue(getRandNum(0, 4));
	ui.spinBox_number_8->setValue(getRandNum(0, 4));
}
void DialogSetting::btnDefaultSettingClick()
{
	setControls(SettingData());
}
void DialogSetting::btnOkClick()
{
	emit sendSettingData(getSettingData());
	accept();
}

//获取控件内容实例化settingdata对象
SettingData DialogSetting::getSettingData()
{
	/*
	AnimalSetting
	int mHp;
	int mSpeed;
	int mAttackRange;
	int mSize;
	int mNum;
	*/
	//从spinBox中获取基本信息和数量
	SettingData tmp; //其他必要的参数
	tmp.mAnimalSetting[1] = { ui.spinBox_hp_1->tti, ui.spinBox_speed_1->tti, ui.spinBox_attackrange_1->tti, ui.spinBox_size_1->tti, ui.spinBox_number_1->tti };
	tmp.mAnimalSetting[2] = { ui.spinBox_hp_2->tti, ui.spinBox_speed_2->tti, ui.spinBox_attackrange_2->tti, ui.spinBox_size_2->tti, ui.spinBox_number_2->tti };
	tmp.mAnimalSetting[3] = { ui.spinBox_hp_3->tti, ui.spinBox_speed_3->tti, ui.spinBox_attackrange_3->tti, ui.spinBox_size_3->tti, ui.spinBox_number_3->tti };
	tmp.mAnimalSetting[4] = { ui.spinBox_hp_4->tti, ui.spinBox_speed_4->tti, ui.spinBox_attackrange_4->tti, ui.spinBox_size_4->tti, ui.spinBox_number_4->tti };
	tmp.mAnimalSetting[5] = { ui.spinBox_hp_5->tti, ui.spinBox_speed_5->tti, ui.spinBox_attackrange_5->tti, ui.spinBox_size_5->tti, ui.spinBox_number_5->tti };
	tmp.mAnimalSetting[6] = { ui.spinBox_hp_6->tti, ui.spinBox_speed_6->tti, ui.spinBox_attackrange_6->tti, ui.spinBox_size_6->tti, ui.spinBox_number_6->tti };
	tmp.mAnimalSetting[7] = { ui.spinBox_hp_7->tti, ui.spinBox_speed_7->tti, ui.spinBox_attackrange_7->tti, ui.spinBox_size_7->tti, ui.spinBox_number_7->tti };
	tmp.mAnimalSetting[8] = { ui.spinBox_hp_8->tti, ui.spinBox_speed_8->tti, ui.spinBox_attackrange_8->tti, ui.spinBox_size_8->tti, ui.spinBox_number_8->tti };
	//其他的设置
	tmp.mAge = ui.spinBox_ageTime->tti;
	tmp.mAnimalLimit = ui.spinBox_numberLimit->tti;
	tmp.mBoneTime = ui.spinBox_boneTime->tti;
	tmp.mDeadAGe = ui.spinBox_ageLimit->tti;
	tmp.mMapHeight = ui.spinBox_mapHeight->tti;
	tmp.mMapWidth = ui.spinBox_mapWidth->tti;
	tmp.mReproduceAge = ui.spinBox_reproduceAge->tti;
	tmp.mReproduceHp = ui.spinBox_reproduceHp->tti;
	tmp.mReproduceProportion = ui.spinBox_reproduceProportion->tti;
	return tmp;
}

void DialogSetting::setControls(SettingData& settingdata)
{
	//控件数组，方便循环操作
	QSpinBox* spinbox[9][5] = { NULL,NULL,NULL,NULL,NULL, ui.spinBox_hp_1, ui.spinBox_speed_1, ui.spinBox_attackrange_1, ui.spinBox_size_1, ui.spinBox_number_1 ,ui.spinBox_hp_2, ui.spinBox_speed_2, ui.spinBox_attackrange_2, ui.spinBox_size_2, ui.spinBox_number_2 ,ui.spinBox_hp_3, ui.spinBox_speed_3, ui.spinBox_attackrange_3, ui.spinBox_size_3, ui.spinBox_number_3 ,ui.spinBox_hp_4, ui.spinBox_speed_4, ui.spinBox_attackrange_4, ui.spinBox_size_4, ui.spinBox_number_4 ,ui.spinBox_hp_5, ui.spinBox_speed_5, ui.spinBox_attackrange_5, ui.spinBox_size_5, ui.spinBox_number_5 ,ui.spinBox_hp_6, ui.spinBox_speed_6, ui.spinBox_attackrange_6, ui.spinBox_size_6, ui.spinBox_number_6 ,ui.spinBox_hp_7, ui.spinBox_speed_7, ui.spinBox_attackrange_7, ui.spinBox_size_7, ui.spinBox_number_7 ,ui.spinBox_hp_8, ui.spinBox_speed_8, ui.spinBox_attackrange_8, ui.spinBox_size_8, ui.spinBox_number_8 };
	for (int i = 1; i <= 8; i++)
	{
		spinbox[i][0]->setValue(settingdata.mAnimalSetting[i].mHp);
		spinbox[i][1]->setValue(settingdata.mAnimalSetting[i].mSpeed);
		spinbox[i][2]->setValue(settingdata.mAnimalSetting[i].mAttackRange);
		spinbox[i][3]->setValue(settingdata.mAnimalSetting[i].mSize);
		spinbox[i][4]->setValue(settingdata.mAnimalSetting[i].mNum);
	}
	//其他的设置
	ui.spinBox_ageTime->setValue(settingdata.mAge);
	ui.spinBox_numberLimit->setValue(settingdata.mAnimalLimit);
	ui.spinBox_boneTime->setValue(settingdata.mBoneTime);
	ui.spinBox_ageLimit->setValue(settingdata.mDeadAGe);
	ui.spinBox_mapHeight->setValue(settingdata.mMapHeight);
	ui.spinBox_mapWidth->setValue(settingdata.mMapWidth);
	ui.spinBox_reproduceAge->setValue(settingdata.mReproduceAge);
	ui.spinBox_reproduceHp->setValue(settingdata.mReproduceHp);
	ui.spinBox_reproduceProportion->setValue(settingdata.mReproduceProportion);
}
