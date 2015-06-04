#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_comboBox_Kategorie_currentIndexChanged(const QString &arg1);

    void on_comboBox_Item_currentIndexChanged(const QString &arg1);

    void on_pushButton_Start_clicked();

private:
    Ui::MainWindow *ui;
    void fillCategoryComboBox(void);
    Database *db;
    void fillTreeWidget(int quantity, Item *itemObject, QTreeWidgetItem *treeLevel);
};

#endif // MAINWINDOW_H
