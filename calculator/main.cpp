#include <iostream>
#include "calculator.h"
#include <bits/stdc++.h>

int main() {
    std::cout << "Type your expression:  \n";
    std::string str;
    while (true) {
        std::cin >> str;
        std::cout << calculator::refactor(str) << std::endl;
        std::cout << "Answer: " << calculator::eval(str) << std::endl;
    }
}