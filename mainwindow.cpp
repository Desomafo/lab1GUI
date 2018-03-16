#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts.h"
#include <QTableWidget>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidget* myTable = ui->tableWidget;
    QHeaderView* header = myTable->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked() { // quick sort
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Quick"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem("Quick"));
//    int *quick_array = new int[20];
//    srand(time(NULL));

//    for(int i = 0; i < 20; i++) {
//        quick_array[i] = rand()%15000 + 1;
//    }
//    quickSort(quick_array, 0, 19);
}

void MainWindow::on_pushButton_5_clicked() { // binary

}

void MainWindow::on_pushButton_3_clicked() { // insertion

}

void MainWindow::on_pushButton_6_clicked() { // shell

}

void MainWindow::on_pushButton_clicked() { // array randomiztion

}

void MainWindow::on_pushButton_2_clicked() { // exit

}

void MainWindow::on_radioButton_clicked() { //  cities

}

void MainWindow::on_radioButton_2_clicked() { // array

}
