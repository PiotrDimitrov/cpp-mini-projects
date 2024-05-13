#include <iostream>
#include "bigNum.h"

int main() {
    //while (true){
        std::string str1;
        std::cin >> str1;
        bigNum x(str1);
        std::cout << x.toStr();
    //}
}