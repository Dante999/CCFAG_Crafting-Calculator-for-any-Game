#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "database.h"
#include "item.h"

#include <map>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->db = new Database;
    fillCategoryComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillCategoryComboBox(void)
{
    ui->comboBox_Kategorie->clear();

    for(db->it1 = db->categoryMap.begin(); db->it1 != db->categoryMap.end(); db->it1++)
    {
        ui->comboBox_Kategorie->addItem(QString::fromStdWString(db->it1->first));
    }
}

void MainWindow::on_comboBox_Kategorie_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_Item->clear();
    Item *currentItem;

    std::wstring selectedCategory = arg1.toStdWString();

    db->it1 = db->categoryMap.find(selectedCategory);

    for(db->it2 = db->it1->second->begin();db->it2 != db->it1->second->end(); db->it2++ )
    {
        currentItem = db->it2->second;

        ui->comboBox_Item->addItem(QString::fromStdWString(currentItem->getID()));
        ui->lineEdit_NameGer->setText(QString::fromStdWString(currentItem->getNameGer()));
        ui->lineEdit_NameEng->setText(QString::fromStdWString(currentItem->getNameEng()));
    }
}

void MainWindow::on_comboBox_Item_currentIndexChanged(const QString &arg1)
{
    QPixmap pix("img/" + arg1);
    int w = ui->label_thumbnail->width();
    int h = ui->label_thumbnail->height();

    ui->label_thumbnail->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->treeWidget_Crafting->clear();
    QTreeWidgetItem *TreeItem = new QTreeWidgetItem(ui->treeWidget_Crafting);
    TreeItem->setText(0, "Craftingtabelle");
    Item *currentItem;

    QString qSelectedCategory = ui->comboBox_Kategorie->currentText();
    QString qSelectedItem = ui->comboBox_Item->currentText();

    db->it1 = db->categoryMap.find(qSelectedCategory.toStdWString());
    db->it2 = db->it1->second->begin();

    for(db->it2 = db->it1->second->begin();db->it2 != db->it1->second->end(); db->it2++ )
    {
        currentItem = db->it2->second;

        ui->comboBox_Item->addItem(QString::fromStdWString(currentItem->getID()));
        ui->lineEdit_NameGer->setText(QString::fromStdWString(currentItem->getNameGer()));
        ui->lineEdit_NameEng->setText(QString::fromStdWString(currentItem->getNameEng()));
    }

    fillTreeWidget( ui->spinBox_Quantity->value(), db->it2->second, TreeItem);
}

void MainWindow::fillTreeWidget(int quantity, Item *itemObject, QTreeWidgetItem *treeLevel)
{
    unsigned int i;
    int j;
    int newQuantity;
    QString qBuffer;
    QTreeWidgetItem *item = new QTreeWidgetItem(treeLevel);

    qBuffer = QString::number(quantity) + "x";
    qBuffer += QString::fromStdWString(itemObject->getNameEng());

    item->setText(0, qBuffer);

    for(i=0; i<itemObject->recipeVector.size(); i++)
    {
        newQuantity = itemObject->recipeVector[i]->quantity;
        newQuantity = newQuantity * quantity;


        // TODO

/**
        for(db->it1 = db->categoryMap->begin(); db->it1 != db->categoryMap->end(); db->it1++)
        {
            for(db->it2 = db->it1->second->begin(); db->it2 != db->it1->second->end(); db->it2++)
            {

            }
        }

        fillTreeWidget(newQuantity, dbFile->itemVektor[j], item);
**/

    }
}
