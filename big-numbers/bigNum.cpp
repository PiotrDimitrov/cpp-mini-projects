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


void bigNum::print() {
    for (auto i : digits){
        std::cout << i;
    }
    std::cout << std::endl;
}

