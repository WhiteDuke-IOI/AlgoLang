#include "utility.h"

const int PIPE_FLAG = 1;

int pipe::max_pipe_id = 1;


string pipe::get_name() const { return(this->name); }
int pipe::get_lenght() const { return(this->lenght); }
int pipe::get_diameter() const { return(this->diameter); }
bool pipe::get_repair() const { return(this->repair); }
int pipe::get_id() const { return(this->id); }

ostream& operator<<(ostream& os, const pipe& p) {
    return os << "|" << setw(4) << p.id << "|" << setw(16) << p.name << "|" << setw(16) << p.lenght << "|" << setw(16) << p.diameter
        << "|" << setw(6) << p.repair << "|" << endl;
}

istream& operator>>(istream& is, pipe& p) {
    //system("cls");
    cout << "Add pipe\n";
    cout << "Enter the pipeline's name: ";
    getline(cin, p.name);
    cout << "Enter pipeline's length (km): ";
    p.lenght = Get_Num(1, 1000000);
    cout << "Enter pipeline's diameter (cm): ";
    p.diameter = Get_Num(1, 1000000);
    cout << "Enter pipeline's status (0 - on, 1 - off): ";
    p.repair = Get_Num(0, 1);
    return is;
};

ofstream& operator<<(ofstream& ofs, const pipe& p) {
    ofs << PIPE_FLAG << endl << p.id << endl << p.name << endl << p.lenght << endl << p.diameter << endl << p.repair
        << endl << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, pipe& p) {
    ifs >> p.id;
    getline(ifs, p.name);
    getline(ifs, p.name);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};

void pipe::set_repair(bool new_status)
{
    this->repair = new_status;
}
