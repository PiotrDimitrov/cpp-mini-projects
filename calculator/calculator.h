#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include <iostream>


struct stringSlice {
    int first;
    int second;
    std::string str;
};

class calculator {
public:
    static float eval(std::string);
    float eval();
    calculator(std::string);
private:
public:
    std::string statement;
    void spaces();
    static void spaces(std::string& statement);
    void refactor();
    static void refactor(std::string& statement);
    static int toInt(std::string str);
    std::string strSlice(int index1, int index2);
    static std::string strSlice(const std::string str, int index1, int index2);
    int rightBracket(int index);
    static int leftBracket(std::string str);
    static int rightBracket(std::string str);
    static std::string brStat(std::string str);
    static stringSlice brackets(std::string str);
    static std::string noBrStat(std::string str);

};


#endif //CALCULATOR_CALCULATOR_H
