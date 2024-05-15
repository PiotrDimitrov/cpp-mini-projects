#include <iostream>
#include "bigNum.h"

int main() {
    while (true){
        int i;
        std::cin >> i;
        bigNum n(i);
        std::cout << n.toStr();
    }

}