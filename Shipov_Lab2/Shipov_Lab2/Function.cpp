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
        << "10. Filtration pipe by name\n"
        << "11. Filtration pipe by repair\n"
        << "12. Filtration CS by name\n"
        << "13. Filtration CS by active workshop\n"
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
    ifstream exist("..\\" + name_file); // Проверка существования файла
    return(exist.is_open());
}


//Добавление трубы
void add_pipe_object(unordered_map <int, pipe>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}


//Действие над трубой
using pipe_func = void(*)(unordered_map <int, pipe>& p, int id);
void edit_pipe(unordered_map <int, pipe>& mp, int id) {
    mp[id].set_repair();
}

void delete_pipe(unordered_map <int, pipe>& mp, int id) {
    mp.erase(id);
}

void action_over_pipe(unordered_map <int, pipe>& mp, pipe_func func) {
    system("cls");
    cout << left << "Edit pipe\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
        << "================================================================" << endl;
    if (mp.size() != 0) { 
        for (auto iter : mp) cout << "|" << setw(4) << iter.first << "|" << iter.second; 

        cout << "\nEnter the ID of pipeline: ";
        auto iter = mp.find(Get_Int(1, 1000000));
        if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else { std::cout << "Sorry, we didn't found any pipeline" << endl; system("pause"); }    
}


//Добавление КС
void add_CS_object(unordered_map <int, CS>& mp) {
    auto iter = mp.end();
    cin >> mp[mp.size() != 0 ? iter--, iter->first + 1 : 1];
}


//Действие над КС
using CS_func = void(*)(unordered_map <int, CS>& p, int id);
void edit_cs(unordered_map <int, CS>& mp, int id) {
    mp[id].set_act_ws();
}

void delete_cs(unordered_map <int, CS>& mp, int id) {
    mp.erase(id);
}

void action_over_cs(unordered_map <int, CS>& mp, CS_func func) {
    system("cls");
    cout << left << "Edit CS\n";
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
        << "====================================================================" << endl;
    if (mp.size() != 0) { 
        for (auto iter : mp) cout << "|" << setw(4) << iter.first << "|" << iter.second; 

        cout << "\nEnter the ID of compressor station: ";
        auto iter = mp.find(Get_Int(1, 1000000));
        if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else { std::cout << "Sorry, we didn't found any CS" << endl; system("pause"); }
}


//Показ всех объектов
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


//Сохранение в файл
void save(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    cout << "Enter the name of file, using for saving data: ";
    string name_file;
    getline(cin, name_file);
    ofstream fout("..\\" + name_file, file_exist(name_file) ? cout << "The file with this name is exist. Rewrite file ? (1 Yes) / (0 No): ", ((bool)Get_Int(0, 1) ? ios::out : ios::app) : ios::out);
    
    if (fout.is_open()) {
        if (mp_pipe.size()) for (auto iter : mp_pipe) fout << iter.second;
        if (mp_cs.size()) for (auto iter : mp_cs) fout << iter.second;
        fout.close();
    }
    cout << "\nData "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been saved";
    system("pause");
}


//Загрузка из файла
void upload(unordered_map <int, pipe>& mp_pipe, unordered_map <int, CS>& mp_cs) {
    system("cls");
    string name_file;
    while (1) {
        cout << "Enter the name of file, using for loading data: ";
        getline(cin, name_file);
        if (file_exist(name_file)) { cout << "This file has been find "; break; }
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


void pakage_edit_pipe(unordered_map <int, pipe>& mp, vector<int>& found_obj) {    
    cout << "Choice what you want to edit, enter 0 for All or 1 for select object's ID: ";
    if (Get_Int(0, 1)) {
        found_obj.clear();
        do {
            cout << "Enter ID: ";
            int q = Get_Int(0, mp.size());
            if (q == 0) { break; }
            found_obj.push_back(q);
        } while (true);
    }
    cout << "Set new repair status: "; bool new_status = Get_Int(0, 1);
    for (int i : found_obj) mp[i].set_repair(new_status);
}


template<typename T> //Фильтрация труб
using filter_pipe = bool(*)(const pair <int, pipe>& p, T param);
bool check_pipe_by_repair(const pair <int, pipe>& p, bool param) {
    return p.second.get_repair() == param;
}

bool check_pipe_by_name(const pair <int, pipe>& p, string param) {
    size_t search = p.second.get_name().find(param);
    return search != std::string::npos;
}

template<typename T>
vector<int> find_pipe_by_filter(const unordered_map <int, pipe>& mp, filter_pipe<T> f, T param) {
    vector<int> res;
    for (auto iter : mp) if (f(iter, param)) res.push_back(iter.first);
    return res;
}

void filtration_pipe_by_repair(unordered_map <int, pipe>& mp) {
    system("cls");
    cout << "Find pipeline by repair" << endl;
    if (mp.size()) {
        cout << "Enter status of repair: ";
        vector<int> found_vector = find_pipe_by_filter<bool>(mp, check_pipe_by_repair, Get_Int(0, 1));
        cout << endl << left << "Find pipelines\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
             << "================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << "|" << setw(4) << i << "|" << mp[i]; } }
        else { cout << "Sorry, we didn't found any pipeline" << endl; }
        cout << "\nWould you like edit this pipelines? 1 Yes/ 0 No: "; if (Get_Int(0, 1)) { pakage_edit_pipe(mp, found_vector); }
    }
    else { cout << "Sorry, we haven't any pipeline" << endl; system("pause"); }    
}

void filtration_pipe_by_name(unordered_map <int, pipe>& mp) {
    system("cls");
    cout << "Find pipeline by name" << endl;
    if (mp.size()) {
        cout << "Enter name or part of name: ";
        string param;
        getline(cin, param);
        vector<int> found_vector = find_pipe_by_filter(mp, check_pipe_by_name, param);
        cout << endl << left << "Find pipelines\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
             << "================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << "|" << setw(4) << i << "|" << mp[i]; } }
        else { cout << "Sorry, we didn't found any pipeline" << endl; }
        cout << "Would you like edit this pipelines? 1 Yes/ 0 No: "; if (Get_Int(0, 1)) { pakage_edit_pipe(mp, found_vector); }
    }
    else { cout << "Sorry, we haven't any pipeline" << endl; system("pause"); }
}


template<typename T> //Фильтрация КС
using filter_cs = bool(*)(const pair <int, CS>& p, T param);
bool check_cs_by_act_ws(const pair <int, CS>& p, int param) {
    return (p.second.get_act_ws() * 100 / p.second.get_count_ws()) >= param;
}

bool check_cs_by_name(const pair <int, CS>& p, string param) {
    size_t search = p.second.get_name().find(param);
    return search != std::string::npos;
}

template<typename T>
vector<int> find_cs_by_filter(const unordered_map <int, CS>& mp, filter_cs<T> f, T param) {
    vector<int> res;
    for (auto iter : mp) if (f(iter, param)) res.push_back(iter.first);
    return res;
}

void filtration_cs_by_act_ws(const unordered_map <int, CS>& mp) {
    system("cls");
    cout << "Find CS by active workshop" << endl;
    if (mp.size()) {
        cout << "Enter percent of working workshops: ";
        vector<int> found_vector = find_cs_by_filter(mp, check_cs_by_act_ws, Get_Int(0, 100));
        cout << endl << left << "Find CSs\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
             << "====================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << "|" << setw(4) << i << "|" << mp.at(i); } }
        else { cout << "Sorry, we didn't found any CS" << endl; }
    }
    else { cout << "Sorry, we haven't any CS" << endl; system("pause"); }
}

void filtration_cs_by_name(const unordered_map <int, CS>& mp) {
    system("cls");
    cout << "Find CS by name" << endl;
    if (mp.size()) {
        cout << "Enter name or part of name: ";
        string param;
        getline(cin, param);
        vector<int> found_vector = find_cs_by_filter(mp, check_cs_by_name, param);
        cout << endl << left << "Find CSs\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
             << "====================================================================" << endl;
        if (found_vector.size() != 0) { for (int i : found_vector) { cout << "|" << setw(4) << i << "|" << mp.at(i); } }
        else { cout << "Sorry, we didn't found any CS" << endl; }
    }
    else { cout << "Sorry, we haven't any CS" << endl; system("pause"); }
}