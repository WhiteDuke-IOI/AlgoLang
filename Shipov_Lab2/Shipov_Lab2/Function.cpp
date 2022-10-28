#include "pipe.h"
#include "CS.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>

void print_menu()
{
    system("cls");
    cout << "1. Add pipeline\n"
        << "2. Edit pipeline\n"
        << "3. Delete pipeline\n"
        << "4. Add compressor stations\n"
        << "5. Edit compressor stations\n"
        << "6. Delete compressor stations\n"
        << "7. Show all objects\n"
        << "8. Save\n"
        << "9. Upload\n"
        << "0. Exit\n"
        << "\nChoose action - ";
}

int Get_Int(const int a, const int b) {
    int n;
    std::cin >> n;
    while ((cin.fail()) || (n < a) || (n > b) || (cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Enter correct number: ";
        std::cin >> n;
    }
    return n;
}

float Get_Float(const float a, const float b) {
    float n;
    std::cin >> n;
    while ((std::cin.fail()) || (n < a) || (n > b) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Enter correct number: ";
        std::cin >> n;
    }
    return n;
}

bool file_exist(const string& name_file)
{
    ifstream exist(name_file); // Проверка существования файла
    return(exist.is_open());
}

void add_pipe_object(unordered_map <int, pipe>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

using pipe_func = void(*)(unordered_map <int, pipe>& p, int id);
void edit_pipe(unordered_map <int, pipe>& mp, int id) {
    mp[id].set_repair();
}

void delete_pipe(unordered_map <int, pipe>& mp, int id) {
    mp.erase(id);
}

void action_over_pipe(unordered_map <int, pipe>& mp, pipe_func func) {
    cout << "Enter the ID of pipeline" << endl;
    auto iter = mp.find(Get_Int(1, 1000000));
    if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
    else {
        int i = iter->first;
        func(mp, i);
    }
}

void add_CS_object(unordered_map <int, CS>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}

using CS_func = void(*)(unordered_map <int, CS>& p, int id);
void edit_cs(unordered_map <int, CS>& mp, int id) {
    mp[id].set_act_ws();
}

void delete_cs(unordered_map <int, CS>& mp, int id) {
    mp.erase(id);
}

void action_over_cs(unordered_map <int, CS>& mp, CS_func func) {
    cout << "Enter the ID of compressor station" << endl;
    auto iter = mp.find(Get_Int(1, 1000000));
    if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
    else {
        int i = iter->first;
        func(mp, i);
    }
}

void show_all_object(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    cout << left << "All objects\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
        << "================================================================" << endl;    
    if (mp_pipe.size() != 0) { for (auto iter : mp_pipe) cout << "|" << setw(4) << iter.first << "|" << iter.second; }
    else { std::cout << "Sorry, we didn't found any pipeline" << endl; }    

    cout << endl;

    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
        << "====================================================================" << endl;
    if (mp_cs.size() != 0) { for (auto iter : mp_cs) cout << "|" << setw(4) << iter.first << "|" << iter.second; }
    else { std::cout << "Sorry, we didn't found any CS" << endl; }
    system("pause");
}

void save(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    cout << "Enter the name of file, using for saving data: ";
    string name_file;
    getline(cin, name_file);
    ofstream fout("..\\" + name_file, file_exist(name_file) ? cout << "The file with this name is exist. Rewrite file ? (1 Yes) / (0 No): ", Get_Int(0, 1) : 0 ? ios::out : ios::app);

    if (fout.is_open())
    {
        if (mp_pipe.size()) for (auto iter : mp_pipe) fout << iter.second;
        if (mp_cs.size()) for (auto iter : mp_cs) fout << iter.second;
        fout.close();
    }
    cout << "\nData "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been saved";
}

void upload(unordered_map <int, pipe>& mp_pipe, unordered_map <int, CS>& mp_cs) {
    system("cls");
    string name_file;
    while (1) {
        cout << "Enter the name of file, using for loading data: ";
        getline(cin, name_file);
        if (file_exist("..\\" + name_file)) { cout << "This file has been find "; break; }
        else { cout << "We cannot find this file. Try again ? Yes 1/ No 0: "; if (Get_Int(0, 1) == false) break; }
    }

    ifstream fin("..\\" + name_file);
    if (fin.is_open()) {
        int type;
        int i = 1;
        int j = 1;
        while (fin >> type) { // Считывание данных из файла до конца файла
            fin.ignore();
            if (type == 1) fin >> mp_pipe[i], i++;
            if (type == 2) fin >> mp_cs[j], j++;
        }
        fin.close();
        cout << "\nData "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been upload";
    }
}