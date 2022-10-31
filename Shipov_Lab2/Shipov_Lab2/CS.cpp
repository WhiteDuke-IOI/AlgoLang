#include "CS.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int CS_FLAG = 2;

int Get_Int(const int a, const int b);
float Get_Float(const float a, const float b);

string CS::get_name() const { return(name); }
int CS::get_count_ws() const { return(count_ws); }
int CS::get_act_ws() const { return(act_ws); }
double CS::get_eff() const { return(eff); }

ostream& operator<<(ostream& os, const CS& stat) {
    return os << setw(16) << stat.get_name() << "|" << setw(16) << stat.get_count_ws() << "|" << setw(16) << stat.get_act_ws() 
        << "|" << setw(10) << stat.get_eff() << "|" << endl;
} 

istream& operator>>(istream& is, CS& stat) {
    system("cls");
    cout << "Add CS\n";
    cout << "Enter the CS's name: ";
    getline(cin, stat.name);
    cout << "Enter number of all worckshop: ";
    stat.count_ws = Get_Int(1, 1000000);
    cout << "Enter number of active worckshop: ";
    stat.act_ws = Get_Int(0, stat.count_ws);
    cout << "Enter the CS's efficiency: ";
    stat.eff = Get_Float(0, 1);
    return is;
};

ofstream& operator<<(ofstream& ofs, const CS& stat) {
    ofs << CS_FLAG << endl << stat.get_name() << endl << stat.get_act_ws() << endl << stat.get_count_ws()
        << endl << stat.get_eff() << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, CS& stat) {
    getline(ifs, stat.name);
    ifs >> stat.act_ws;
    ifs >> stat.count_ws;
    ifs >> stat.eff;
    return ifs;
};

void CS::set_act_ws() { // Редактирование КС      
    cout << "Old number active workshops: " << act_ws << endl;
    cout << "Enter new number of active worckshop: ";
    act_ws = Get_Int(0, count_ws);
}