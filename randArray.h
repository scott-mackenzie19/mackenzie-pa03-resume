//
// Created by dalla on 10/4/2021.
//

#ifndef PA03_TEMPLATE_RANDARRAY_H
#define PA03_TEMPLATE_RANDARRAY_H
#include <random>
#include "DSString.h"
using namespace std;

class randArray {
private:
    double Nsquared[3];
    DSString wordVectorsq[3];
    double Nlog[2];
    DSString wordVectorlog[2];

public:
    int* arrGenerator(int size);
    void timeAtSize(int size);
    void reverseTest(int size);





};


#endif //PA03_TEMPLATE_RANDARRAY_H
