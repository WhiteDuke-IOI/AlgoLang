#include "Header.h"

using namespace std;

int main() {
    unordered_map <int, pipe> mp_pipe;
    unordered_map <int, CS> mp_cs;
    do {
        print_menu();
        int cursor = Get_Int(0, 13);

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

        case 0: { //Выход
            return 0;
            break;
        }
        }
    } while (true);
    return 0;
}