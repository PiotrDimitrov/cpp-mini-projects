#include <iostream>
#include "bigNum.h"

int main() {
                    //18446744073709551615
    bigNum x("");
    bigNum y("0");
    bigNum z = x * y;
    std::cout << z.toStr();
}