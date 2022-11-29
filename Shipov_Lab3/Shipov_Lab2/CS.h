#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class CS {
private:
	int id;
	string name; // Название коммпрессионой станции
	int count_ws; // Количество цехов
	int act_ws; // Количество цехов в работе
	float eff; // Эффективность работы

public:
	static int max_cs_id;

	CS() {
		id = max_cs_id++;
		name = "CS";
		count_ws = 0;
		act_ws = 0;
		eff = 0;
	}

	string get_name() const;
	int get_count_ws() const;
	int get_act_ws() const;
	double get_eff() const;
	int get_id() const;

	void set_act_ws();

	friend ostream& operator<<(std::ostream& os, const CS& stat);
	friend istream& operator>>(std::istream& is, CS& stat);
	friend ofstream& operator<<(std::ofstream& ofs, const CS& stat);
	friend ifstream& operator>>(std::ifstream& ifs, CS& stat);
};

