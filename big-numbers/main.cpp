#include <iostream>
#include "bigNum.h"

int main() {
    while (true) {
        bigNum x("609");
        bigNum y("10");
        bigNum z = x / y;
        //std::cout << z.toStr();
        z.print();
    }

}