#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include <iostream>


struct stringSlice {
    int first;
    int second;
    std::string str;
};

struct afterOper {
    int first;
    int second;
    int result;
};

class calculator {
public:
    static int eval(std::string);


private:
public:
    std::string statement;
    void spaces();
    void refactor();
    std::string strSlice(int index1, int index2);
    int rightBracket(int index);
    int eval();
    calculator(std::string);
    static std::string brStat(std::string str);
    static std::string noBrStat(std::string str);
    static int leftBracket(std::string str);
    static int rightBracket(std::string str);

    static void spaces(std::string& statement);
    static void refactor(std::string& statement);
    static int toInt(std::string str);
    static std::string strSlice(const std::string str, int index1, int index2);
    static stringSlice brackets(std::string str);
    static afterOper operation(int signIndex, const std::string str);
    static std::string toStr(int num);
    static std::string insert(std::string ins, std::string& str, int first, int second);
};


#endif //CALCULATOR_CALCULATOR_H
