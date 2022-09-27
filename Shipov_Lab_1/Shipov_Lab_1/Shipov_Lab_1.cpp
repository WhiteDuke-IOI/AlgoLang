#include <iostream>
#include <string>
using namespace std;

struct pipe
{
    string name;
    int lenght;
    int diametr;
    bool repair;
};

struct CS
{
    string name;
    int countWS;
    int actWS;
    float eff;
};

void print_menu()
{
    system("cls");
    cout << "1. Добавить трубу\n";
    cout << "2. Добавить КС\n";
    cout << "3. Просмотр всех объектов\n";
    cout << "4. Редактировать трубу\n";
    cout << "5. Редактировать КС\n";
    cout << "6. Сохранить\n";
    cout << "7. Загрузить\n";
    cout << "0. Выход\n";
    cout << "\nВыберите действие - ";
}

int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 0 || variant > count) 
    {
        cout << "Некорректный ввод. Попробуйте снова: ";
        getline(cin, s);
    }
    return variant;
}

pipe AddPipe()
{
    pipe Obj;
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Имя: ";
    cin >> Obj.name;
    cout << "Длинна (м): ";
    cin >> Obj.lenght;
    cout << "Диаметр (мм): ";
    cin >> Obj.diametr;
    cout << "Ремонт (0 или 1): ";
    cin >> Obj.repair;
    return Obj;
}

CS AddCS()
{
    CS Obj;
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
    cin >> Obj.name;
    cout << "Кол-во цехов: ";
    cin >> Obj.countWS;
    cout << "Кол-во цехов в работе: ";
    cin >> Obj.actWS;
    cout << "Эффективность: ";
    cin >> Obj.eff;
    return Obj;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int cursor;

    pipe p;
    CS CS;

    do
    {
        print_menu();
        cursor = get_variant(7);

        switch (cursor) {
        case 1: 
        {
            //cout << "Действие: " << cursor << "\n";  
            p = AddPipe();
            break;
        }

        case 2: 
        {
            //cout << "Действие: " << cursor << "\n"; 
            CS = AddCS();
            break;
        }

        case 3: 
        {
            cout << "Действие: " << cursor << "\n";            
            break;
        }

        case 4: 
        {
            cout << "Действие: " << cursor << "\n";            
            break;
        }

        case 5: 
        {
            cout << "Действие: " << cursor << "\n";            
            break;
        }

        case 6: 
        {
            cout << "Действие: " << cursor << "\n";
            break;
        }

        case 7: 
        {
            cout << "Действие: " << cursor << "\n";
            break;
        }
        }
        if (cursor != 0) system("pause");
    } while (cursor != 0);
    return 0;
}