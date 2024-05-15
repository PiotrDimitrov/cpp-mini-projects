#include "calculator.h"
#include <bits/stdc++.h>

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
    for (int i = index1; i < index2; i++){
        result = result + statement[i];
    }
    return result;
}