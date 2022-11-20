#include "pipe.h"

const int PIPE_FLAG = 1;

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

string pipe::get_name() const { return(name); }
bool pipe::get_repair() const { return(repair); }

ostream& operator<<(ostream& os, const pipe& p) {
    return os << "|" << setw(4) << p.id << "|" << setw(16) << p.name << "|" << setw(16) << p.lenght << "|" << setw(16) << p.diameter
        << "|" << setw(6) << p.repair << "|" << endl;
}

istream& operator>>(istream& is, pipe& p) {
    system("cls");
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
    getline(ifs, p.name);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};

void pipe::set_repair() { // Редактирование трубы
    cout << "Old repair status: " << repair << endl;;
    cout << "Enter the new repair status: ";
    repair = Get_Num(0, 1);
}

void pipe::set_repair(bool new_status)
{
    repair = new_status;
}

void pipe::set_pipe_id(int pipe_id) {
    id = pipe_id;
}
