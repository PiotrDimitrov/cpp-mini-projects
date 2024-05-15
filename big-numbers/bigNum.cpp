#include "bigNum.h"

bigNum::bigNum(){
    positive = true;
    //digits.push_back(0);
}

bigNum::bigNum(std::string str) {
    digits.reserve(str.length());
    positive = true;
    for(int i = str.length()-1; i >= 0; i--){
        if (str[i] == '-') { positive = false; continue;}
        digits.push_back(str[i] - '0');
    }
    zeros();
}

bigNum::bigNum(const bigNum& other){
    this->digits = other.digits;
    this->positive = other.positive;
}

bigNum::bigNum(int i) {
    if (i < 0) {i *= -1; positive = false;}
    else {positive = true;}
    if (i == 0) {digits.push_back(0);}
    while (i > 0){
        digits.push_back(i % 10);
        i /= 10;
    }
}

bigNum& bigNum::operator=(const bigNum& other) {
    if (this != &other) {
        this->digits = other.digits;
        this->positive = other.positive;
    }
    return *this;
}

bigNum& bigNum::operator=(std::string str) {
    bigNum other(str);
    if (this != &other) {
        this->digits = other.digits;
        this->positive = other.positive;
    }
    return *this;
}

bigNum& bigNum::operator=(int i) {
    bigNum other(i);
    if (this != &other) {
        this->digits = other.digits;
        this->positive = other.positive;
    }
    return *this;
}

void bigNum::print() {
    if (!positive) {std::cout << '-';}
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
    if (this->positive == num.positive) {
        result.positive = this->positive;
        result.digits.reserve(std::max(this->digits.size(), num.digits.size()) + 1);
        int remainder = 0; int i;
        for (i = 0; i < this->size() || i < num.size(); i++){
            result.digits.push_back(((*this)[i] + num[i] + remainder) % 10);
            remainder = ((*this)[i] + num[i] + remainder) / 10;
        }
        if (remainder > 0) {
            result.digits.push_back(remainder);
        }
        result.zeros();
        return result;
    } else {
        if (!this->positive && num.positive){
            bigNum n1, n2;
            n1 = *this; n2 = num;
            n1.positive = n2.positive = true;
            return n2 - n1;
        }
        if (this->positive && !num.positive){
            bigNum n1, n2;
            n1 = *this; n2 = num;
            n1.positive = n2.positive = true;
            return n1 - n2;
        }
    }
}

bigNum bigNum::operator+(std::string str) {
    bigNum num(str);
    return (*this) + num;
}

bigNum bigNum::operator+(int i) {
    bigNum num(i);
    return (*this) + num;
}

bool bigNum::operator == (const bigNum& other) const {
    return (digits == other.digits) && (positive == other.positive);
}

bool bigNum::operator==(std::string str) const {
    bigNum other(str);
    return *this == other;
}

bool bigNum::operator==(int i) const {
    bigNum other(i);
    return *this == other;
}

bool bigNum::operator != (const bigNum& other) const {
    return digits != other.digits || positive != other.positive;
}

bool bigNum::operator!=(std::string str) const {
    bigNum other(str);
    return *this != other;
}

bool bigNum::operator!=(int i) const {
    bigNum other(i);
    return *this != other;
}

bool bigNum::operator>(const bigNum& other) const {
    if (*this == other) {return false;}
    if (digits.size() > other.digits.size()){
        return true;
    }
    else if (digits.size() < other.digits.size()){
        return false;
    }
    for (size_t i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] > other.digits[i]){
            return true;
        }
        else if (digits[i] < other.digits[i]){
            return false;
        }
    }
}

bool bigNum::operator>(std::string str) const {
    bigNum other(str);
    return *this > other;
}

bool bigNum::operator>(int i) const {
    bigNum other(i);
    return *this > other;
}

bool bigNum::operator<(const bigNum& other) const {
    return other > *this;
}

bool bigNum::operator<(std::string str) const {
    bigNum other(str);
    return *this < other;
}

bool bigNum::operator<(int i) const {
    bigNum other(i);
    return *this < other;
}

bool bigNum::operator >= (const bigNum& other) const {
    return *this > other || *this == other;
}

bool bigNum::operator>=(std::string str) const {
    bigNum other(str);
    return *this >= other;
}

bool bigNum::operator>=(int i) const {
    bigNum other(i);
    return *this >= other;
}

bool bigNum::operator <= (const bigNum& other) const {
    return *this < other || *this == other;
}

bool bigNum::operator<=(std::string str) const {
    bigNum other(str);
    return *this <= other;
}

bool bigNum::operator<=(int i) const {
    bigNum other(i);
    return *this <= other;
}

bigNum bigNum::operator * (const bigNum num) {
    bigNum result("0");
    bigNum temp;
    if (this->positive != num.positive) {result.positive = false;}
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
    result.zeros();
    return result;
}

bigNum bigNum::operator*(std::string str) {
    bigNum num(str);
    return (*this) * num;
}

bigNum bigNum::operator*(int i) {
    bigNum num(i);
    return (*this) * num;
}

bigNum bigNum::operator-(const bigNum num) {
    bigNum num1, num2, result; //result = num1 - num2
    if (this->positive && !num.positive) {
        num1 = *this; num2 = num;
        num1.positive = num2.positive = true;
        return num1 + num2;
    }
    if (!this->positive && num.positive) {
        num1 = *this; num2 = num;
        num1.positive = num2.positive = true;
        result = num1 + num2;
        result.positive = false;
        result.zeros();
        return result;
    }
    if (!this->positive && !num.positive){
        num1 = *this; num2 = num;
        num1.positive = num2.positive = true;
        result = num2 - num1;
        result.zeros();
        return result;
    }
    if (this->positive && num.positive) {
        int digit;
        if (*this >= num) {num1 = (*this); num2 = num; result.positive = true;}
        else {num1 = num; num2 = (*this); result.positive = false;}
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] >= num2[i]) {digit = num1[i] - num2[i];}
            else {digit = num1[i] + 10 - num2[i]; num1.digits[i+1] -= 1;}
            result.digits.push_back(digit);
        }
        result.zeros();
        return result;
    }
}

bigNum bigNum::operator-(std::string str) {
    bigNum num(str);
    return (*this) - num;
}

bigNum bigNum::operator-(int i) {
    bigNum num(i);
    return (*this) - num;
}

bigNum bigNum::operator/(const bigNum num) {
    bigNum counter("0");
    counter.positive = (this->positive == num.positive);
    bigNum div1 = *this;
    bigNum div2 = num;
    div1.positive = div2.positive = true;
    while (div1.positive) {
        div1 = div1 - div2;
        counter = counter + "1";
    }
    counter = counter - "1";
    counter.zeros();
    return counter;
}

bigNum bigNum::operator/(std::string str) {
    bigNum num(str);
    return *this / num;
}

bigNum bigNum::operator/(int i) {
    bigNum num(i);
    return *this / num;
}

std::string bigNum::toStr() const{
    char symb;
    std::string result;
    for (int i = 0; i < this->size(); i++){
        symb = char ('0' + digits[i]);
        result = symb + result;
    }
    if (positive) {return result;}
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

void bigNum::zeros() {
    for (int i = this->size() - 1; i > 0; i--){
        if (this->digits[i] == 0) {this->digits.pop_back();}
        else {break;}
    }
}