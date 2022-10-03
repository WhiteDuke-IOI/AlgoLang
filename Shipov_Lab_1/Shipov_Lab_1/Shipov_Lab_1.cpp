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

int Get_Int(int b)
{
    int n;
    cin >> n;
    while ((cin.fail()) || (n < 0) || (n > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> n;
    }
    return n;
}

float Get_Float(float b)
{
    float n;
    cin >> n;
    while ((cin.fail()) || (n < 0) || (n > b) || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Введите корректное число: ";
        cin >> n;
    }
    return n;
}

pipe AddPipe()
{
    pipe Obj;
    system("cls");
    cout << "Добавление трубы\n";
    cout << "Имя: ";
    //cin >> Obj.name;
    getline(cin, Obj.name);
    cout << "Длинна (км): ";
    //cin >> Obj.lenght;
    Obj.lenght = Get_Int(1000000);
    while (Obj.lenght <= 0) {
        cout << "Длинна должна быть больше 0!" << endl;
        Obj.lenght = Get_Int(1000000);
    }
    cout << "Диаметр (см): ";
    //cin >> Obj.diametr;
    Obj.diametr = Get_Int(1000000);
    while (Obj.diametr <= 0) {
        cout << "Диаметр должен быть больше 0!" << endl;
        Obj.diametr = Get_Int(1000000);
    }
    cout << "Ремонт (0 - Нет или 1 - Да): ";
    //cin >> Obj.repair;
    Obj.repair = Get_Int(1);
    return Obj;
}

CS AddCS()
{
    CS Obj;
    system("cls");
    cout << "Добавление КС\n";
    cout << "Имя: ";
    //cin >> Obj.name;
    getline(cin, Obj.name);
    cout << "Кол-во цехов: ";
    //cin >> Obj.countWS;
    Obj.countWS = Get_Int(1000000);
    while (Obj.countWS <= 0) {
        cout << "Кол-во цехов должно быть больше 0!" << endl;
        Obj.countWS = Get_Int(1000000);
    }
    cout << "Кол-во цехов в работе: ";
    //cin >> Obj.actWS;
    Obj.actWS = Get_Int(1000000);
    while (Obj.countWS < Obj.actWS) {
        cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
        Obj.actWS = Get_Int(1000000);
    }
    cout << "Эффективность (От 0 до 1): ";
    //cin >> Obj.eff;
    Obj.eff = Get_Float(1);
    return Obj;
}

void ShowPipe(const pipe& Obj)
{
    cout << "Имя\t" << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
    cout << "================================================" << endl;
    cout << Obj.name << '\t' << Obj.lenght << '\t' << Obj.diametr << '\t' << Obj.repair << endl;
}

void ShowCS(const CS& Obj)
{
    cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
    cout << "===========================================================================" << endl;
    cout << Obj.name << '\t' << Obj.countWS << '\t' << Obj.actWS << '\t' << Obj.eff << endl;
}

void EditPipe(pipe& Obj)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Длинна\n" << "3. Диаметр\n" << "4. Ремонт\n" << "0. Выход\n" << ">";
    int cursor = Get_Int(4);
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        //cin >> Obj.name;
        getline(cin, Obj.name);
        break;
    case 2:
        cout << "Текущая длинна: " << Obj.lenght << "\n";
        cout << "Новая длинна (км): ";
        //cin >> Obj.lenght;
        Obj.lenght = Get_Int(1000000);
        while (Obj.lenght <= 0) {
            cout << "Длинна должна быть больше 0!" << endl;
            Obj.lenght = Get_Int(1000000);
        }
        break;
    case 3:
        cout << "Текущий диаметр: " << Obj.diametr << "\n";
        cout << "Новый диаметр (см): ";
        //cin >> Obj.diametr;
        Obj.diametr = Get_Int(1000000);
        while (Obj.diametr <= 0) {
            cout << "Диаметр должен быть больше 0!" << endl;
            Obj.diametr = Get_Int(1000000);
        }
        break;
    case 4:
        cout << "Текущий Ремонт: " << Obj.repair << "\n";
        cout << "Ремонт (0 - Нет или 1 - Да): ";
        //cin >> Obj.repair;
        Obj.repair = Get_Int(1);
        break;
    case 0:
        break;
    }
}

void EditCS(CS& Obj)
{
    system("cls");
    cout << "Что редактируем?\n" << "1. Имя\n" << "2. Кол-во цехов\n" << "3. Кол-во цехов в работе\n" << "4. Эффективность\n" << "0. Выход\n" << ">";
    int cursor = Get_Int(4);
    switch (cursor) {
    case 1:
        cout << "Текущее имя: " << Obj.name << "\n";
        cout << "Новое имя: ";
        //cin >> Obj.name;
        getline(cin, Obj.name);
        break;
    case 2:
        cout << "Текущее кол-во цехов: " << Obj.countWS << "\n";
        cout << "Новое кол-во цехов: ";
        //cin >> Obj.countWS;
        Obj.countWS = Get_Int(1000000);
        while (Obj.countWS <= 0) {
            cout << "Кол-во цехов должно быть больше 0!" << endl;
            Obj.countWS = Get_Int(1000000);
        }
        break;
    case 3:
        cout << "Текущее кол-во цехов в работе: " << Obj.actWS << "\n";
        cout << "Новое кол-во цехов в работе: ";
        //cin >> Obj.actWS;
        Obj.actWS = Get_Int(1000000);
        while (Obj.countWS < Obj.actWS) {
            cout << "Количество цехов в работе должно быть меньше либо равно общему количеству цехов!" << endl;
            Obj.actWS = Get_Int(1000000);
        }
        break;
    case 4:
        cout << "Текущая эффективность: " << Obj.eff << "\n";
        cout << "Новая эффективность (От 0 до 1): ";
        //cin >> Obj.eff;
        Obj.eff = Get_Float(1);
        break;
    case 0:
        break;
    }
}

void Save(const pipe& Obj1, const CS& Obj2)
{
    ofstream fout ("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    fout << Obj1.name << "/" << Obj1.lenght << "/" << Obj1.diametr << "/" << Obj1.repair << endl;
    fout << Obj2.name << "/" << Obj2.countWS << "/" << Obj2.actWS << "/" << Obj2.eff << endl;
    fout.close();
}

void Upload(pipe& Obj1, CS& Obj2)
{
    ifstream fin("C:\\Users\\iship\\OneDrive\\Документы\\GitHub\\CrossPlatform\\Shipov_Lab_1\\mas.txt");
    string buff;
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        getline(fin, Obj1.name, '/');
        getline(fin, buff, '/');
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 1!" << endl;
            return;
        }
        else {
            Obj1.lenght = stoi(buff);
        }
        getline(fin, buff, '/');        
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 2!" << endl;
            return;
        }
        else {
            Obj1.diametr = stoi(buff);
        }
        getline(fin, buff);        
        if ((stoi(buff) < 0) || (stoi(buff) > 1)) {
            cout << "Файл не корректен 3!" << endl;
            return;
        }
        else {
            Obj1.repair = stoi(buff);
        }

        getline(fin, Obj2.name, '/');
        getline(fin, buff, '/');        
        if (stoi(buff) <= 0) {
            cout << "Файл не корректен 4!" << endl;
            return;
        }
        else {
            Obj2.countWS = stoi(buff);
        }
        getline(fin, buff, '/');        
        if (Obj2.countWS < stoi(buff)) {
            cout << "Файл не корректен 5!" << endl;
            return;
        }
        else {
            Obj2.actWS = stoi(buff);
        }
        getline(fin, buff);
        if ((stof(buff) < 0) || (stof(buff) > 1)) {
            cout << "Файл не корректен 6!" << endl;
            return;
        }
        else {
            Obj2.eff = stof(buff);
        }
        
        fin.close(); // закрываем файл  
        return;
    }
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int cursor;

    pipe p = {"0", 0, 0, 0};
    CS CS = { "0", 0, 0, 0 };

    do
    {
        print_menu();
        cursor = Get_Int(7);

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
            //cout << "Действие: " << cursor << "\n";   
            system("cls");
            cout << "Просмотр всех объектов\n\n";
            ShowPipe(p);
            cout << "\n";
            ShowCS(CS);
            break;
        }

        case 4: 
        {
            //cout << "Действие: " << cursor << "\n";            
            EditPipe(p);
            break;
        }

        case 5: 
        {
            //cout << "Действие: " << cursor << "\n";            
            EditCS(CS);
            break;
        }

        case 6: 
        {
            //cout << "Действие: " << cursor << "\n";
            Save(p, CS);
            break;
        }

        case 7: 
        {
            //cout << "Действие: " << cursor << "\n";
            Upload(p, CS);
            break;
        }
        }
        if (cursor != 0) system("pause");
    } while (cursor != 0);
    return 0;
}