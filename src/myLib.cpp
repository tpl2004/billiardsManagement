#include "../include/myLib.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

bool checkID(const std::string &id) {
    for(const char &c : id) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) continue;
        return false;
    }
    return true;
}

bool checkFullName(const std::string &fullName) {
    for(const char &c : fullName) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') continue;
        return false;
    }
    return true;
}

std::string standardize(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::stringstream ss(str);
    std::string tmp;
    std::vector<std::string> v;
    std::string newStr = "";
    while(ss >> tmp) {
        tmp[0] = std::toupper(tmp[0]);
        v.push_back(tmp);
    }
    for(int i = 0; i < int(v.size()) - 1; i++) {
        newStr += v[i] + " ";
    }
    return newStr + v[int(v.size()) - 1];
}