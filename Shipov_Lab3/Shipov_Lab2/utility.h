#pragma once
#include "pipe.h"
#include "CS.h"
#include <iostream>

template<typename T>
T Get_Num(T a, T b) {
    T n;
    while (!(cin >> n) || (n < a) || (n > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Enter correct number: ";
    }
    return n;
}

struct connect {
    int initial_cs_id = 0;
    int terminal_cs_id = 0;
    pipe& pipe_id = *(new pipe());
};