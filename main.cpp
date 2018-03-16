#include "mainwindow.h"
#include <QApplication>
#include <chrono>






//void sortComparisonChrono(int array_size) {
//    int *linear_array = new int[array_size];
//    int *linear_binary_array = new int[array_size];
//    int *shell_array = new int[array_size];
//    int *quick_array = new int[array_size];

//    long long *iters_comps;

//    srand(time(NULL));

//    for(int i = 0; i < array_size; i++) {
//        linear_array[i] = rand()%15000 + 1;
//        linear_binary_array[i] = linear_array[i];
//        shell_array[i] = linear_array[i];
//        quick_array[i] = linear_array[i];
//    }

//    cout << setw(8) << array_size;

//    auto start_time = std::chrono::system_clock::now();
//    auto end_time = std::chrono::system_clock::now();
//    auto elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

//    if (array_size < 1000000) {
//        start_time = std::chrono::system_clock::now();
//        iters_comps = insertion_sort(linear_array, array_size);
//        end_time = std::chrono::system_clock::now();
//        elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//        //cout << "Time for array[" << array_size << "] with linear insertion sort: " << elapsed_ns.count() << " ns.\n";
//        cout << setw(4) << elapsed_ns.count() <<  "|" << setw(8) << iters_comps[0] << "|" << setw(8) << iters_comps[1] ;
//    } else {
//        cout << setw(10) << "---\t";
//    }

//    start_time = std::chrono::system_clock::now();
//    binary_insertionSort(linear_binary_array, array_size);
//    end_time = std::chrono::system_clock::now();
//    elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//    //cout << "Time for array[" << array_size << "] with binary insertion sort: " << elapsed_ns.count() << " ns.\n\n";
//    cout << setw(10) << elapsed_ns.count();

//    start_time = std::chrono::system_clock::now();
//    ShellSort(shell_array, array_size);
//    end_time = std::chrono::system_clock::now();
//    elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//    //cout << "Time for array[" << array_size << "] with Shell sort: " << elapsed_ns.count() << " ns.\n";
//    cout << setw(10) << elapsed_ns.count();

//    start_time = std::chrono::system_clock::now();
//    quickSort(quick_array, 0, array_size-1);
//    end_time = std::chrono::system_clock::now();
//    elapsed_ns = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
//    //cout << "Time for array[" << array_size << "] with quick sort: " << elapsed_ns.count() << " ns.\n\n";
//    cout << setw(10) << elapsed_ns.count() << "\n";


//    delete linear_array;
//    delete linear_binary_array;
//    delete shell_array;
//    delete quick_array;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
