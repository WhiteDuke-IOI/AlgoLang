#include "CS.h"

const int CS_FLAG = 2;

int CS::max_cs_id = 1;

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

string CS::get_name() const { return(this->name); }
int CS::get_count_ws() const { return(this->count_ws); }
int CS::get_act_ws() const { return(this->act_ws); }
double CS::get_eff() const { return(this->eff); }
int CS::get_id() const { return(this->id); }

ostream& operator<<(ostream& os, const CS& stat) {
    return os << "|" << setw(4) << stat.id << "|" << setw(16) << stat.name << "|" << setw(16) << stat.count_ws << "|" << setw(16) << stat.act_ws
        << "|" << setw(10) << stat.eff << "|" << endl;
} 

istream& operator>>(istream& is, CS& stat) {
    system("cls");
    cout << "Add CS\n";
    cout << "Enter the CS's name: ";
    getline(cin, stat.name);
    cout << "Enter number of all worckshop: ";
    stat.count_ws = Get_Num(1, 1000000);
    cout << "Enter number of active worckshop: ";
    stat.act_ws = Get_Num(0, stat.count_ws);
    cout << "Enter the CS's efficiency: ";
    stat.eff = Get_Num(0.0, 1.0);
    return is;
};

ofstream& operator<<(ofstream& ofs, const CS& stat) {
    ofs << CS_FLAG << endl << stat.id << endl << stat.name << endl << stat.act_ws << endl << stat.count_ws
        << endl << stat.eff << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, CS& stat) {
    ifs >> stat.id;
    getline(ifs, stat.name);
    getline(ifs, stat.name);
    ifs >> stat.act_ws;
    ifs >> stat.count_ws;
    ifs >> stat.eff;
    return ifs;
};

void CS::set_act_ws() { // Редактирование КС      
    cout << "Old number active workshops: " << this->act_ws << endl;
    cout << "Enter new number of active worckshop: ";
    this->act_ws = Get_Num(0, this->count_ws);
}

//void CS::set_cs_id(int cs_id) {
//    id = cs_id;
//}