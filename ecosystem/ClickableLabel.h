#pragma once
#include "qlabel.h"
class ClickableLabel : public QLabel
{
	Q_OBJECT
public:
	ClickableLabel(QWidget *parent = 0) : QLabel(parent), m_str("")
	{
		setText(m_str);
	};
	~ClickableLabel() {};
signals:
	void clicked();
protected:
	void mousePressEvent(QMouseEvent* event);
private:
		QString m_str;
};