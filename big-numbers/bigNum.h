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
    void zeros();
    bigNum addZeros(int i);
    static bigNum toBN(std::string str);
    static bigNum toBN(int i);
public:
    bigNum();
    bigNum(std::string str);
    bigNum(const bigNum& other);
    bigNum(int i);
    bigNum& operator = (const bigNum& other);
    bigNum& operator = (std::string str);
    bigNum& operator = (int i);
    bigNum operator + (const bigNum num);
    bigNum operator + (std::string str);
    bigNum operator + (int i);
    bigNum operator * (const bigNum num);
    bigNum operator * (std::string str);
    bigNum operator * (int i);
    bigNum operator - (const bigNum num);
    bigNum operator - (std::string str);
    bigNum operator - (int i);
    bigNum operator / (const bigNum num);
    bigNum operator / (std::string str);
    bigNum operator / (int i);
    bigNum operator % (const bigNum num);
    bigNum operator % (std::string str);
    bigNum operator % (int i);
    bigNum operator ^ (const bigNum num);
    bigNum operator ^ (std::string str);
    bigNum operator ^ (int i);
    bool operator == (const bigNum& other) const;
    bool operator == (std::string str) const;
    bool operator == (int i) const;
    bool operator != (const bigNum& other) const;
    bool operator != (std::string str) const;
    bool operator != (int i) const;
    bool operator > (const bigNum& other) const;
    bool operator > (std::string str) const;
    bool operator > (int i) const;
    bool operator < (const bigNum& other) const;
    bool operator < (std::string str) const;
    bool operator < (int i) const;
    bool operator <= (const bigNum& other) const;
    bool operator <= (std::string str) const;
    bool operator <= (int i) const;
    bool operator >= (const bigNum& other) const;
    bool operator >= (std::string str) const;
    bool operator >= (int i) const;
    std::string toStr() const;
    static std::string toStr(long long x);
    void print();
};

#endif //BIG_NUMBERS_BIGNUM_H