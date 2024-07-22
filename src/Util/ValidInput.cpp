#include <ValidInput.h>

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

bool isValidInteger(string &input, int &value) {
    getline(cin, input);
    value = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] > '9' || input[i] < '0') return false;
        value = value * 10 + (int)(input[i] - '0');
    }
    return true;
}

bool isValidMove(string s) {
    if (s.size() != 3) return false;
    if (s[0] < '0' || s[0] > '9') return false;
    if (s[1] != ' ') return false;
    if (s[2] < '0' || s[2] > '9') return false;
    return true;
}

int getNum(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 10 + (int)s[i] - 48;
    return res;
}