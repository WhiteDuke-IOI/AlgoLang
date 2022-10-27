#include "pipe.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int PIPE_FLAG = 1;

int Get_Int(const int a, const int b);
float Get_Float(const float a, const float b);

string pipe::get_name() const { return(name); }
int pipe::get_lenght() const { return(lenght); }
double pipe::get_diameter() const { return(diameter); }
bool pipe::get_repair() const { return(repair); }

ostream& operator<<(ostream& os, const pipe& p) {
    return os << setw(16) << p.get_name() << "|" << setw(16) << p.get_lenght() << "|" << setw(16) << p.get_diameter() 
        << "|" << setw(6) << p.get_repair() << "|" << endl;
}

istream& operator>>(istream& is, pipe& p) {
    system("cls");
    cout << "Add pipe\n";
    cout << "Enter the pipeline's name: ";
    getline(cin, p.name);
    cout << "Enter pipeline's length (km): ";
    p.lenght = Get_Int(1, 1000000);
    cout << "Enter pipeline's diameter (cm): ";
    p.diameter = Get_Int(1, 1000000);
    cout << "Enter pipeline's status (0 - on, 1 - off): ";
    p.repair = Get_Int(0, 1);
    return is;
};

ofstream& operator<<(ofstream& ofs, const pipe& p) {
    ofs << PIPE_FLAG << endl << p.get_name() << endl << p.get_lenght() << endl << p.get_diameter() << endl << p.get_repair()
        << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, pipe& p) {
    getline(ifs, p.name);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};

void pipe::set_repair() { // Редактирование трубы
    system("cls");
    cout << "Edit pipe\n";
    cout << "Old repair status: " << repair << endl;;
    cout << " Enter the new repair status: ";
    repair = Get_Int(0, 1);
}