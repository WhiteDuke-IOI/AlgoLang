#include <string>

using namespace std;

class CS {
private:
	string name; // Название коммпрессионой станции
	int count_ws = 0; // Количество цехов
	int act_ws = 0; // Количество цехов в работе
	float eff = 0; // Эффективность работы

public:
	string get_name() const;
	int get_count_ws() const;
	int get_act_ws() const;
	double get_eff() const;

	void add_CS();
	void set_act_ws();

	friend ostream& operator<<(ostream& os, const CS& stat);
	friend ofstream& operator<<(ofstream& ofs, const CS& stat);
	friend ifstream& operator>>(ifstream& ifs, CS& stat);
};

