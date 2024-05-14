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
    void clear();
    bool positive;
public:
    bigNum();
    bigNum(std::string str);
    bigNum(const bigNum& other);
    bigNum& operator = (const bigNum& other);
    bigNum operator + (const bigNum num);
    bigNum operator * (const bigNum num);
    bigNum operator - (const bigNum num);
    bool operator == (const bigNum& other) const;
    bool operator != (const bigNum& other) const;
    bool operator > (const bigNum& other) const;
    bool operator < (const bigNum& other) const;
    bool operator <= (const bigNum& other) const;
    bool operator >= (const bigNum& other) const;
    bigNum& operator = (std::string str);
    bigNum operator + (std::string str);
    bigNum operator * (std::string str);
    bigNum operator - (std::string str);
    bool operator == (std::string str) const;
    bool operator != (std::string str) const;
    bool operator > (std::string str) const;
    bool operator < (std::string str) const;
    bool operator <= (std::string str) const;
    bool operator >= (std::string str) const;
    //~bigNum();
    std::string toStr();
    static std::string toStr(long long x);
    void print();
};

#endif //BIG_NUMBERS_BIGNUM_H