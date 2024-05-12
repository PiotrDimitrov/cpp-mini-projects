#ifndef BIG_NUMBERS_BIGNUM_H
#define BIG_NUMBERS_BIGNUM_H
#include <vector>
#include <iostream>

class bigNum {
private:
    std::vector<int> digits;
    //void carryOver();
public:
    bigNum();
    bigNum(std::string str);
    bigNum(const bigNum& other);
    bigNum& operator = (const bigNum& other);
    //bigNum operator + (const bigNum num);
    //~bigNum();
    //std::string toStr();
    static std::string toStr(int x);
    static std::string toStr(long long x);
    void print();
};

#endif //BIG_NUMBERS_BIGNUM_H