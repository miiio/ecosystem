/********************************************************************************
** Form generated from reading UI file 'DialogData.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDATA_H
#define UI_DIALOGDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogData
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *DialogData)
    {
        if (DialogData->objectName().isEmpty())
            DialogData->setObjectName(QStringLiteral("DialogData"));
        DialogData->resize(492, 345);
        verticalLayoutWidget = new QWidget(DialogData);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 491, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogData);

        QMetaObject::connectSlotsByName(DialogData);
    } // setupUi

    void retranslateUi(QDialog *DialogData)
    {
        DialogData->setWindowTitle(QApplication::translate("DialogData", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogData: public Ui_DialogData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDATA_H
