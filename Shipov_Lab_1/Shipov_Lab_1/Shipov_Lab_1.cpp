#include <iostream>
#include <string>
#include <fstream>

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
    std::cout << "1. Добавить трубу\n";
    std::cout << "2. Добавить КС\n";
    std::cout << "3. Просмотр всех объектов\n";
    std::cout << "4. Редактировать трубу\n";
    std::cout << "5. Редактировать КС\n";
    std::cout << "6. Сохранить\n";
    std::cout << "7. Загрузить\n";
    std::cout << "0. Выход\n";
    std::cout << "\nВыберите действие - ";
}

int Get_Int(int b) {
    int n;
    std::cin >> n;
    while ((cin.fail()) || (n < 0) || (n > b) || (cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Введите корректное число: ";
        std::cin >> n;
    }
    return n;
}

float Get_Float(float b) {
    float n;
    std::cin >> n;
    while ((std::cin.fail()) || (n < 0) || (n > b) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Введите корректное число: ";
        std::cin >> n;
    }
    return n;
}

pipe AddPipe() {
    pipe Obj;
    system("cls");
    std::cout << "Добавление трубы\n";
    std::cout << "Имя: ";
    std::getline(cin, Obj.name);
    std::cout << "Длинна (км): ";
    Obj.lenght = Get_Int(1000000);
    while (Obj.lenght <= 0) {
        std::cout << "Длинна должна быть больше 0!" << endl;
        Obj.lenght = Get_Int(1000000);
    }
    std::cout << "Диаметр (см): ";
    Obj.diametr = Get_Int(1000000);
    while (Obj.diametr <= 0) {
        std::cout << "Диаметр должен быть больше 0!" << endl;
        Obj.diametr = Get_Int(1000000);
    }
    std::cout << "Ремонт (0 - Нет или 1 - Да): ";
    Obj.repair = Get_Int(1);
    return Obj;
}

CS AddCS() {
    CS Obj;
    system("cls");
    std::cout << "Добавление КС\n";
    std::cout << "Имя: ";
    std::getline(cin, Obj.name);
    std::cout << "Кол-во цехов: ";
    Obj.countWS = Get_Int(1000000);
    while (Obj.countWS <= 0) {
        std::cout << "Кол-во цехов должно быть больше 0!" << endl;
        Obj.countWS = Get_Int(1000000);
    }
    std::cout << "Кол-во цехов в работе: ";
    Obj.actWS = Get_Int(1000000);
    while (Obj.countWS < Obj.actWS) {
        std::cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
        Obj.actWS = Get_Int(1000000);
    }
    std::cout << "Эффективность (От 0 до 1): ";
    Obj.eff = Get_Float(1);
    return Obj;
}

void ShowPipe(const pipe& Obj) {
    std::cout << "Имя\t" << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
    std::cout << "================================================" << endl;
    std::cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;
}

void ShowCS(const CS& Obj) {
    std::cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
    std::cout << "===========================================================================" << endl;
    std::cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

void EditPipe(pipe& Obj) {
    int cursor = 0;
    do {
        system("cls");
        std::cout << "1. Редактировать имя\n" << "2. Редактировать длинну\n" << "3. Редактировать диаметр\n" << "4. Редактировать ремонт\n" 
            << "0. Выход\n" << "Выберите действие - ";
        cursor = Get_Int(4);
        switch (cursor) {
        case 1:
            std::cout << "Текущее имя: " << Obj.name << "\n";
            std::cout << "Новое имя: ";
            std::getline(cin, Obj.name);
            break;
        case 2:
            std::cout << "Текущая длинна: " << Obj.lenght << "\n";
            std::cout << "Новая длинна (км): ";
            Obj.lenght = Get_Int(1000000);
            while (Obj.lenght <= 0) {
                std::cout << "Длинна должна быть больше 0!" << endl;
                Obj.lenght = Get_Int(1000000);
            }
            break;
        case 3:
            std::cout << "Текущий диаметр: " << Obj.diametr << "\n";
            std::cout << "Новый диаметр (см): ";
            Obj.diametr = Get_Int(1000000);
            while (Obj.diametr <= 0) {
                std::cout << "Диаметр должен быть больше 0!" << endl;
                Obj.diametr = Get_Int(1000000);
            }
            break;
        case 4:
            std::cout << "Текущий Ремонт: " << Obj.repair << "\n";
            std::cout << "Ремонт (0 - Нет или 1 - Да): ";
            Obj.repair = Get_Int(1);
            break;
        case 0:
            break;
        }
    } while (cursor != 0);
}

void EditCS(CS& Obj) {
    int cursor = 0;
    do {
        system("cls");
        std::cout << "1. Редактировать имя\n" << "2. Редактировать кол-во цехов\n" << "3. Редактировать кол-во цехов в работе\n" 
            << "4. Редактировать эффективность\n" << "0. Выход\n" << "Выберите действие - ";
        cursor = Get_Int(4);
        switch (cursor) {
        case 1:
            std::cout << "Текущее имя: " << Obj.name << "\n";
            std::cout << "Новое имя: ";
            std::getline(cin, Obj.name);
            break;
        case 2:
            std::cout << "Текущее кол-во цехов: " << Obj.countWS << "\n";
            std::cout << "Новое кол-во цехов: ";
            Obj.countWS = Get_Int(1000000);
            while (Obj.countWS <= 0) {
                std::cout << "Кол-во цехов должно быть больше 0!" << endl;
                Obj.countWS = Get_Int(1000000);
            }
            break;
        case 3:
            std::cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
            std::cout << "Новое кол-во цехов в работе: ";
            Obj.actWS = Get_Int(1000000);
            while (Obj.countWS < Obj.actWS) {
                std::cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
                Obj.actWS = Get_Int(1000000);
            }
            break;
        case 4:
            std::cout << "Текущая эффективность: " << Obj.eff << "\n";
            std::cout << "Новая эффективность (От 0 до 1): ";
            Obj.eff = Get_Float(1);
            break;
        case 0:
            break;
        }
    } while (cursor != 0);
}

void Save(const pipe& Obj1, const CS& Obj2) {
    ofstream fout ("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    fout << Obj1.name << "/" << Obj1.lenght << "/" << Obj1.diametr << "/" << Obj1.repair << endl;
    fout << Obj2.name << "/" << Obj2.countWS << "/" << Obj2.actWS << "/" << Obj2.eff << endl;
    fout.close();
}

void Upload(pipe& Obj1, CS& Obj2) {
    ifstream fin("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    string buff;
    if (!fin.is_open()) // если файл не открыт
        std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else {
        std::getline(fin, Obj1.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 1!" << endl;
            return;
        }
        else {
            Obj1.lenght = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 2!" << endl;
            return;
        }
        else {
            Obj1.diametr = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stoi(buff) < 0) || (stoi(buff) > 1)) {
            std::cout << "Файл не корректен 3!" << endl;
            return;
        }
        else {
            Obj1.repair = stoi(buff);
        }

        std::getline(fin, Obj2.name, '/');
        std::getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            std::cout << "Файл не корректен 4!" << endl;
            return;
        }
        else {
            Obj2.countWS = stoi(buff);
        }
        std::getline(fin, buff, '/');
        if (Obj2.countWS < stoi(buff)) {
            std::cout << "Файл не корректен 5!" << endl;
            return;
        }
        else {
            Obj2.actWS = stoi(buff);
        }
        std::getline(fin, buff);
        if ((stof(buff) < 0) || (stof(buff) > 1)) {
            std::cout << "Файл не корректен 6!" << endl;
            return;
        }
        else {
            Obj2.eff = stof(buff);
        }
        
        fin.close(); // закрываем файл  
        return;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int cursor;

    pipe p = {"0", 0, 0, 0};
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        cursor = Get_Int(7);

        switch (cursor) {
        case 1: {  
            p = AddPipe();
            break;
        }

        case 2: { 
            CS = AddCS();
            break;
        }

        case 3: {
            system("cls");
            std::cout << "Просмотр всех объектов\n\n";
            ShowPipe(p);
            std::cout << "\n";
            ShowCS(CS);
            break;
        }

        case 4: {            
            EditPipe(p);
            break;
        }

        case 5: {          
            EditCS(CS);
            break;
        }

        case 6: {
            Save(p, CS);
            break;
        }

        case 7: {
            Upload(p, CS);
            break;
        }
        }
        if (cursor != 0) system("pause");
    } while (cursor != 0);
    return 0;
}