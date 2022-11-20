#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class CS {
private:
	int id;
	string name; // Название коммпрессионой станции
	int count_ws = 0; // Количество цехов
	int act_ws = 0; // Количество цехов в работе
	float eff = 0; // Эффективность работы

public:
	string get_name() const;
	int get_count_ws() const;
	int get_act_ws() const;
	double get_eff() const;

	void set_cs_id(int id);
	void set_act_ws();

	friend ostream& operator<<(std::ostream& os, const CS& stat);
	friend istream& operator>>(std::istream& is, CS& stat);
	friend ofstream& operator<<(std::ofstream& ofs, const CS& stat);
	friend ifstream& operator>>(std::ifstream& ifs, CS& stat);
};

