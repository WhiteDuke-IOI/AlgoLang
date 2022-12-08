#include "Source.h"

int main() {
    unordered_map <int, pipe> mp_pipe;
    unordered_map <int, CS> mp_cs;
    vector <connect> connects;

    do {
        print_menu();
        int cursor = Get_Num(0, 16);

        switch (cursor) {
        case 1: { //Добавление трубы
            system("cls");
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
            system("cls");
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
            system("cls");
            cout << left << "All objects\n";
            show_pipe(mp_pipe);
            cout << endl;
            show_cs(mp_cs);
            system("pause");
            break;
        }

        case 8: { //Сохранение в файл
            save(mp_pipe, mp_cs, connects);
            break;
        }

        case 9: { //Загрузка из файла
            upload(mp_pipe, mp_cs, connects);
            break;
        }

        case 10: { //Поиск трубы по имени
            filtration_pipe_by_name(mp_pipe);
            break;
        }

        case 11: { //Поиск трубы по ремонту
            filtration_pipe_by_repair(mp_pipe);
            break;
        }

        case 12: { //Поиск КС по имени
            filtration_cs_by_name(mp_cs);
            break;
        }

        case 13: { //Поиск КС по проценту незадействованных цехов
            filtration_cs_by_act_ws(mp_cs);
            break;
        }

        case 14: {
            create_new_connection(connects, mp_pipe, mp_cs);
            break;
        }
        case 15: {
            show_all_connection(connects, mp_pipe, mp_cs);
            break;
        }
        case 16: {
            topology_sort(connects, mp_pipe, mp_cs);
            break;
        }

        case 0: { //Выход
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}