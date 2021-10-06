#include <iostream>
#include <chrono>
#include "include/sorting_library.h"
#include "randArray.h"
using namespace std;


int main() {

    randArray one;
    double array[5];
    one.timeAtSize(10);
    one.timeAtSize(100);
    one.timeAtSize(1000);
    one.timeAtSize(2000);
    one.timeAtSize(5000);
    one.timeAtSize(10000);
    double aye[5];
   // one.timeAtSize(20000);
   // one.timeAtSize(30000);
  //  one.timeAtSize(40000);
   // one.timeAtSize(50000);
    //one.timeAtSize(100000);
   // one.timeAtSize(1000000);
    //one.timeAtSize(50000);

    one.reverseTest(10000);

    return 0;
}
