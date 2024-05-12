#include "bigNum.h"

bigNum::bigNum() {
    digits.reserve(1);
}

bigNum::bigNum(std::string str) {
    for(int i = 0; i < str.length(); i++){
        digits.push_back(str[i] - '0');
    }
}

bigNum::bigNum(const bigNum& other){
    if (!other.digits.empty()){
        for (int i = 0; other.digits.size(); i++){
            this->digits[i] = other.digits[i];
        }
    }
}

bigNum& bigNum::operator=(const bigNum &other) {
    if (!other.digits.empty()) {
        for (int i = 0; other.digits.size(); i++) {
            this->digits[i] = other.digits[i];
        }
    }
}

void bigNum::carryOver(){
    for (int i = 0; i < digits.size() - 1; i++){
        if (digits[i] > 9){
            digits[i+1] += digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
    }
    while (digits[digits.size() - 1] > 9){
        digits.push_back(digits[digits.size() - 1] / 10);
        digits[digits.size() - 2] = digits[digits.size() - 2] % 10;
    }
}

void bigNum::print() {
    for (auto i : digits){
        std::cout << i;
    }
    std::cout << std::endl;
}

