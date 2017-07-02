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
	void paintEvent(QPaintEvent* p); //重写绘制函数
	void mouseReleaseEvent(QMouseEvent *e); //重写鼠标点击事件
	void closeEvent(QCloseEvent *event);

	SettingData mSettingData; //配置数据

	//2个窗口
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
	System* sys = NULL; //生态系统组合类
	bool running = false;
	Ui::ecosystemClass ui;	
};
