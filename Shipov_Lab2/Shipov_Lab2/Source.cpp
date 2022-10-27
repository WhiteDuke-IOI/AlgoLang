#include "pipe.h"
#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int Get_Int(const int a, const int b);
float Get_Float(const float a, const float b);

void print_menu();

void add_pipe_object(unordered_map <int, pipe>& mp);
void add_CS_object(unordered_map <int, CS>& mp);

void show_all_object(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs);

void save(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs);
void upload(unordered_map <int, pipe>& mp_pipe, unordered_map <int, CS>& mp_cs);

int main() {
    unordered_map <int, pipe> mp_pipe;
    unordered_map <int, CS> mp_cs;
    do {
        print_menu();
        int cursor = Get_Int(0, 9);

        switch (cursor) {
        case 1: {
            add_pipe_object(mp_pipe);
            break;
        }

        case 2: {
            //
            break;
        }

        case 3: {
            //
            break;
        }

        case 4: {
            add_CS_object(mp_cs);
            break;
        }

        case 5: {
            //
            break;
        }

        case 6: {
            //
            break;
        }

        case 7: {
            show_all_object(mp_pipe, mp_cs);
            break;
        }

        case 8: {
            save(mp_pipe, mp_cs);
            break;
        }

        case 9: {
            upload(mp_pipe, mp_cs);
            break;
        }

        case 0: {
            system("pause");
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}