#pragma once

#include <QtWidgets/QWidget>
#include <QCloseEvent>		
#include "ui_ecosystem.h"
#include "DialogSetting.h"
#include "QTimer"
#include "System.h"
#include<time.h>
#include<QTime>
#include<QMouseEvent>
class ecosystem : public QWidget
{
	Q_OBJECT
public:
	ecosystem(QWidget *parent = Q_NULLPTR);
	~ecosystem();
	void paintEvent(QPaintEvent* p); //��д���ƺ���
	void mouseReleaseEvent(QMouseEvent *e); //��д������¼�
	void closeEvent(QCloseEvent *event);

	SettingData mSettingData; //��������

	//2������
	DialogSetting dialogSetting;
	DataDialog mDataDialog;
public slots :
	void btnRunClick();
	void btnStopClick();
	void btnSettingClick();
	void btnPauseClick();
	void btnSaveClick();
	void btnLoadClick();
	void receiveSettingData(SettingData settingData);
	void timerEven();
	void labelDeadClick();
	void labelTreaClick();
	void labelSureClick();
	void btnDataClick();
private:
	QTimer *timer;
	System* sys = NULL; //��̬ϵͳ�����
	bool running = false;
	Ui::ecosystemClass ui;	
};
