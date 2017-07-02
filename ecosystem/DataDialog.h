#pragma once
#include "ui_DialogData.h"
#include "Animal.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE

class DataDialog :
	public QDialog
{
public:
	struct NumNode
	{
		int num[9]; //id为1~8 的8种队伍数量
	};
	Q_OBJECT
public:
	explicit DataDialog(QWidget *parent = 0);
	void setData();
	void init();


	QMap<int, DataDialog::NumNode>* mNumData;
	int count = 0;
private:
	Ui::DialogData ui;
	QChartView* cView;
};
