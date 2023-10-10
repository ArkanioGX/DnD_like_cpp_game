#pragma once
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Dice
{
	unsigned int dn, dv, db;

public:
	Dice();
	Dice(unsigned int n, unsigned int v, unsigned int b);

	vector<int> Roll();

	string getString();
	static string getRollString(vector<int> r);

	int getBonus();
	static int getRollTotal(vector<int> r);
};

