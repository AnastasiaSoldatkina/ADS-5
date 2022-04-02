// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int Imp(char w) {
    switch (w) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default: return 10;
    }
}
int calcul(char w, int x, int y) {
    switch (w) {
    case '*': return x * y;
    case '/': return x / y;
    case '-': return x - y;
    case '+': return x + y;
    default: return 10;
    }
}
std::string infx2pstfx(std::string inf) {
std::string str;
    TStack <char, 100> stackA;
    int i = 0;
    while (i <= inf.length()) {
        if (Imp(inf[i]) == 0 && (Imp(inf[i]) != 1) && Imp(inf[i]) != 10) {
            stackA.push(inf[i]);
        } else if (Imp(inf[i]) > Imp(stackA.get()) && (Imp(inf[i]) != 1) && Imp(inf[i]) != 10) {
            stackA.push(inf[i]);
        } else if (stackA.isEmpty() && (Imp(inf[i]) != 1) && Imp(inf[i]) != 10) {
            stackA.push(inf[i]);
        } else if (Imp(inf[i]) == 10) {
                str.push_back(inf[i]);
                str.push_back(' ');
        } else if (Imp(inf[i]) <= Imp(stackA.get()) && Imp(inf[i]) != 10 && Imp(inf[i]) != 1) {
            while (Imp(inf[i]) <= Imp(stackA.get()) && !stackA.isEmpty() && Imp(stackA.get()) !=0) {
                str.push_back(stackA.get());
                stackA.pop();
                str.push_back(' ');
            }
            stackA.push(inf[i]);
        } else if (Imp(inf[i]) == 1) {
            while (Imp(stackA.get()) != 0) {
                str.push_back(stackA.get());
                str.push_back(' ');
                stackA.pop();
            }
            stackA.pop();
        }
        i++;
    } while (!stackA.isEmpty()) {
        str.push_back(stackA.get());
        str.push_back(' ');
        stackA.pop();
    }
    return str;
}

int eval(std::string pref) {
TStack <char, 100> stackB;
    int j = 0;
    int x, y = 0;
    int Res = 0;
    while (j < pref.length()) {
        if (Imp(pref[j]) == 10) {
            if (pref[j] != ' ') {
                stackB.push(pref[j] - '0');
            }
        } else if (Imp(pref[j]) < 4) {
            x = stackB.get();
            stackB.pop();
            y = stackB.get();
            stackB.pop();
            stackB.push(calcul(pref[j], y, x));
        }
        j++;
    }
    Res = stackB.get();
    return Res;
}
