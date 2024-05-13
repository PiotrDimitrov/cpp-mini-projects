#include <iostream>
#include "bigNum.h"

int main() {
bigNum x("7162");
bigNum y("9435");
bigNum z = x + y;
z.print();
}