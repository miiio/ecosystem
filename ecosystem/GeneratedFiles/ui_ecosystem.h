/********************************************************************************
** Form generated from reading UI file 'ecosystem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECOSYSTEM_H
#define UI_ECOSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_ecosystemClass
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QComboBox *comboBox;
    ClickableLabel *label_5;
    ClickableLabel *label_6;
    ClickableLabel *label_7;

    void setupUi(QWidget *ecosystemClass)
    {
        if (ecosystemClass->objectName().isEmpty())
            ecosystemClass->setObjectName(QStringLiteral("ecosystemClass"));
        ecosystemClass->resize(1108, 709);
        label = new QLabel(ecosystemClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 2, 600));
        label->setStyleSheet(QStringLiteral("border:2px solid;"));
        pushButton = new QPushButton(ecosystemClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 20, 120, 50));
        pushButton_2 = new QPushButton(ecosystemClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(950, 140, 120, 50));
        textEdit = new QTextEdit(ecosystemClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 640, 791, 38));
        pushButton_3 = new QPushButton(ecosystemClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(950, 200, 120, 50));
        pushButton_4 = new QPushButton(ecosystemClass);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(950, 80, 120, 50));
        horizontalSlider = new QSlider(ecosystemClass);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(960, 650, 121, 22));
        horizontalSlider->setMaximum(1950);
        horizontalSlider->setValue(1400);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(ecosystemClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(919, 20, 2, 600));
        label_3->setStyleSheet(QStringLiteral("border:2px solid;"));
        label_2 = new QLabel(ecosystemClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 900, 2));
        label_2->setStyleSheet(QStringLiteral("border:2px solid;"));
        label_4 = new QLabel(ecosystemClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 620, 900, 2));
        label_4->setStyleSheet(QStringLiteral("border:2px solid;"));
        textEdit_2 = new QTextEdit(ecosystemClass);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(950, 450, 131, 141));
        pushButton_5 = new QPushButton(ecosystemClass);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(950, 260, 120, 50));
        pushButton_6 = new QPushButton(ecosystemClass);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(950, 320, 120, 50));
        pushButton_7 = new QPushButton(ecosystemClass);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(820, 640, 101, 41));
        comboBox = new QComboBox(ecosystemClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(950, 390, 81, 31));
        label_5 = new ClickableLabel(ecosystemClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(980, 600, 31, 21));
        label_5->setCursor(QCursor(Qt::PointingHandCursor));
        label_6 = new ClickableLabel(ecosystemClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1040, 400, 31, 21));
        label_6->setCursor(QCursor(Qt::PointingHandCursor));
        label_7 = new ClickableLabel(ecosystemClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1020, 600, 31, 21));
        label_7->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(ecosystemClass);
        QObject::connect(pushButton, SIGNAL(clicked()), ecosystemClass, SLOT(btnRunClick()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ecosystemClass, SLOT(btnStopClick()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), ecosystemClass, SLOT(btnSettingClick()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), ecosystemClass, SLOT(btnPauseClick()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), ecosystemClass, SLOT(btnSaveClick()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), ecosystemClass, SLOT(btnLoadClick()));
        QObject::connect(label_5, SIGNAL(clicked()), ecosystemClass, SLOT(labelDeadClick()));
        QObject::connect(label_7, SIGNAL(clicked()), ecosystemClass, SLOT(labelTreaClick()));
        QObject::connect(label_6, SIGNAL(clicked()), ecosystemClass, SLOT(labelSureClick()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), ecosystemClass, SLOT(btnDataClick()));

        QMetaObject::connectSlotsByName(ecosystemClass);
    } // setupUi

    void retranslateUi(QWidget *ecosystemClass)
    {
        ecosystemClass->setWindowTitle(QApplication::translate("ecosystemClass", "ecosystem", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("ecosystemClass", "\350\277\220\350\241\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ecosystemClass", "\345\201\234\346\255\242", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("ecosystemClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ecosystemClass", "\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ecosystemClass", "\346\232\202\345\201\234", Q_NULLPTR));
        label_3->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        pushButton_5->setText(QApplication::translate("ecosystemClass", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("ecosystemClass", "\345\212\240\350\275\275", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("ecosystemClass", "\346\225\260\346\215\256", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ecosystemClass", "\345\234\260\351\234\207", Q_NULLPTR)
         << QApplication::translate("ecosystemClass", "\351\227\252\347\224\265", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("ecosystemClass", "<html><head/><body><p><span style=\" font-size:11pt; text-decoration: underline; color:#ff0000;\">\346\255\273\344\272\241</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("ecosystemClass", "<html><head/><body><p><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\347\241\256\345\256\232</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("ecosystemClass", "<html><head/><body><p><span style=\" font-size:11pt; text-decoration: underline; color:#ff0000;\">\346\262\273\347\226\227</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ecosystemClass: public Ui_ecosystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECOSYSTEM_H
