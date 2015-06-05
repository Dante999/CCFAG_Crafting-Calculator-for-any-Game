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
    ui->lineEdit_NameEng->setText(QString::fromStdWString(this->pCBoxItem->getNameEng()));
}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->treeWidget_Crafting->clear();
    QTreeWidgetItem *TreeItem = new QTreeWidgetItem(ui->treeWidget_Crafting);
    TreeItem->setText(0, "Craftingtabelle");
    Item *currentItem;

    QString qSelectedCategory = ui->comboBox_Kategorie->currentText();
    QString qSelectedItem = ui->comboBox_Item->currentText();

    db->itCategory = db->categoryMap.find(qSelectedCategory.toStdWString());

    for(db->itItem = db->itCategory->second->begin();db->itItem != db->itCategory->second->end(); db->itItem++ )
    {
        currentItem = db->itItem->second;

        ui->comboBox_Item->addItem(QString::fromStdWString(currentItem->getID()));
        ui->lineEdit_NameGer->setText(QString::fromStdWString(currentItem->getNameGer()));
        ui->lineEdit_NameEng->setText(QString::fromStdWString(currentItem->getNameEng()));
    }

    fillTreeWidget( ui->spinBox_Quantity->value(), db->itItem->second, TreeItem);
}

void MainWindow::fillTreeWidget(int quantity, Item *itemObject, QTreeWidgetItem *previousTreeItem)
{
    size_t i;
    int j;
    int newQuantity;
    QString qBuffer;

    QTreeWidgetItem *newTreeItem = new QTreeWidgetItem(previousTreeItem);

    qBuffer = QString::number(quantity) + "x";
    qBuffer += QString::fromStdWString(itemObject->getNameEng());
#if 0
    newTreeItem->setText(0, qBuffer);

    for(i=0; i<itemObject->recipeVector.size(); i++)
    {
        /**
        newQuantity = itemObject->recipeVector[i]->quantity;
        newQuantity = newQuantity * quantity;


        // TODO


        for(db->it1 = db->categoryMap->begin(); db->it1 != db->categoryMap->end(); db->it1++)
        {
            for(db->it2 = db->it1->second->begin(); db->it2 != db->it1->second->end(); db->it2++)
            {

            }
        }

        fillTreeWidget(newQuantity, dbFile->itemVektor[j], item);
    **/
    }
#endif
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

    ui->lineEdit_NameEng->setText(QString::fromStdWString(this->pCBoxItem->getNameEng()));
    ui->lineEdit_NameGer->setText(QString::fromStdWString(this->pCBoxItem->getNameGer()));

    QPixmap pix("img/" + QString::fromStdWString(this->pCBoxItem->getID()));
    int w = ui->label_thumbnail->width();
    int h = ui->label_thumbnail->height();
    ui->label_thumbnail->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}





