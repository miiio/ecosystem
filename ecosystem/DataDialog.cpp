#include "DataDialog.h"
#define _Get(a) (mNumData->find( a *interval + 1)->num[i])

DataDialog::DataDialog(QWidget * parent)
{
	ui.setupUi(this);
	cView = NULL;
}

void DataDialog::init()
{
	if (cView)
	{
		ui.verticalLayout->removeWidget(cView); 
		delete cView;
		cView = NULL;
	}
	QString PIXNAMES[12] = { "BG","cattle","chick" ,"deer","elephant","lion","pig","tiger","wolf","bone","grass","light" };
	int showNum = 10; //显示10个时间段
	int interval = count / 10; //时间间隔
	QBarSet* set[9]; //8种动物数量信息集合
	for (int i = 1; i <= 8; i++) 
	{
		set[i] = new QBarSet(PIXNAMES[i]);
	}
	for (int i = 1; i <= 8; i++)
	{
		*(set[i]) << _Get(0) << _Get(1) << _Get(2) << _Get(3) << _Get(4) << _Get(5) << _Get(6) << _Get(7) << _Get(8) << _Get(9)<< (mNumData->find(count)->num[i]);
	}
	QStackedBarSeries *series = new QStackedBarSeries();
	for (int i = 1; i <= 8; i++)
	{
		series->append(set[i]);
	}
	QChart *chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Animals's number in " + QString::number(count,10));
	chart->setAnimationOptions(QChart::SeriesAnimations);
	QStringList categories;
	for (int i = 0; i < 10; i++)
	{
		categories << QString::number(i*interval+1,10);
	}
	categories << QString::number(count);
	QBarCategoryAxis *axis = new QBarCategoryAxis();
	axis->append(categories);
	chart->createDefaultAxes();
	chart->setAxisX(axis, series);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	cView = new QChartView(chart);
	cView->setRenderHint(QPainter::Antialiasing);
	ui.verticalLayout->addWidget(cView);
}
