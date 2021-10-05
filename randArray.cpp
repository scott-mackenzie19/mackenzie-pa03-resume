//
// Created by dalla on 10/4/2021.
//

#include "randArray.h"
#include <chrono>
#include <iostream>
#include "include/sorting_library.h"
using namespace std;

int *randArray::arrGenerator(int size) {
    int siz = 10;
    int* arr = new int[size];
    srand(time(0)); //seed reset as to not generate the same numbers each time
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; //generates random number between 0 and 10000
    }
    return arr;
}

void randArray::timeAtSize(int size) {
    double timeArray[5];
    for (int i = 0; i < 5; i++) {
        int* tempArray = arrGenerator(size); //random array generated of size size
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
        start = std::chrono::high_resolution_clock::now();
        mystery01(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray[i] = time_in_seconds.count();
        delete [] tempArray;
        //std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

    }
    double timeSum = 0;
    for (int i = 0; i < 5; i++) {
        timeSum += timeArray[i];
    }
    timeSum = timeSum / 5;
    std::cout << std::fixed << "Mystery1 Sum: " << timeSum << std::endl;
    double timeArray2[5];
    for (int i = 0; i < 5; i++) {
        int* tempArray = arrGenerator(size); //random array generated of size size
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
        start = std::chrono::high_resolution_clock::now();
        mystery02(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray2[i] = time_in_seconds.count();
        delete [] tempArray;
        //std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

    }
    double timeSum2 = 0;
    for (int i = 0; i < 5; i++) {
        timeSum2 += timeArray2[i];
    }
    timeSum2 = timeSum2 / 5;
    std::cout << std::fixed << "Mystery2 Sum: " << timeSum2 << std::endl;
    double timeArray3[5];
    for (int i = 0; i < 5; i++) {
        int* tempArray = arrGenerator(size); //random array generated of size size
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
        start = std::chrono::high_resolution_clock::now();
        mystery03(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray3[i] = time_in_seconds.count();
        delete [] tempArray;
        //std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

    }
    double timeSum3 = 0;
    for (int i = 0; i < 5; i++) {
        timeSum3 += timeArray3[i];
    }
    timeSum3 = timeSum3 / 5;
    std::cout << std::fixed << "Mystery3 Sum: " << timeSum3 << std::endl;
    double timeArray4[5];
    for (int i = 0; i < 5; i++) {
        int* tempArray = arrGenerator(size); //random array generated of size size
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
        start = std::chrono::high_resolution_clock::now();
        mystery04(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray4[i] = time_in_seconds.count();
        delete [] tempArray;
        //std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

    }
    double timeSum4 = 0;
    for (int i = 0; i < 5; i++) {
        timeSum4 += timeArray4[i];
    }
    timeSum4 = timeSum4 / 5;
    std::cout << std::fixed << "Mystery4 Sum: " << timeSum4 << std::endl;
    double timeArray5[5];
    for (int i = 0; i < 5; i++) {
        int* tempArray = arrGenerator(size); //random array generated of size size
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
        start = std::chrono::high_resolution_clock::now();
        mystery05(tempArray, size);
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_in_seconds = end - start;
        timeArray5[i] = time_in_seconds.count();
        delete [] tempArray;
        //std::cout << std::fixed << "Duration: " << time_in_seconds.count() << std::endl;

    }
    double timeSum5 = 0;
    for (int i = 0; i < 5; i++) {
        timeSum5 += timeArray5[i];
    }
    timeSum5 = timeSum5 / 5;
    std::cout << std::fixed << "Mystery5 Sum: " << timeSum5 << std::endl;

}
