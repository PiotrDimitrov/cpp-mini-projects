#include <iostream>
#include "calculator.h"
#include <bits/stdc++.h>

int main() {
    /*
    std::string str = "4 + 6 * (1 + (3 + 3) * 6) - 1 + 5";

    std::cout << calculator::brStat(str) << std::endl;
    std::cout << calculator::noBrStat(str) << std::endl;
    
    stringSlice ss = calculator::brackets(str);
    std::cout << ss.first << std::endl; //index of first opening (
    std::cout << ss.second << std::endl; // index of corresponding closing )
    std::cout << ss.str << std::endl; //string between outer pair of brackets
     */
    std::string str = "14+17^2-1";
    afterOper r = calculator::operation(5, str);
    std::cout << r.result << " " << r.first << " " << r.second;
}