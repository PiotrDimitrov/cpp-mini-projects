#include <iostream>
#include "bigNum.h"

int main() {
    while (true){
        std::string str1, str2;
        std::cin >> str1 >> str2;

        bigNum x(str1);
        bigNum y(str2);
        std::cout << (x < y) << std::endl;
        std::cout << (x == y) << std::endl;
    }
}