#include <iostream>
#include "bigNum.h"

int main() {
    while (true){
        int i, j;
        std::cin >> i >> j;
        bigNum n(i);
        bigNum m(j);
        std::cout << (n / m).toStr();
    }
}