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

	vector<int> Roll(); //Roll the dice

	string getString(); //Get the value of the dice as a string (like "3d6 + 2")
	static string getRollString(vector<int> r); //Get the value of the roll() as a string

	int getBonus(); //Get the bonus damage of the dice
	static int getRollTotal(vector<int> r); //get the roll value as a simple int
};

