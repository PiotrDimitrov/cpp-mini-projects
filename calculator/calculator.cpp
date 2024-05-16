#include "calculator.h"
#include <bits/stdc++.h>


void calculator::spaces(std::string& statement) {
    std::string temp;
    for (int i = 0; i < statement.length(); i++){
        if (statement[i] != ' ') {temp = temp + statement[i];}
    }
    statement = temp;
}

void calculator::refactor(std::string& statement) {
    std::string allowed = "1234567890-+/^*()%";
    std::string temp;
    for (char st : statement) {
        bool flag = false;
        for (char al : allowed) {
            if (al == st) {flag = true;}
        }
        if (flag) {temp = temp + st;}
    }
    statement = temp;
}

int calculator::toInt(std::string str) {
    int result = 0;
    bool flag = false;
    for (int i = str.length() - 1; i >= 0; i--){
        if (str[i] == '_') {flag = true; continue;}
        result += int(str[i] - '0') * pow (10, str.length() - 1 - i);
    }
    if (flag) {result *= -1;}
    return result;
}

std::string calculator::insert(std::string ins, std::string& str, int first, int second) {
    return strSlice(str, 0, first-1) + ins + strSlice(str, second+1, str.length()-1);
}

std::string calculator::strSlice(const std::string statement, int index1, int index2) {
    if (index1 < 0 || index2 < 0 || index1 >= statement.length() || index2 >= statement.length()) {
        return "";
    }
    std::string result;
    if (index1 > index2) {int temp = index1; index1 = index2; index2 = temp;}
    for (int i = index1; i <= index2; i++){
        result = result + statement[i];
    }
    return result;
}

stringSlice calculator::brackets(std::string str) {
    stringSlice result;
    result.first = result.second = -1;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {result.first = i; break;}
    }
    int brCount = 0;
    int second = result.first;
    while (second < str.length()){
        if (str[second] == '(') {++brCount;}
        else if (str[second] == ')') {--brCount;}
        if (brCount <= 0) { break;}
        ++second;
    }
    result.second = second;
    result.str = calculator::strSlice(str, result.first+1, result.second-1);
    return result;
}

afterOper calculator::operation(int signIndex, const std::string str) {
    afterOper res;
    std::string rightNum = "";
    std::string leftNum = "";
    int index = signIndex + 1;
    while ((int(str[index] - '0') >= 0 && int(str[index] - '0') <= 9)|| str[index] == '_' ){
        if (str[index] == '_')
        {
            rightNum = '_' + rightNum;
            index++;
            if (index >= str.length()) {break;}
        } else {
            rightNum = rightNum + str[index];
            index++;
            if (index >= str.length()) {break;}
        }
    }
    res.second = index - 1;
    index = signIndex - 1;
    while ((int(str[index] - '0') >= 0 && int(str[index] - '0') <= 9) || str[index] == '_'){
            leftNum = str[index] + leftNum;
            index--;
            if (index < 0) {break;}

    }
    res.first = index + 1;
    int left = toInt(leftNum); int right = toInt(rightNum);
    switch (str[signIndex]) {
        case '-':
            res.result = left - right;
            break;
        case '*':
            res.result = left * right;
            break;
        case '/':
            res.result = left / right;
            break;
        case '^':
            res.result = pow(left, right);
            break;
        case '+':
            res.result = left + right;
            break;
        default:
            res.result = 0;
            break;
    }
    return res;
}

std::string calculator::toStr(int num){
    std::string result = ""; bool neg = false;
    if (num < 0) {neg = true; num *= -1;}
    while (num > 0) {
        result = char(num%10 + '0') + result;
        num /= 10;
    }
    if (neg) {result = '_' + result;}
    return result;
}

int calculator::eval(std::string statement) {
    spaces(statement); if (statement[0] == '-') {statement[0] = '_';}
    while (true) {
        stringSlice ss = brackets(statement);
        if (ss.first == -1 || ss.second == -1) {break;}
        statement = insert(toStr(eval(ss.str)), statement, ss.first, ss.second);
    }
    //here we are confident that statement doesn't contain brackets
    //check for power ^ operator
    bool powerFlag = true;
    while (powerFlag) {
        powerFlag = false; int index = 0;
        for (int i = 0; i < statement.length(); ++i){
            if (statement[i] == '^') {powerFlag = true; index = i; break;}
        }
        if (powerFlag) {
            afterOper ao = operation(index, statement);
            statement = insert(toStr(ao.result), statement, ao.first, ao.second);
        }
    }

    //check for * or / operator
    bool multDivFlag = true;
    while (multDivFlag) {
        multDivFlag = false; int index = 0;
        for (int i  = 0; i < statement.length(); ++i) {
            if (statement[i] == '*' || statement[i] == '/') {
                multDivFlag = true;
                index = i;
                break;
            }
        }
        if (multDivFlag) {
            afterOper ao = operation(index, statement);
            statement = insert(toStr(ao.result), statement, ao.first, ao.second);
        }
    }

    //check for + or - operator
    bool sumFlag = true;
    while (sumFlag) {
        sumFlag = false; int index = 0;
        for (int i  = 0; i < statement.length(); ++i) {
            if (statement[i] == '+' || statement[i] == '-') {
                sumFlag = true;
                index = i;
                break;
            }
        }
        if (sumFlag) {
            afterOper ao = operation(index, statement);
            statement = insert(toStr(ao.result), statement, ao.first, ao.second);
        }
    }
    return toInt(statement);
}