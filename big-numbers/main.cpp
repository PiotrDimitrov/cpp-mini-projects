#include <iostream>
#include "bigNum.h"

int main() {
    bigNum x("61943");
    bigNum y("59129");
    bigNum z = x - y;
    //std::cout << z.toStr();
    z.print();
}