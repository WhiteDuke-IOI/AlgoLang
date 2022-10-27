#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string pipe::get_name() const { return(name); }
int pipe::get_lenght() const { return(lenght); }
double pipe::get_diameter() const { return(diameter); }
bool pipe::get_repair() const { return(repair); }

ostream& operator<<(ostream& os, const pipe& p)
{
    return os << p.get_name() << '\t' << p.get_lenght() << '\t' << p.get_diameter() << '\t' << p.get_repair() << endl;
}

ofstream& operator<<(ofstream& ofs, const pipe& p)
{
    ofs << 1 << endl << p.get_name() << endl << p.get_lenght() << endl << p.get_diameter() << endl << p.get_repair()
        << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, pipe& p)
{
    getline(ifs, p.name);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};

void pipe::add_pipe() // Добавление трубы
{
    system("cls");
    cout << "Add pipe\n";
    cout << "Enter the pipeline's name: ";
    getline(cin, name);
    cout << "Enter pipeline's length (km): ";
    lenght = Get_Int(1, 1000000);
    cout << "Enter pipeline's diameter (cm): ";
    diameter = Get_Int(1, 1000000);
    cout << "Enter pipeline's status (0 working, 1 in the repair): ";
    repair = Get_Int(0, 1);
}

void pipe::set_repair() // Редактирование трубы
{
    system("cls");
    cout << "Edit pipe\n";
    cout << "Old repair status: " << repair << endl;;
    cout << " Enter the new repair status: ";
    repair = Get_Int(0, 1);
}