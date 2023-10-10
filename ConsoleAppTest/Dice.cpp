#include "Dice.h"

Dice::Dice() {
	dn = 1;
	dv = 6;
	db = 0;
}

Dice::Dice(unsigned int n, unsigned int v, unsigned int b) {
	dn = n;
	dv = v;
	db = b;
}

vector<int> Dice::Roll() {
	std::vector<int> v;
	for (int i = 0; i < dn; i++) {
		srand(time(NULL) + rand());

		v.push_back(rand() % dv + 1);
	}
	v.push_back(db);
	return v;
}

string Dice::getString() {
	std::string s;
	s = to_string(dn) + "D" + to_string(dv) + " + " + to_string(db);
	return s;
}

string Dice::getRollString(vector<int> r) {
	string s;
	for (int i = 0; i < r.size(); i++) {
		if ((i + 1) == r.size()) { s += " | BONUS "; }
		s.push_back('[');
		s+= to_string(r[i]);
		s.push_back(']');
	}
	return s;
}

int Dice::getBonus() {
	return db;
}

int Dice::getRollTotal(vector<int> r) {
	int i = 0;
	for (int j = 0; j < r.size(); j++) {
		i += r[j];
	}
	return i;
}
