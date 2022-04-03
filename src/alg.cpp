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
std::string yep;
    char probel = ' ';
    for (int i = 0; i < inf.size(); i++) {
        if (Imp(inf[i]) == 4) {
            yep.push_back(inf[i]);
            yep.push_back(probel);
        }
        else {
            if (Imp(inf[i]) == 0) {
                stackA.push(inf[i]);
            }
            else if (stackA.isEmpty()) {
                stackA.push(inf[i]);
            }
            else if ((Imp(inf[i]) > Imp(stackA.get()))) {
                stackA.push(inf[i]);
            }
            else if (Imp(inf[i]) == 1) {
                while (Imp(stackA.get()) != 0) {
                    yep.push_back(stackA.get());
                    yep.push_back(probel);
                    stackA.pop();
                }
                stackA.pop();
            }
            else {
                while (!stackA.isEmpty()
                    && (Imp(inf[i]) <= Imp(stackA.get()))) {
                    yep.push_back(stackA.get());
                    yep.push_back(probel);
                    stackA.pop();
                }
                stackA.push(inf[i]);
            }
        }
    }
    while (!stackA.isEmpty()) {
        yep.push_back(stackA.get());
        yep.push_back(probel);
        stackA.pop();
    }
    for (int i = 0; i < yep.size(); i++) {
        if (yep[yep.size() - 1] == ' ')
            yep.erase(yep.size() - 1);
    }
    return yep;
}

int eval(std::string pref) {
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
