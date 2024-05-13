#include "bigNum.h"

bigNum::bigNum() = default;

bigNum::bigNum(std::string str) {
    digits.reserve(str.length());
    for(int i = 0; i < str.length(); i++){
        digits.push_back(str[i] - '0');
    }
}

bigNum::bigNum(const bigNum& other){
    this->digits = other.digits;
}


bigNum& bigNum::operator=(const bigNum& other) {
    if (this != &other) {
        this->digits = other.digits;
    }
    return *this;
}

void bigNum::print() {
    for (auto i : digits){
        std::cout << i;
    }
    std::cout << std::endl;
}

int bigNum::size() {
    return digits.size();
}

int bigNum::operator[](int index) {
    if (index >= this->digits.size() || index < 0) {
        return 0;
    } else {
        return this->digits[index];
    }
}

bigNum bigNum::operator+(bigNum num) {
    bigNum result;
    result.digits.reserve(std::max(this->digits.size(), num.digits.size()) + 1);
    int remainder = 0; int i;
    for (i = 0; i < this->size() || i < num.size(); i++){
        result.digits[i] = ((*this)[i] + num[i] + remainder) % 10;
        remainder = ((*this)[i] + num[i] + remainder) / 10;
    }
    if (remainder > 0) {
        result.digits[i+1] = remainder;
    }
    return result;
}