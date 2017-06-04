#include "ecosystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ecosystem w;
	w.show();
	return a.exec();
}
