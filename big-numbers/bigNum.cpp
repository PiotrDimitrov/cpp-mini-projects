#include "bigNum.h"

bigNum::bigNum(){
    //digits.push_back(0);
}

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

int bigNum::size() const {
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

bool bigNum::operator == (const bigNum& other) const {
    return digits == other.digits;
}

bool bigNum::operator != (const bigNum& other) const {
    return !(digits == other.digits);
}

bool bigNum::operator < (const bigNum& other) const {
    if (other == (*this)) {return false;}
    if (other.size() > this->size()) {return true;}
    if (other.size() < this->size()) {return false;}
    for (int i = this->size() - 1; i >= 0; i++){
        if (other.digits[i] > this->digits[i]) {return true;}
        if (other.digits[i] < this->digits[i]) {return false;}
    }
    return false;
}

bool bigNum::operator > (const bigNum& other) const {
    if (other == (*this)) {return false;}
    if (other.size() > this->size()) {return false;}
    if (other.size() < this->size()) {return true;}
    for (int i = this->size() - 1; i >= 0; i++){
        if (other.digits[i] > this->digits[i]) {return false;}
        if (other.digits[i] < this->digits[i]) {return true;}
    }
    return false;
}

bool bigNum::operator >= (const bigNum& other) const {
    if (other == (*this)) {return true;}
    if (other.size() > this->size()) {return false;}
    if (other.size() < this->size()) {return true;}
    for (int i = this->size() - 1; i >= 0; i++){
        if (other.digits[i] > this->digits[i]) {return false;}
        if (other.digits[i] < this->digits[i]) {return true;}
    }
    return true;
}

bool bigNum::operator <= (const bigNum& other) const {
    if (other == (*this)) {return true;}
    if (other.size() > this->size()) {return true;}
    if (other.size() < this->size()) {return false;}
    for (int i = this->size() - 1; i >= 0; i++){
        if (other.digits[i] > this->digits[i]) {return true;}
        if (other.digits[i] < this->digits[i]) {return false;}
    }
    return true;
}

bigNum bigNum::operator * (const bigNum num) {
    bigNum result("0");
    bigNum temp;
    result.digits.reserve(this->size() + num.size());
    int tens = 0;
    for (int nm : num.digits) {
        int remainder = 0;
        for (int th : this->digits) {
            temp.digits.push_back((nm * th + remainder) % 10);
            remainder = (nm * th + remainder) / 10;
        }
        while (remainder > 0) {
            temp.digits.push_back(remainder % 10);
            remainder /= 10;
        }
        result = result + temp;
        temp.clear();
        tens++;
        for (int i = 0; i < tens; i++) {temp.digits.push_back(0);}
    }
    return result;
}

std::string bigNum::toStr() {
    char symb;
    std::string result;
    for (int i = 0; i < this->size(); i++){
        symb = char ('0' + digits[i]);
        result = symb + result;
    }
    return result;
}

void bigNum::clear() {
    digits.clear();
    //digits.push_back(0);
}

std::string bigNum::toStr(long long x) {
    std::string result;
    while (x > 0){
        result = char('0' + (x % 10)) + result;
        x /= 10;
    }
    return result;
}