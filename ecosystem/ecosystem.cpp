#include "ecosystem.h"

void delaymsec(unsigned msec)
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

ecosystem::ecosystem(QWidget *parent)
	: QWidget(parent)
{
	
	srand((unsigned)time(NULL));
	ui.setupUi(this);
	ui.pushButton->setEnabled(true); //run
	ui.pushButton_2->setEnabled(false); //stop
	ui.pushButton_4->setEnabled(false); //pause
	connect(&dialogSetting, SIGNAL(sendSettingData(SettingData)), this, SLOT(receiveSettingData(SettingData)));//发射信号和接受槽函数连接
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerEven()));
}


ecosystem::~ecosystem()
{
	btnStopClick();
}

void ecosystem::paintEvent(QPaintEvent * p)
{if (running&& sys)
	{
		QPainter painter(this);
		sys->show(&painter);
	}
}

void ecosystem::mouseReleaseEvent(QMouseEvent * e)
{
	int clickX = e->x();
	int clickY = e->y();
	if ( sys &&clickX >= sys->mSettingData.mapPadding &&
		clickX <= sys->mSettingData.mMapWidth + sys->mSettingData.mapPadding
		&&clickY >= sys->mSettingData.mapPadding &&
		clickY <= sys->mSettingData.mMapHeight + sys->mSettingData.mapPadding) //判断鼠标在不在地图内
	{
		sys->select(clickX - sys->mSettingData.mapPadding, clickY - sys->mSettingData.mapPadding);
		QString info = sys->getOrganismInfo(clickX- sys->mSettingData.mapPadding,clickY- sys->mSettingData.mapPadding);
		if (info != NULL)
		{
			ui.textEdit_2->setText(info);
			if (running == false)
			{
				running = true;
				repaint();
				running = false;
			}
		}
	}
}

void ecosystem::closeEvent(QCloseEvent * event)
{
	if (sys)
	{
		delete sys;
		sys = NULL;
		running = false;
	}
}

void ecosystem::btnStopClick()
{

	delete sys;
	sys = NULL;
	running = false;

	ui.pushButton->setEnabled(true); //run
	ui.pushButton_2->setEnabled(false); //stop
	ui.pushButton_4->setEnabled(false); //pauseX
}

void ecosystem::btnSettingClick()
{
	dialogSetting.exec();

}

void ecosystem::btnPauseClick()
{
	running = false;
	ui.pushButton->setEnabled(true); //run
	ui.pushButton_2->setEnabled(true); //stop
	ui.pushButton_4->setEnabled(false); //pause
}

void ecosystem::btnSaveClick()
{
	QString path = QFileDialog::getSaveFileName(this,
		tr("Save"),
		"",
		tr("ec (*.ec)"),
		0);
	if (!path.isNull())
	{
		sys->saveStatus(path);
		QMessageBox::information(this, "notice", "Save!");
	}
}

void ecosystem::btnLoadClick()
{
	QString path = QFileDialog::getOpenFileName(this,
		tr("Load"),
		"",
		tr("ec (*.ec)"),
		0);
	if (!path.isNull())
	{
		if (sys)delete sys;
		sys = new System();
		sys->setOutputTextEdit(ui.textEdit);
		sys->setAnimalInfoTextEdit(ui.textEdit_2);
		ui.pushButton->setEnabled(true); //run
		ui.pushButton_2->setEnabled(false); //stop
		ui.pushButton_4->setEnabled(false); //pauseX
		sys->loadStatus(path);
		running = true;
		repaint();
		running = false;
	}
}

void ecosystem::btnRunClick()
{
	ui.pushButton->setEnabled(false); //run
	ui.pushButton_2->setEnabled(true); //stop
	ui.pushButton_4->setEnabled(true); //pause
	if (!sys)
	{
		sys = new System();
		sys->setSettingData(mSettingData);
		for (int i = 1; i <= 8; i++)
		{
			sys->creatAnimal(i, mSettingData.mAnimalSetting[i].mNum);
		}
		sys->setOutputTextEdit(ui.textEdit);
		sys->setAnimalInfoTextEdit(ui.textEdit_2);
	}
	running = true;
	for (;;)
	{
		if (!running || !sys)break; //停止
		if (sys->getSize() <= 0)
		{
			btnStopClick();
			break;
		}
		setWindowTitle(QString::number(sys->getSize(), 10)); //标题显示动物的数量
		sys->run();
		repaint(); //重绘
		delaymsec(2000 - ui.horizontalSlider->value());
	}
}

void ecosystem::receiveSettingData(SettingData settingData)
{
	mSettingData = settingData;

	ui.pushButton->setEnabled(true); //run
	ui.pushButton_2->setEnabled(false); //stop
	ui.pushButton_4->setEnabled(false); //pause
}

void ecosystem::timerEven()
{
}


