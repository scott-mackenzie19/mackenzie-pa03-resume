//
// Created by dalla on 10/4/2021.
//

#include "randArray.h"
#include <chrono>
#include <iostream>
#include "include/sorting_library.h"
#include "DSString.h"
using namespace std;
//comments placed above referenced lines of code


//function below generates random array
int *randArray::arrGenerator(int size) {
    int siz = 10;
    int* arr = new int[size];
    //seed reset as to not generate the same numbers each time
    srand(time(0));
    for (int i = 0; i < size; i++) {
        //generates random number between 0 and 10000
        arr[i] = rand() % 10000;

    }
    return arr;
}
//function timeAtSize checks the average timing of each sorting function given
//a randomly generated array of given size. Based off these times, it adds each time
//to either a nlogn set of parallel arrays or n^2 parallel arrays.
void randArray::timeAtSize(int size) {
    double avgArray[5];
    DSString mysteryArray[5] = {"Mystery 01", "Mystery 02", "Mystery 03", "Mystery 04", "Mystery 05"};
    cout << "Size: " << size << endl;
    double timeArray[15];
    for (int i = 0; i < 15; i++) {
        //random array generated of given size
        int* tempArray = arrGenerator(size);
        //create start and end point objects
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        mystery01(tempArray, size);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray[i] = time_in_seconds.count();
        delete [] tempArray;
    }
    double timeSum = 0;
    for (int i = 0; i < 15; i++) {
        timeSum += timeArray[i];
    }
    //time for 15 random arrays averaged and added to an array
    timeSum = timeSum / 15;
    avgArray[0] = timeSum;
    std::cout << std::fixed << "Mystery01 Time: " << timeSum << std::endl;


    double timeArray2[15];
    for (int i = 0; i < 15; i++) {
        int* tempArray = arrGenerator(size);
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        mystery02(tempArray, size);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray2[i] = time_in_seconds.count();
        delete [] tempArray;
    }
    double timeSum2 = 0;
    for (int i = 0; i < 15; i++) {
        timeSum2 += timeArray2[i];
    }
    timeSum2 = timeSum2 / 15;
    avgArray[1] = timeSum2;
    std::cout << std::fixed << "Mystery02 Time: " << timeSum2 << std::endl;


    double timeArray3[15];
    for (int i = 0; i < 15; i++) {
        int* tempArray = arrGenerator(size);
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        mystery03(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray3[i] = time_in_seconds.count();
        delete [] tempArray;
    }
    double timeSum3 = 0;
    for (int i = 0; i < 15; i++) {
        timeSum3 += timeArray3[i];
    }
    timeSum3 = timeSum3 / 15;
    avgArray[2] = timeSum3;
    std::cout << std::fixed << "Mystery03 Time: " << timeSum3 << std::endl;


    double timeArray4[15];
    for (int i = 0; i < 15; i++) {
        int* tempArray = arrGenerator(size);
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        mystery04(tempArray, size);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray4[i] = time_in_seconds.count();
        delete [] tempArray;
    }
    double timeSum4 = 0;
    for (int i = 0; i < 15; i++) {
        timeSum4 += timeArray4[i];
    }
    timeSum4 = timeSum4 / 15;
    avgArray[3] = timeSum4;
    std::cout << std::fixed << "Mystery04 Time: " << timeSum4 << std::endl;


    double timeArray5[15];
    for (int i = 0; i < 15; i++) {
        int* tempArray = arrGenerator(size);
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        mystery05(tempArray, size);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray5[i] = time_in_seconds.count();
        delete [] tempArray;
    }
    double timeSum5 = 0;
    for (int i = 0; i < 15; i++) {
        timeSum5 += timeArray5[i];
    }
    timeSum5 = timeSum5 / 15;
    avgArray[4] = timeSum5;
    std::cout << std::fixed << "Mystery05 Time: " << timeSum5 << std::endl;
    cout << endl;

    //below code block only executes when testing the largest array
    if (size == 10000) {
        int i, j;
        //Both the avgArray and a parallel array containing the sorter names are sorted in sync
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5 - i - 1; j++) {
                if (avgArray[j] > avgArray[j+1]) {
                    double temp;
                    DSString temp2;
                    temp = avgArray[j];
                    temp2 = mysteryArray[j];
                    avgArray[j] = avgArray[j + 1];
                    mysteryArray[j] = mysteryArray[j + 1];
                    avgArray[j + 1] = temp;
                    mysteryArray[j + 1] = temp2;

                }
            }
        }
        Nsquared[0] = avgArray[2];
        Nsquared[1] = avgArray[3];
        Nsquared[2] = avgArray[4];
        wordVectorsq[0] = mysteryArray[2];
        wordVectorsq[1] = mysteryArray[3];
        wordVectorsq[2] = mysteryArray[4];
        //O(n^2) array populated as well as parallel word array
        Nlog[0] = avgArray[0];
        Nlog[1] = avgArray[1];
        wordVectorlog[0] = mysteryArray[0];
        wordVectorlog[1] = mysteryArray[1];
        //O(nlogn) array populated as well as parallel word array
    }
}
//below function essentially utilizes the newly populated parallel vectors from the above function, and runs
//them through a variety of tests to determine which algorithm is which
void randArray::reverseTest(int size) {
    double compare1;
    double holder[2];
    DSString nameHolder[2];
    DSString nameHolder2[3];
    double holder2[3];
    int sacredIndex;
    cout << "Classifications" << endl;
    //below for loop iterates over both the nlogn average time parallel arrays, testing on a reverse ordered array
    //to determine which is quick sort and which is Merge sort.
    for (int i = 0; i < 2; i++) {
            int arr[size];
            int num = size;
            //array in reverse order generated
            for (int i = 0; i < size; i++) {
                arr[i] = num;
                num--;
            }
            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
            start = std::chrono::high_resolution_clock::now();
            //below block of code allows for algorithms to be swapped and still produce correct results
            if (wordVectorlog[i] == "Mystery 01") {
                mystery01(arr, size);
            }
            else if (wordVectorlog[i] == "Mystery 02") {
                mystery02(arr, size);
            }
            else if (wordVectorlog[i] == "Mystery 03") {
                mystery03(arr, size);
            }
            else if (wordVectorlog[i] == "Mystery 04") {
                mystery04(arr, size);
            }
            else if (wordVectorlog[i] == "Mystery 05") {
                mystery05(arr, size);
            }
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_in_seconds = end - start;
            double timeDiff = time_in_seconds.count() - Nlog[i];
            compare1 = timeDiff;
            holder[i] = compare1;
            nameHolder[i] = wordVectorlog[i];
        }
    if (holder[0] < holder[1]) {
        cout << nameHolder[1] << ": " << "Quicksort" << endl;
        cout << nameHolder[0] << ": " << "Merge Sort" << endl;
    }
    else {
        cout << nameHolder[0] << ": " << "Quicksort" << endl;
        cout << nameHolder[1] << ": " << "Merge Sort" << endl;
    }
    for (int i = 0; i < 3; i++) {
        int arr[size];
        int num = size;
        //reverse array generated to be sorted bt the sorting algorithms in n^2 arrays
        for (int i = 0; i < size; i++) {
            arr[i] = num;
            num--;
        }
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        //below block of code allows for interchanging
        if (wordVectorsq[i] == "Mystery 01") {
            mystery01(arr, size);
        }
        else if (wordVectorsq[i] == "Mystery 02") {
            mystery02(arr, size);
        }
        else if (wordVectorsq[i] == "Mystery 03") {
            mystery03(arr, size);
        }
        else if (wordVectorsq[i] == "Mystery 04") {
            mystery04(arr, size);
        }
        else if (wordVectorsq[i] == "Mystery 05") {
            mystery05(arr, size);
        }
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_in_seconds = end - start;
        double timeDiff = time_in_seconds.count() - Nsquared[i];
        compare1 = timeDiff;
        holder2[i] = compare1;
        nameHolder2[i] = wordVectorsq[i];
    }
    //maximum determined of the difference between the timing in reverse and normal
    double max = 0;
    sacredIndex = 0;
    for (int i = 0; i < 3; i++) {
        if (holder2[i] > max) {
            holder2[i] = max;
            sacredIndex = i;
        }
    }
    //Maximum is insertion sort as its worst case is in reverse array
    cout << nameHolder2[sacredIndex] << ": " << "Insertion Sort" << endl;

    double timeArray[15];
    double holda[3];
    DSString wordHolda[3];
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 15; i++) {
            int *tempArray = arrGenerator(10000);
            std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
            start = std::chrono::high_resolution_clock::now();
            if (wordVectorsq[j] == "Mystery 01") {
                mystery01(tempArray, size);
            }
            else if (wordVectorsq[j] == "Mystery 02") {
                mystery02(tempArray, size);
            }
            else if (wordVectorsq[j] == "Mystery 03") {
                mystery03(tempArray, size);
            }
            else if (wordVectorsq[j] == "Mystery 04") {
                mystery04(tempArray, size);
            }
            else if (wordVectorsq[j] == "Mystery 05") {
                mystery05(tempArray, size);
            }
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            timeArray[i] = time_in_seconds.count();
            delete[] tempArray;
        }
        double timeSum4 = 0;
        for (int i = 0; i < 15; i++) {
            timeSum4 += timeArray[i];
        }
        timeSum4 = timeSum4 / 15;
        holda[j] = timeSum4;
        wordHolda[j] = wordVectorsq[j];
    }
    //maximum of the N^2 times is determined, this is bubble sort as this is least efficient
    double maximum = 0;
    int holdex = 0;
    for (int i = 0; i < 3; i++ ) {
        if (holda[i] > maximum) {
            maximum = holda[i];
            holdex = i;
        }
    }
    cout << wordVectorsq[holdex] << ": " << "Bubble sort" << endl;
    //remaining array must be selection sort
    int num =  3 - holdex - sacredIndex ;
    cout << wordVectorsq[num] << ": " << "Selection sort";








}
