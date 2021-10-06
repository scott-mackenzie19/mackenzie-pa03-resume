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

void randArray::timeAtSize(int size) { //function timeAtSize checks the average timing of each sorting function given
    //a randomly generated array of given size. Appends the averages to an array

    cout << "Size: " << size << endl;
    cout << endl;
    double timeArray[15];
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 15; i++) {
        timeSum += timeArray[i];
    }
    timeSum = timeSum / 15;
    std::cout << std::fixed << "Mystery1 Time: " << timeSum << std::endl;
    double timeArray2[15];
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 15; i++) {
        timeSum2 += timeArray2[i];
    }
    timeSum2 = timeSum2 / 15;
    std::cout << std::fixed << "Mystery2 Time: " << timeSum2 << std::endl;
    double timeArray3[15];
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 15; i++) {
        timeSum3 += timeArray3[i];
    }
    timeSum3 = timeSum3 / 15;
    std::cout << std::fixed << "Mystery3 Time: " << timeSum3 << std::endl;
    double timeArray4[15];
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 15; i++) {
        timeSum4 += timeArray4[i];
    }
    timeSum4 = timeSum4 / 15;
    std::cout << std::fixed << "Mystery4 Time: " << timeSum4 << std::endl;
    double timeArray5[15];
    for (int i = 0; i < 15; i++) {
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
    for (int i = 0; i < 15; i++) {
        timeSum5 += timeArray5[i];
    }
    timeSum5 = timeSum5 / 15;
    std::cout << std::fixed << "Mystery5 Time: " << timeSum5 << std::endl;

}

void randArray::reverseTest(int size) {
    int arr[size];
    int num = size;
    for (int i = 0; i < size; i++) {
        //cout << num;
        arr[i] = num;
        num--;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //create start and end point objects
    start = std::chrono::high_resolution_clock::now();
    mystery01(arr, size);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_in_seconds = end - start;
    cout << std::fixed << "Reverse1: " << time_in_seconds.count() << std::endl;

    int arr2[size];
    int num2 = size;
    for (int i = 0; i < size; i++) {
        //cout << num;
        arr2[i] = num2;
        num2--;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start2, end2; //create start and end point objects
    start2 = std::chrono::high_resolution_clock::now();
    mystery02(arr2, size);
    end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_in_seconds2 = end2 - start2;
    cout << std::fixed << "Reverse2: " << time_in_seconds2.count() << std::endl;

    int arr3[size];
    int num3 = size;
    for (int i = 0; i < size; i++) {
        //cout << num;
        arr3[i] = num3;
        num3--;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start3, end3; //create start and end point objects
    start3 = std::chrono::high_resolution_clock::now();
    mystery03(arr3, size);
    end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_in_seconds3 = end3 - start3;
    cout << std::fixed << "Reverse3: " << time_in_seconds3.count() << std::endl;

    int arr4[size];
    int num4 = size;
    for (int i = 0; i < size; i++) {
        //cout << num;
        arr4[i] = num4;
        num4--;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start4, end4; //create start and end point objects
    start4 = std::chrono::high_resolution_clock::now();
    mystery04(arr4, size);
    end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_in_seconds4 = end4 - start4;
    cout << std::fixed << "Reverse4: " << time_in_seconds4.count() << std::endl;

    int arr5[size];
    int num5 = size;
    for (int i = 0; i < size; i++) {
        //cout << num;
        arr5[i] = num5;
        num5--;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start5, end5; //create start and end point objects
    start5 = std::chrono::high_resolution_clock::now();
    mystery05(arr5, size);
    end5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_in_seconds5 = end5 - start5;
    cout << std::fixed << "Reverse5: " << time_in_seconds5.count() << std::endl;

}
