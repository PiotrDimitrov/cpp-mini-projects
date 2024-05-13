#include <iostream>
#include "bigNum.h"

int main() {
        bigNum x("6391");
        bigNum y("2030");
        bigNum z = x * y;
        z.print();
}