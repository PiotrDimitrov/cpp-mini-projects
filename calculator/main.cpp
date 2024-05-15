#include <iostream>
#include "calculator.h"

int main() {
    std::string str = " a/b+c def - gH 12  3 4  !% ";
    calculator::refactor(str);
    std::cout << str;
}