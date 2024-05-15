#include <iostream>
#include "calculator.h"

int main() {
    std::string str = "4 + 6 * (1 + (3 + 3) * 6) - 1 + 5";
    //calculator c(str);
    //int x = c.rightBracket(0);
    //std::cout << x;
    std::cout << calculator::brStat(str) << std::endl;
    std::cout << calculator::noBrStat(str) << std::endl;
}