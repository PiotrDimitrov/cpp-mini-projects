#include <iostream>
#include "bigNum.h"

int main() {
    while (true){
        std::string str1, str2;
        std::cin >> str1 >> str2;

        bigNum x(str1);
        bigNum y(str2);
        bigNum z = x + y;
        z.print();
    }
}