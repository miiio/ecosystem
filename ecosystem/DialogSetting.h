#pragma once
#include <QDialog>  
#include "SettingData.h"
#include "ui_DialogSetting.h"
#include <QFileDialog>
#include <QMessageBox>
class DialogSetting :
	public QDialog
{
	Q_OBJECT
signals :
	void sendSettingData(SettingData settingData);
public slots :
	void btnOkClick();
	void btnSaveClick();
	void btnLoadClick();
	void btnRandClick();
	void btnDefaultSettingClick();
public: 
	explicit DialogSetting(QWidget *parent = 0);
	SettingData getSettingData(); //��ȡ�ؼ�����ʵ����settingdata����
	void setControls(SettingData& settingdata); //��settingdata������ʾ�ڿؼ��� 
	
private:
	Ui::Dialog ui;
};

