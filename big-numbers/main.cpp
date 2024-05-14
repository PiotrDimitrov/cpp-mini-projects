#include <iostream>
#include "bigNum.h"

int main() {
    bigNum x("-6143");
    bigNum y("-123");
    bigNum z = x - y;
    //std::cout << z.toStr();
    z.print();
}