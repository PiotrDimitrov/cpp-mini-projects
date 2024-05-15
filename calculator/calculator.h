#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include <iostream>


class calculator {
public:
    static float eval(std::string);
    float eval();
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
};


#endif //CALCULATOR_CALCULATOR_H
