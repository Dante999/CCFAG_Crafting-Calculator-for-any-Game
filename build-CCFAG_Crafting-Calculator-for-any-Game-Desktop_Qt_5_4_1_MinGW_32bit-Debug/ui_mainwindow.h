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
#include <QtWidgets/QFormLayout>
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
    QLabel *label_thumbnail;
    QTreeWidget *treeWidget_Crafting;
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QSpinBox *spinBox_Quantity;
    QPushButton *pushButton_Start;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Kategorie;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_Item;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_NameGer;
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
        label->setGeometry(QRect(60, 10, 451, 51));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Script"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_thumbnail = new QLabel(centralWidget);
        label_thumbnail->setObjectName(QStringLiteral("label_thumbnail"));
        label_thumbnail->setGeometry(QRect(20, 170, 150, 150));
        label_thumbnail->setMinimumSize(QSize(100, 100));
        label_thumbnail->setMaximumSize(QSize(500, 500));
        label_thumbnail->setFrameShape(QFrame::StyledPanel);
        treeWidget_Crafting = new QTreeWidget(centralWidget);
        treeWidget_Crafting->setObjectName(QStringLiteral("treeWidget_Crafting"));
        treeWidget_Crafting->setGeometry(QRect(200, 170, 421, 331));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(650, 10, 121, 31));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(670, 210, 81, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBox_Quantity = new QSpinBox(formLayoutWidget);
        spinBox_Quantity->setObjectName(QStringLiteral("spinBox_Quantity"));
        spinBox_Quantity->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox_Quantity);

        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(670, 350, 75, 23));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 80, 761, 53));
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
        lineEdit_NameGer = new QLineEdit(groupBox_3);
        lineEdit_NameGer->setObjectName(QStringLiteral("lineEdit_NameGer"));
        lineEdit_NameGer->setGeometry(QRect(10, 23, 133, 20));
        lineEdit_NameGer->setReadOnly(true);
        splitter->addWidget(groupBox_3);
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        label_thumbnail->raise();
        treeWidget_Crafting->raise();
        label_2->raise();
        splitter->raise();
        splitter->raise();
        formLayoutWidget->raise();
        pushButton_Start->raise();
        groupBox_2->raise();
        groupBox_3->raise();
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
        label_thumbnail->setText(QApplication::translate("MainWindow", "image_label", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_Crafting->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Crafting Baum", 0));
        label_2->setText(QApplication::translate("MainWindow", "by Dante999", 0));
        label_3->setText(QApplication::translate("MainWindow", "Anzahl", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Kategorie", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Item Englisch", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Item Deutsch", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
