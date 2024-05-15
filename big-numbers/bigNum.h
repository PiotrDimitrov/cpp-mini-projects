#ifndef BIG_NUMBERS_BIGNUM_H
#define BIG_NUMBERS_BIGNUM_H
#include <vector>
#include <iostream>

class bigNum {
private:
    std::vector<int> digits;
    int operator [] (int index);
    int size() const;
    void clear();
    bool positive;
    void zeros();
public:
    bigNum();
    bigNum(std::string str);
    bigNum(const bigNum& other);

    bigNum& operator = (const bigNum& other);
    bigNum& operator = (std::string str);

    bigNum operator + (const bigNum num);
    bigNum operator + (std::string str);

    bigNum operator * (const bigNum num);
    bigNum operator * (std::string str);

    bigNum operator - (const bigNum num);
    bigNum operator - (std::string str);

    bigNum operator / (const bigNum num);
    bigNum operator / (std::string str);

    bool operator == (const bigNum& other) const;
    bool operator == (std::string str) const;

    bool operator != (const bigNum& other) const;
    bool operator != (std::string str) const;

    bool operator > (const bigNum& other) const;
    bool operator > (std::string str) const;

    bool operator < (const bigNum& other) const;
    bool operator < (std::string str) const;

    bool operator <= (const bigNum& other) const;
    bool operator <= (std::string str) const;

    bool operator >= (const bigNum& other) const;
    bool operator >= (std::string str) const;

    std::string toStr() const;
    static std::string toStr(long long x);
    void print();
};

#endif //BIG_NUMBERS_BIGNUM_H