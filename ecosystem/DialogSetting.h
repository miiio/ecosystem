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
	SettingData getSettingData(); //获取控件内容实例化settingdata对象
	void setControls(SettingData& settingdata); //将settingdata对象显示在控件上 
	
private:
	Ui::Dialog ui;
};

