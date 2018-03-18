#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts.h"
#include "structsorts.h"
#include <QTableWidget>
#include <QString>
#include <ctime>
#include <chrono>
#include <fstream>
#include <QMessageBox>
#include <string>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    citiesAmount = 538;

    QTableWidget* myTable = ui->tableWidget;
    QHeaderView* header = myTable->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    whatToSort = new QButtonGroup(this);
    whatToSortCities = new QButtonGroup(this);

    whatToSort->addButton(ui->radioButton, 0);
    whatToSort->addButton(ui->radioButton_2, 1);
    whatToSortCities->addButton(ui->radioButton_3, 0);
    whatToSortCities->addButton(ui->radioButton_4, 1);

    ui->radioButton_3->setDisabled(true);
    ui->radioButton_4->setDisabled(true);
}

MainWindow::~MainWindow()
{
    citiesDB.close();
    citiesSorted.close();
    delete ui;
}

void MainWindow::openFiles() {
    citiesDB.open("cities.txt");
    citiesSorted.open("sortedCities.txt");

    if (!citiesDB.is_open() || !citiesSorted.is_open()) {
        QMessageBox error;
        error.setText("Cannot open files.");
        error.exec();
        this->close();
    }
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

void MainWindow::tableOutput(QString sortName, int time, long long iterations, long long compares) {

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(sortName));
    if (whatToSort->checkedId())
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(ui->spinBox->value())));
    else
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(citiesAmount)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(time)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(iterations)));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::number(compares)));
}

void MainWindow::on_pushButton_4_clicked() { // quick sort 
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    if (whatToSort->checkedId()) {
        int *array = arrayGeneration();
        start_time = std::chrono::system_clock::now();
        quickSort(array, 0, ui->spinBox->value() - 1, iters, comps);
        end_time = std::chrono::system_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        delete array;
    } else {
        city cities[citiesAmount];
        for(int i = 0; i < citiesAmount; ++i) {
            citiesDB >> cities[i].name >> cities[i].population >> cities[i].foundationYear;
        }
        if (whatToSortCities->checkedId()) {
            start_time = std::chrono::system_clock::now();
            quickSortYear(cities, 0, citiesAmount - 1, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        } else {
            start_time = std::chrono::system_clock::now();
            quickSortPopulation(cities, 0, citiesAmount - 1, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        }
        for(int i = 0; i < citiesAmount; ++i) {
           citiesSorted << cities[i].name << " " << cities[i].population << " " << cities[i].foundationYear << "\n";
        }
    }
    tableOutput(QString("Quick"), elapsed_ns.count(), iters, comps);
}

void MainWindow::on_pushButton_5_clicked() { // binary
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    if (whatToSort->checkedId()) {
        int *array = arrayGeneration();
        start_time = std::chrono::system_clock::now();
        binary_insertionSort(array, ui->spinBox->value(), iters, comps);
        end_time = std::chrono::system_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        delete array;
    } else {
        city cities[citiesAmount];
        for(int i = 0; i < citiesAmount; ++i) {
            citiesDB >> cities[i].name >> cities[i].population >> cities[i].foundationYear;
        }
        if (whatToSortCities->checkedId()) {
            start_time = std::chrono::system_clock::now();
            binaryInsertionSortYear(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        } else {
            start_time = std::chrono::system_clock::now();
            binaryInsertionSortPopulation(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        }
        for(int i = 0; i < citiesAmount; ++i) {
           citiesSorted << cities[i].name << " " << cities[i].population << " " << cities[i].foundationYear << "\n";
        }
    }
    tableOutput(QString("Binary"), elapsed_ns.count(), iters, comps);
}

void MainWindow::on_pushButton_3_clicked() { // insertion
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    if (whatToSort->checkedId()) {
        int *array = arrayGeneration();
        start_time = std::chrono::system_clock::now();
        insertion_sort(array, ui->spinBox->value(), iters, comps);
        end_time = std::chrono::system_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        delete array;
    } else {
        city cities[citiesAmount];
        for(int i = 0; i < citiesAmount; ++i) {
            citiesDB >> cities[i].name >> cities[i].population >> cities[i].foundationYear;
        }
        if (whatToSortCities->checkedId()) {
            start_time = std::chrono::system_clock::now();
            insertionSortYear(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        } else {
            start_time = std::chrono::system_clock::now();
            insertionSortPopulation(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        }
        for(int i = 0; i < citiesAmount; ++i) {
           citiesSorted << cities[i].name << " " << cities[i].population << " " << cities[i].foundationYear << "\n";
        }
    }
    tableOutput(QString("Insertion"), elapsed_ns.count(), iters, comps);
}

void MainWindow::on_pushButton_6_clicked() { // shell
    long long iters = 0, comps = 0;
    auto start_time = std::chrono::system_clock::now();
    auto end_time = std::chrono::system_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    if (whatToSort->checkedId()) {
        int *array = arrayGeneration();
        start_time = std::chrono::system_clock::now();
        ShellSort(array, ui->spinBox->value(), iters, comps);
        end_time = std::chrono::system_clock::now();
        elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        delete array;
    } else {
        city cities[citiesAmount];
        for(int i = 0; i < citiesAmount; ++i) {
            citiesDB >> cities[i].name >> cities[i].population >> cities[i].foundationYear;
        }
        if (whatToSortCities->checkedId()) {
            start_time = std::chrono::system_clock::now();
            shellSortYear(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        } else {
            start_time = std::chrono::system_clock::now();
            shellSortPopulation(cities, citiesAmount, iters, comps);
            end_time = std::chrono::system_clock::now();
            elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        }
        for(int i = 0; i < citiesAmount; ++i) {
          citiesSorted << cities[i].name << " " << cities[i].population << " " << cities[i].foundationYear << "\n";
        }
    }
    tableOutput(QString("Shell"), elapsed_ns.count(), iters, comps);
}

void MainWindow::on_radioButton_clicked() { //  cities
    ui->radioButton_3->setEnabled(true);
    ui->radioButton_4->setEnabled(true);
}

void MainWindow::on_radioButton_2_clicked() { // array
    ui->radioButton_3->setDisabled(true);
    ui->radioButton_4->setDisabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("cities.txt", QUrl::TolerantMode));
}

void MainWindow::on_pushButton_7_clicked()
{
    QDesktopServices::openUrl(QUrl("sortedCities.txt", QUrl::TolerantMode));
}
