#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>

const int CS_FLAG = 2;

string CS::get_name() const { return(name); }
int CS::get_count_ws() const { return(count_ws); }
int CS::get_act_ws() const { return(act_ws); }
double CS::get_eff() const { return(eff); }

ostream& operator<<(ostream& os, const CS& stat)
{
    return os << stat.get_name() << '\t' << stat.get_count_ws() << '\t' << stat.get_act_ws() << '\t' << stat.get_eff() << endl;
}

ofstream& operator<<(ofstream& ofs, const CS& stat)
{
    ofs << CS_FLAG << endl << stat.get_name() << endl << stat.get_act_ws() << endl << stat.get_count_ws()
        << endl << stat.get_eff() << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, CS& stat)
{
    getline(ifs, stat.name);
    ifs >> stat.act_ws;
    ifs >> stat.count_ws;
    ifs >> stat.eff;
    return ifs;
};

void CS::add_CS() // Добавление КС
{
    system("cls");
    cout << "Add CS\n";
    cout << "Enter the CS's name: ";
    getline(cin, name);
    cout << "Enter number of all worckshop: ";
    count_ws = Get_Int(1, 1000000);
    cout << "Enter number of active worckshop: ";
    act_ws = Get_Int(0, count_ws);
    cout << "Enter the CS's efficiency: ";
    eff = Get_Float(0, 1);
}

void CS::set_act_ws() // Редактирование КС
{
    system("cls");
    cout << "Edit CS\n";
    cout << "Old number active workshops: " << act_ws << endl;
    cout << "Enter new number of active worckshop: ";
    act_ws = Get_Int(0, count_ws);
}