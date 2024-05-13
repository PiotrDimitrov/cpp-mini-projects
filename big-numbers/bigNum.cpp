#include "bigNum.h"

bigNum::bigNum() = default;

bigNum::bigNum(std::string str) {
    digits.reserve(str.length());
    for(int i = str.length()-1; i >= 0; i--){
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
    for (int i = this->size()-1; i >= 0; i--){
        std::cout << digits[i];
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
        result.digits.push_back(((*this)[i] + num[i] + remainder) % 10);
        remainder = ((*this)[i] + num[i] + remainder) / 10;
    }
    if (remainder > 0) {
        result.digits.push_back(remainder);
    }
    return result;
}