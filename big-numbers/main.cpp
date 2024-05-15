#include <iostream>
#include "bigNum.h"

int main() {
    bigNum result;
    result = "1";
    for (bigNum i("1"); i <= "200"; i = i + "1"){
        result = result * i;
    }
    result.print();
    /*
    while (true){
        std::string str1, str2;
        std::cin >> str1 >> str2;
        bigNum n1, n2;
        n1 = str1;
        n2 = str2;
        std::cout << "n1 > n2: " << (n1 > n2) << std::endl;
        std::cout << "n1 < n2: " << (n1 < n2) << std::endl;
        std::cout << "n1 >= n2: " << (n1 >= n2) << std::endl;
        std::cout << "n1 <= n2: " << (n1 <= n2) << std::endl;
        std::cout << "n1 == n2: " << (n1 == n2) << std::endl;
        std::cout << "n1 != n2: " << (n1 != n2) << std::endl;
    }
     */
}