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

    for(db->itCategory = db->categoryMap.begin(); db->itCategory != db->categoryMap.end(); db->itCategory++)
    {
        ui->comboBox_Kategorie->addItem(QString::fromStdWString(db->itCategory->first));
    }
}

void MainWindow::on_comboBox_Kategorie_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_Item->clear();
    Item *currentItem;
    typeItemMap::iterator itItem;

    std::wstring selectedCategory = arg1.toStdWString();

    this->itCBoxCategory = db->categoryMap.find(selectedCategory);

    for(itItem = this->itCBoxCategory->second->begin();itItem != this->itCBoxCategory->second->end(); itItem++ )
    {
        currentItem = itItem->second;
        ui->comboBox_Item->addItem(QString::fromStdWString(currentItem->getNameEng()));
    }

    this->itCBoxItem = this->itCBoxCategory->second->begin();
    this->pCBoxItem = this->itCBoxItem->second;

    ui->lineEdit_NameGer->setText(QString::fromStdWString(this->pCBoxItem->getNameGer()));    
}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->treeWidget_Crafting->clear();
    QTreeWidgetItem *TreeItem = new QTreeWidgetItem(ui->treeWidget_Crafting);
    TreeItem->setText(0, "Craftingtabelle");

    fillTreeWidget( ui->spinBox_Quantity->value(), this->pCBoxItem, TreeItem);
}

void MainWindow::fillTreeWidget(int quantity, Item *itemObject, QTreeWidgetItem *previousTreeItem)
{
    size_t i;    
    int newQuantity;
    QString qBuffer;    

    typeItemMap::iterator itItem;

    QTreeWidgetItem *newTreeItem = new QTreeWidgetItem(previousTreeItem);

    qBuffer = QString::number(quantity) + "x";
    qBuffer += QString::fromStdWString(itemObject->getNameEng());

    newTreeItem->setText(0, qBuffer);

    for(i=0; i<itemObject->recipeVector.size(); i++)
    {
        newQuantity = itemObject->recipeVector[i]->quantity;
        newQuantity = newQuantity * quantity;

        itItem = db->findItemIterator(itemObject->recipeVector[i]->itemID);

        fillTreeWidget(newQuantity, itItem->second, newTreeItem);
    }
}

void MainWindow::on_comboBox_Item_currentIndexChanged(int index)
{
    this->itCBoxItem = this->itCBoxCategory->second->begin();

    int i;

    for(i=0; i < index; i++)
    {
        this->itCBoxItem++;
    }

    this->pCBoxItem = this->itCBoxItem->second;

    ui->lineEdit_NameGer->setText(QString::fromStdWString(this->pCBoxItem->getNameGer()));

    QPixmap pix("img/" + QString::fromStdWString(this->pCBoxItem->getID()));
    int w = ui->label_thumbnail->width();
    int h = ui->label_thumbnail->height();
    ui->label_thumbnail->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}





