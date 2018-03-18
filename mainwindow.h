#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <string>
#include <fstream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    struct city {
        std::string name;
        int foundationYear;
        int population;
    };
    int *arrayGeneration();
    void openFiles();
    void tableOutput(QString sortName, int time, long long iterations, long long compares);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

private:
    std::ifstream citiesDB;
    std::ofstream citiesSorted;
    QButtonGroup *whatToSort;
    QButtonGroup *whatToSortCities;
    int citiesAmount;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
