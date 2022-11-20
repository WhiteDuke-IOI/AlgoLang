#include "pipe.h"
#include "CS.h"
#include <unordered_map>
#include <unordered_set>


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

bool file_exist(const string& name_file)
{
    ifstream exist("..\\" + name_file); // Проверка существования файла    
    bool flag = exist.is_open();
    exist.close();
    return(flag);
}

//Добавление трубы
void add_pipe_object(unordered_map <int, pipe>& mp, int& max_pipe_id) {
    cin >> mp[++max_pipe_id];
    mp[max_pipe_id].set_pipe_id(max_pipe_id);
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
        for (auto iter : mp) 
            cout << "|" << setw(4) << iter.first << "|" << iter.second; 

        cout << "\nEnter the ID of pipeline: ";
        auto iter = mp.find(Get_Num(1, 1000000));
        if (iter == mp.end()) 
            cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else 
    {
        std::cout << "Sorry, we didn't found any pipeline" << endl; 
        system("pause"); 
    }    
}

//Добавление КС
void add_CS_object(unordered_map <int, CS>& mp, int& max_cs_id) {
    cin >> mp[++max_cs_id];
    mp[max_cs_id].set_cs_id(max_cs_id);
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
        auto iter = mp.find(Get_Num(1, 1000000));
        if (iter == mp.end()) cout << "\nWe cannot find this id. Try again \n" << endl;
        else {
            int i = iter->first;
            func(mp, i);
        }
    }
    else { std::cout << "Sorry, we didn't found any CS" << endl; system("pause"); }
}

void show_pipe(const unordered_map <int, pipe>& mp_pipe) {
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
        << "================================================================" << endl;
    if (mp_pipe.size() != 0) { for (auto iter : mp_pipe) cout << iter.second; }
    else { std::cout << "Sorry, we didn't found any pipeline" << endl; }
}

void show_cs(const unordered_map <int, CS>& mp_cs) {
    cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
        << "====================================================================" << endl;
    if (mp_cs.size() != 0) { for (auto iter : mp_cs) cout << iter.second; }
    else { std::cout << "Sorry, we didn't found any CS" << endl; }
}

//Сохранение в файл
void save(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    string name_file;
    do {
        cout << "\n Enter the name of file, using for saving data: ";
        getline(cin, name_file);
        if (file_exist(name_file))
            cout << "This file is already exist. Rewrite file ? Yes 1 / No 0";
        else
            break;
    } while (!Get_Num(0, 1));

    ofstream fout("..\\" + name_file, ios::out);

    if (fout.is_open()) {
        if (mp_pipe.size()) for (auto iter : mp_pipe) {fout << iter.second; }
        if (mp_cs.size()) for (auto iter : mp_cs) {fout << iter.second; }
        fout.close();
    }
    cout << "\nData "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been saved";
    system("pause");
}


//Загрузка из файла
void upload(unordered_map <int, pipe>& mp_pipe, unordered_map <int, CS>& mp_cs, int& max_pipe_id, int& max_cs_id) {
    system("cls");
    string name_file;
    while (1) {
        cout << "Enter the name of file, using for loading data: ";
        getline(cin, name_file);
        if (file_exist(name_file))
        {
            cout << "This file has been find ";
            break;
        }
        else
        {
            cout << "We cannot find this file. Try again ? Yes 1/ No 0: ";
            if (!Get_Num(0, 1))
                return;
        }
    }

    ifstream fin("..\\" + name_file);
    if (fin.is_open()) {
        int type;
        int id;
        while (fin >> type) { // Считывание данных из файла до конца

            fin >> id;
            fin.ignore();
            if (type == 1) {
                fin >> mp_pipe[id];
                mp_pipe[id].set_pipe_id(id);
                if (id > max_pipe_id)
                    max_pipe_id = id;
            }
            if (type == 2) {
                fin >> mp_cs[id];
                mp_cs[id].set_cs_id(id);
                if (id > max_cs_id)
                    max_cs_id = id;
            }
        }

        fin.close();
        cout << "\nData "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been upload";
    }
}


void pakage_edit_pipe(unordered_map <int, pipe>& mp, unordered_set<int>& found_obj) {
    cout << "Choice what you want to edit, enter 0 for All or 1 for select object's ID: ";
    unordered_set<int> obj_vec;
    if (Get_Num(0, 1)) {        
        do {
            cout << "Enter ID: ";
            int q = Get_Num(0, (int)mp.size());
            if (q == 0) { break; }
            if (find(found_obj.begin(), found_obj.end(), q) != found_obj.end()) {
                obj_vec.insert(q);
            }
            else {
                cout << "This object not found\n";
            }
        } while (true);
        if (!obj_vec.size()) {
            return;
        }
    }
    
    found_obj = obj_vec;

    cout << "Enter 0 (delete) or 1 (edit): ";
    if ((bool)Get_Num(0, 1)) {
        cout << "Set new repair status: "; bool new_status = Get_Num(0, 1);
        for (int i : obj_vec)
            mp[i].set_repair(new_status);
    }
    else {
        for (int i : obj_vec)
            mp.erase(i);
    }
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
unordered_set<int> find_pipe_by_filter(const unordered_map <int, pipe>& mp, filter_pipe<T> f, T param) {
    unordered_set<int> res;
    for (auto iter : mp) if (f(iter, param)) res.insert(iter.first);
    return res;
}

void filtration_pipe_by_repair(unordered_map <int, pipe>& mp) {
    system("cls");
    cout << "Find pipeline by repair" << endl;
    if (mp.size()) {
        cout << "Enter status of repair: ";
        unordered_set<int> found_vector = find_pipe_by_filter<bool>(mp, check_pipe_by_repair, Get_Num(0, 1));
        cout << endl << left << "Find pipelines\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
             << "================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << mp[i]; } }
        else { cout << "Sorry, we didn't found any pipeline" << endl; }
        cout << "\nWould you like edit this pipelines? 1 Yes/ 0 No: "; if (Get_Num(0, 1)) { pakage_edit_pipe(mp, found_vector); }
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
        unordered_set<int> found_vector = find_pipe_by_filter(mp, check_pipe_by_name, param);
        cout << endl << left << "Find pipelines\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Length" << "|" << setw(16) << "Diameter" << "|" << setw(6) << "Repair" << "|" << endl
             << "================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << mp[i]; } }
        else { cout << "Sorry, we didn't found any pipeline" << endl; }
        cout << "Would you like edit this pipelines? 1 Yes/ 0 No: "; if (Get_Num(0, 1)) { pakage_edit_pipe(mp, found_vector); }
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
        vector<int> found_vector = find_cs_by_filter(mp, check_cs_by_act_ws, Get_Num(0, 100));
        cout << endl << left << "Find CSs\n";
        cout << "|" << setw(4) << "ID" << "|" << setw(16) << "Name" << "|" << setw(16) << "Count WS" << "|" << setw(16) << "Act WS" << "|" << setw(10) << "Efficiency" << "|" << endl
             << "====================================================================" << endl;
        if (found_vector.size()) { for (int i : found_vector) { cout << mp.at(i); } }
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
        if (found_vector.size() != 0) { for (int i : found_vector) { cout << mp.at(i); } }
        else { cout << "Sorry, we didn't found any CS" << endl; }
    }
    else { cout << "Sorry, we haven't any CS" << endl; system("pause"); }
}