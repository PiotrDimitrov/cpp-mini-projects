#ifndef BIG_NUMBERS_BIGNUM_H
#define BIG_NUMBERS_BIGNUM_H
#include <vector>
#include <iostream>

class bigNum {
private:
public:
    std::vector<int> digits;
    int operator [] (int index);
    int size() const;
public:
    bigNum();
    bigNum(std::string str);
    bigNum(const bigNum& other);
    bigNum& operator = (const bigNum& other);
    bigNum operator + (const bigNum num);
    bool operator == (const bigNum& other) const;
    bool operator != (const bigNum& other) const;
    bool operator > (const bigNum& other);
    bool operator < (const bigNum& other);
    //~bigNum();
    //std::string toStr();
    std::string toStr();
    static std::string toStr(int x);
    static std::string toStr(long long x);
    void print();
};

#endif //BIG_NUMBERS_BIGNUM_H