#include "calculator.h"
#include <bits/stdc++.h>

calculator::calculator(std::string str) {
    statement = str;
}

void calculator::spaces() {
    std::string temp;
    for (int i = 0; i < statement.length(); i++){
        if (statement[i] != ' ') {temp = temp + statement[i];}
    }
    statement = temp;
}

void calculator::spaces(std::string& statement) {
    std::string temp;
    for (int i = 0; i < statement.length(); i++){
        if (statement[i] != ' ') {temp = temp + statement[i];}
    }
    statement = temp;
}

void calculator::refactor() {
    std::string allowed = "1234567890-+/^:*()%";
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

void calculator::refactor(std::string& statement) {
    std::string allowed = "1234567890-+/^:*()%";
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
    for (int i = str.length() - 1; i >= 0; i--){
        result += int(str[i] - '0') * pow (10, str.length() - 1 - i);
    }
    return result;
}

std::string calculator::strSlice(int index1, int index2) {
    if (index1 < 0 || index2 < 0 || index1 >= statement.length() || index2 >= statement.length()) {
        return "";
    }
    std::string result;
    if (index1 > index2) {int temp = index1; index1 = index2; index2 = temp;}
    for (int i = index1; i < index2; i++){
        result = result + statement[i];
    }
    return result;
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

int calculator::rightBracket(int index) {
    //index - is index of first '(' bracket
    int brCount = 0; //bracket counter
    int i = index;
    while (i < statement.length()){
        if (statement[i] == '(') {++brCount;}
        else if (statement[i] == ')') {--brCount;}
        if (brCount <= 0) { break;}
        ++i;
    }
    return i;
}

int calculator::leftBracket(std::string str){
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '(') {return i;}
    }
    return -1;
}

int calculator::rightBracket(std::string str) {

}

std::string calculator::brStat(std::string str) {
    int first = -1;
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '(') {first = i; break;}
    }
    if (first < 0) {return "";}
    int brCount = 0;
    int second = first;
    while (second < str.length()){
        if (str[second] == '(') {++brCount;}
        else if (str[second] == ')') {--brCount;}
        if (brCount <= 0) { break;}
        ++second;
    }
    return calculator::strSlice(str, first, second);
}

std::string calculator::noBrStat(std::string str) {
    int first = -1;
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '(') {first = i; break;}
    }
    if (first < 0) {return "";}
    int brCount = 0;
    int second = first;
    while (second < str.length()){
        if (str[second] == '(') {++brCount;}
        else if (str[second] == ')') {--brCount;}
        if (brCount <= 0) { break;}
        ++second;
    }
    return calculator::strSlice(str, first+1, second-1);
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