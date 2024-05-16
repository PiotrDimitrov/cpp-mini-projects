#include <iostream>
#include "calculator.h"
#include <bits/stdc++.h>

int main() {
//    std::cout << "Type your expression:  \n";
//    std::string str = "-1-3";
//    while (true) {
//        std::cin >> str;
//        std::cout << "Answer: " << calculator::eval(str) << std::endl;
//    }

std::string str = "6+5*()";
std::cout << calculator::eval(str);

}