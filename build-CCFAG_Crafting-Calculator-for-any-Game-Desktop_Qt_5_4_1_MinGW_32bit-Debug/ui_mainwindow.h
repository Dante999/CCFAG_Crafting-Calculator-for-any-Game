/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Kategorie;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_Item;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_NameGer;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_NameEng;
    QLabel *label_thumbnail;
    QTreeWidget *treeWidget_Crafting;
    QSpinBox *spinBox_Quantity;
    QPushButton *pushButton_Start;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(787, 563);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 451, 51));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Script"));
        font.setPointSize(17);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 160, 751, 61));
        gridLayout_5 = new QGridLayout(gridLayoutWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(gridLayoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox_Kategorie = new QComboBox(groupBox);
        comboBox_Kategorie->setObjectName(QStringLiteral("comboBox_Kategorie"));

        gridLayout_2->addWidget(comboBox_Kategorie, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_Item = new QComboBox(groupBox_2);
        comboBox_Item->setObjectName(QStringLiteral("comboBox_Item"));

        gridLayout->addWidget(comboBox_Item, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_NameGer = new QLineEdit(groupBox_3);
        lineEdit_NameGer->setObjectName(QStringLiteral("lineEdit_NameGer"));

        gridLayout_3->addWidget(lineEdit_NameGer, 0, 0, 1, 1);

        splitter->addWidget(groupBox_3);
        groupBox_4 = new QGroupBox(splitter);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_NameEng = new QLineEdit(groupBox_4);
        lineEdit_NameEng->setObjectName(QStringLiteral("lineEdit_NameEng"));

        gridLayout_4->addWidget(lineEdit_NameEng, 0, 0, 1, 1);

        splitter->addWidget(groupBox_4);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        label_thumbnail = new QLabel(centralWidget);
        label_thumbnail->setObjectName(QStringLiteral("label_thumbnail"));
        label_thumbnail->setGeometry(QRect(50, 280, 60, 60));
        label_thumbnail->setMinimumSize(QSize(60, 60));
        label_thumbnail->setMaximumSize(QSize(60, 60));
        treeWidget_Crafting = new QTreeWidget(centralWidget);
        treeWidget_Crafting->setObjectName(QStringLiteral("treeWidget_Crafting"));
        treeWidget_Crafting->setGeometry(QRect(160, 250, 421, 241));
        spinBox_Quantity = new QSpinBox(centralWidget);
        spinBox_Quantity->setObjectName(QStringLiteral("spinBox_Quantity"));
        spinBox_Quantity->setGeometry(QRect(610, 310, 42, 22));
        spinBox_Quantity->setMinimum(1);
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(670, 310, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 787, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Crafting Calculator for any Game", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Kategorie", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Item ID", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Name Deutsch", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Name Englisch", 0));
        label_thumbnail->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_Crafting->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Crafting Baum", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
