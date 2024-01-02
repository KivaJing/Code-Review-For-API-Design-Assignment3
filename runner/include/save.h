#pragma once
#include<iostream>
#include<fstream>

#include"batch.hpp"
using namespace runner;
using namespace std;
class Save
{
private:
	struct score
	{
		string name;
		int score;

	};

	/*std::ifstream read;
	std::ofstream write;*/

	struct Student {
		int roll_no;
		string name;
	};

public:
	Save();
	~Save();
	void save();
	void final_page(PrimitiveBatch& batch);
};