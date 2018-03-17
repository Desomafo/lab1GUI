#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts.h"
#include <QTableWidget>
#include <QString>
#include <ctime>
#include <chrono>


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

int *MainWindow::arrayGeneration() {
    int array_size = ui->spinBox->value();
    int *array = new int[array_size];

    int left_border = ui->spinBox_2->value();
    int right_border = ui->spinBox_3->value();

    srand(time(NULL));
    for(int i = 0; i < array_size; i++) {
        array[i] = rand()%right_border - left_border;
    }

    return array;
}

void MainWindow::on_pushButton_4_clicked() { // quick sort
    int *array = arrayGeneration();
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    quickSort(array, 0, ui->spinBox->value() - 1, iters, comps);
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Quick"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(elapsed_ns.count())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(iters)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::number(comps)));
    delete array;
}

void MainWindow::on_pushButton_5_clicked() { // binary
    int *array = arrayGeneration();
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    binary_insertionSort(array, ui->spinBox->value(), iters, comps);
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Binary"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(elapsed_ns.count())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(iters)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::number(comps)));
    delete array;
}

void MainWindow::on_pushButton_3_clicked() { // insertion
    int *array = arrayGeneration();
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    insertion_sort(array, ui->spinBox->value(), iters, comps);
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Insertion"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(elapsed_ns.count())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(iters)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::number(comps)));
    delete array;
}

void MainWindow::on_pushButton_6_clicked() { // shell
    int *array = arrayGeneration();
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    ShellSort(array, ui->spinBox->value(), iters, comps);
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem("Shell"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(elapsed_ns.count())));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(iters)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::number(comps)));
    delete array;
}

void MainWindow::on_pushButton_2_clicked() { // exit

}

void MainWindow::on_radioButton_clicked() { //  cities

}

void MainWindow::on_radioButton_2_clicked() { // array

}
