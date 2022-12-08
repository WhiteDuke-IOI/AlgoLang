#include "utility.h"
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>


void print_menu()
{
    system("cls");
    cout << "1. Add pipeline\n" << "max pipe id: " << pipe::max_pipe_id 
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
         << "14. Create new connection\n"
         << "15. Show all connection\n"
         << "16. Topology sort\n"
         << "0. Exit\n"
         << "\nChoose action - ";
}

bool file_exist(const string& name_file)
{
    ifstream exist("..\\" + name_file); // Проверка существования файла    
    bool flag = exist.is_open();
    exist.close();
    return(flag);
}

//Добавление трубы
void add_pipe_object(unordered_map <int, pipe>& mp) {    
    pipe p;
    cin >> p;
    mp.insert({ p.get_id(), p });
}

//Действие над трубой
using pipe_func = void(*)(unordered_map <int, pipe>& p, int id);
void edit_pipe(unordered_map <int, pipe>& mp, int id) {
    cout << "Enter the new repair status: ";
    mp[id].set_repair((bool)Get_Num(0, 1));
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
void add_CS_object(unordered_map <int, CS>& mp) {
    CS stat;
    cin >> stat;
    mp.insert({ stat.get_id(), stat });
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
void save(const unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs, vector <connect>& connects) {
    system("cls");
    string name_file;
    do {
        cout << "Enter the name of file, using for saving data: ";
        getline(cin, name_file);
        if (file_exist(name_file))
            cout << "This file is already exist. Rewrite file ? Yes 1 / No 0: ";
        else
            break;
    } while (!Get_Num(0, 1));

    ofstream fout("..\\" + name_file, ios::out);

    if (fout.is_open()) {
        if (mp_pipe.size()) for (auto iter : mp_pipe) {fout << iter.second; }
        if (mp_cs.size()) for (auto iter : mp_cs) {fout << iter.second; }
        if (connects.size()) for (auto iter : connects) { fout << 3 << endl << iter.initial_cs_id << endl << iter.terminal_cs_id << endl << iter.pipe_id.get_id() << endl << endl; }
        fout.close();
    }
}


//Загрузка из файла
void upload(unordered_map <int, pipe>& mp_pipe, unordered_map <int, CS>& mp_cs, vector <connect>& connects) {
    system("cls");
    string name_file;
    while (1) {
        cout << "Enter the name of file, using for loading data: ";
        getline(cin, name_file);
        if (file_exist(name_file)) {
            cout << "This file has been find ";
            break;
        }
        else {
            cout << "We cannot find this file. Try again ? Yes 1/ No 0: ";
            if (!Get_Num(0, 1))
                return;
        }
    }

    ifstream fin("..\\" + name_file);
    if (fin.is_open()) {
        int type;
        while (fin >> type) { // Считывание данных из файла до конца
            fin.ignore();
            if (type == 1) {
                pipe p;
                fin >> p;
                mp_pipe.insert({ p.get_id(), p });
                pipe::max_pipe_id = (pipe::max_pipe_id < p.get_id() ? p.get_id() : pipe::max_pipe_id);
            }
            if (type == 2) {
                CS stat;
                fin >> stat;
                mp_cs.insert({ stat.get_id(), stat });
                CS::max_cs_id = (CS::max_cs_id < stat.get_id() ? stat.get_id() : CS::max_cs_id);
            }
            if (type == 3) {
                connect con;
                pipe::max_pipe_id--;
                fin >> con.initial_cs_id;
                fin >> con.terminal_cs_id;
                int id;
                fin >> id;
                con.pipe_id = mp_pipe.at(id);
                connects.push_back(con);
            }
        }
        fin.close();
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
            if (found_obj.find(q) != found_obj.end()) {
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
    else {
        obj_vec = found_obj;
    }

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

int checker_cs_id(const unordered_map <int, CS>& mp_cs) {
    while (1) {
        int id = Get_Num(1, INT_MAX);
        if (mp_cs.count(id))
            return(id);
        else
            cout << "\nThis ID not exist. Try again: ";
    }
}

int checker_pipeline_id(unordered_map <int, pipe>& mp_pipe) {
    while (1) {
        cout << "Enter pipeline's diameter 500, 700, 1400: ";
        int diameter = Get_Num(1, INT_MAX);
        if (!((diameter == 500) || (diameter == 700) || (diameter == 1400))) {
            cout << endl << "Incorrect diameter. Try again." << endl;
            continue;
        }

        for (auto iter_search : mp_pipe)
            if ((diameter == iter_search.second.get_diameter()) && (!iter_search.second.used))
                return(iter_search.first);

        while (1) {
            cout << "\nThis pipeline diameter's not exist. Create new pipeline.";
            //add_pipe_object(mp_pipe);  
            pipe p;
            cin >> p;
            mp_pipe.insert({ p.get_id(), p });
            if (mp_pipe.at(p.get_id()).get_diameter() != diameter)
                cout << "This pipeline hasn't " << diameter << " diameter. Create again.";
            else return(p.get_id());
        }
    }
    
}

void create_new_connection(vector <connect>& connects, unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    connect new_connect;
    pipe::max_pipe_id--;

    bool flag = false;
    do {
        cout << "Enter initial compressor station's ID: ";
        new_connect.initial_cs_id = checker_cs_id(mp_cs);

        cout << "Enter terminal compressor station'S ID: ";
        new_connect.terminal_cs_id = checker_cs_id(mp_cs);

        for (auto iter : connects) {
            if ((iter.initial_cs_id == new_connect.initial_cs_id) && (iter.terminal_cs_id == new_connect.terminal_cs_id)) {
                flag = true;
                cout << "This CS's was connected. Try again.\n";
            }
            else {
                flag = false;
            }                
        }      
    } while(flag);    

    int id = checker_pipeline_id(mp_pipe);
    new_connect.pipe_id = mp_pipe[id];
    mp_pipe[id].used = true;

    connects.push_back(new_connect);
}

void show_all_connection(vector <connect>& connects, unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    unordered_map <int, unordered_map <int, pipe>> adjacency_matrix;
    for (auto iter_connect : connects)
    {
        if (!(
            mp_cs.count(iter_connect.initial_cs_id) && mp_cs.count(iter_connect.terminal_cs_id)
            && mp_pipe.count((iter_connect.pipe_id).get_id())
            )) continue;
        adjacency_matrix[iter_connect.initial_cs_id][iter_connect.terminal_cs_id] = iter_connect.pipe_id;
    }
        

    cout << "[CS ID] -> (CS ID) : PIPE ID \n" << endl;
    for (auto iter_some_network : adjacency_matrix) {
        cout << "[" << iter_some_network.first << "]" << " -> ";
        for (auto iter_term : adjacency_matrix[iter_some_network.first])
            cout << "(" << iter_term.first << ")" << " : " << iter_term.second.get_id() << ",  ";
        cout << endl;
    }
    system("pause");
}

void dfs(unordered_map <int, unordered_map <int, pipe>> adjacency_matrix, vector<int>& top_sort_cs, int first_cs) {
    map <int, bool> visited_point;
    stack <int> stack_dfs;
    int ID_cs = first_cs;

    top_sort_cs.push_back(ID_cs);
    stack_dfs.push(ID_cs);

    while (!stack_dfs.empty())
    {
        ID_cs = stack_dfs.top();
        stack_dfs.pop();

        for (auto iter_adj_matrix : adjacency_matrix[ID_cs])
        {
            stack_dfs.push(ID_cs);
            if (!visited_point[ID_cs])
                top_sort_cs.push_back(ID_cs);
            visited_point[ID_cs] = true;
        }
    }
}

void topology_sort(vector <connect>& connects, unordered_map <int, pipe>& mp_pipe, const unordered_map <int, CS>& mp_cs) {
    system("cls");
    unordered_map <int, unordered_map <int, pipe>> adjacency_matrix;
    unordered_map <int, unordered_map <int, pipe>> inv_adjacency_matrix;
    for (auto iter_connect : connects) {
        if (!(
            mp_cs.count(iter_connect.initial_cs_id) && mp_cs.count(iter_connect.terminal_cs_id)
            && mp_pipe.count((iter_connect.pipe_id).get_id())
            )) continue;
        adjacency_matrix[iter_connect.initial_cs_id][iter_connect.terminal_cs_id] = iter_connect.pipe_id;
        inv_adjacency_matrix[iter_connect.terminal_cs_id][iter_connect.initial_cs_id] = iter_connect.pipe_id;
    }

    stack <int> stack_dfs;
    for (auto iter_adj_matrix : adjacency_matrix)
    {
        map <int, bool> visited_point;
        int ID_cs = 0;
        stack_dfs.push(iter_adj_matrix.first);

        while (!stack_dfs.empty())
        {
            ID_cs = stack_dfs.top();
            stack_dfs.pop();

            if (adjacency_matrix.find(ID_cs) != adjacency_matrix.end())
                for (auto& iter_adj_matrix_ID_cs : adjacency_matrix.at(ID_cs))
                {
                    if (visited_point[iter_adj_matrix_ID_cs.first])
                    {
                        cout << " This graph isn't tree. Topology sort is impossible " << endl;
                        system("pause");
                        return;
                    }
                    stack_dfs.push(iter_adj_matrix_ID_cs.first);
                    visited_point[ID_cs] = true;
                }
        }
    }

    map <int, bool> visited_point;
    vector<int> top_sort_cs;

    for (auto iter_adj_matrix : adjacency_matrix)
        if (inv_adjacency_matrix.find(iter_adj_matrix.first) == inv_adjacency_matrix.end())
        {
            int ID_cs = iter_adj_matrix.first;
            stack <int> stack_dfs;

            stack_dfs.push(ID_cs);
            top_sort_cs.push_back(ID_cs);
            while (!stack_dfs.empty())
            {
                ID_cs = stack_dfs.top();
                stack_dfs.pop();
                for (auto iter_adj_matrix : adjacency_matrix[ID_cs])
                {
                    ID_cs = iter_adj_matrix.first;
                    stack_dfs.push(ID_cs);
                    if (!visited_point[ID_cs])
                        top_sort_cs.push_back(ID_cs);
                    visited_point[ID_cs] = true;
                }
            }
        }

    int num_CS_at_topology = 1;
    for (auto iter : top_sort_cs)
    {
        cout << " " << num_CS_at_topology++ << " -> ID [" << iter << "] " << endl;
    }
    system("pause");
}

