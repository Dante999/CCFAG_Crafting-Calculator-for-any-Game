#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Database *myDatabase = new Database();

}

MainWindow::~MainWindow()
{
    delete ui;
}
