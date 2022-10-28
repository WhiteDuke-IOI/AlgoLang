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

using pipe_func = void(*)(unordered_map <int, pipe>& p, int id);
void edit_pipe(unordered_map <int, pipe>& mp, int id);
void delete_pipe(unordered_map <int, pipe>& mp, int id);
void action_over_pipe(unordered_map <int, pipe>& mp, pipe_func func);

void add_CS_object(unordered_map <int, CS>& mp);

using CS_func = void(*)(unordered_map <int, CS>& p, int id);
void edit_cs(unordered_map <int, CS>& mp, int id);
void delete_cs(unordered_map <int, CS>& mp, int id);
void action_over_cs(unordered_map <int, CS>& mp, CS_func func);

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
        case 1: { //Добавление трубы
            add_pipe_object(mp_pipe);
            break;
        }

        case 2: { //Редактирование трубы
            action_over_pipe(mp_pipe, edit_pipe);
            break;
        }

        case 3: { //Удаление трубы
            action_over_pipe(mp_pipe, delete_pipe);
            break;
        }

        case 4: { //Добавление КС
            add_CS_object(mp_cs);
            break;
        }

        case 5: { //Редактирование КС
            action_over_cs(mp_cs, edit_cs);
            break;
        }

        case 6: { //Удаление КС
            action_over_cs(mp_cs, delete_cs);
            break;
        }

        case 7: { //Просмотр всех объектов
            show_all_object(mp_pipe, mp_cs);
            break;
        }

        case 8: { //Сохранение в файл
            save(mp_pipe, mp_cs);
            break;
        }

        case 9: { //Загрузка из файла
            upload(mp_pipe, mp_cs);
            break;
        }

        case 0: { //Выход
            system("pause");
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}