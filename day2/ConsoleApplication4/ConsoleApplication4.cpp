#include <iostream>
#include <fstream>

using namespace std;

void calculateSchoolNumber(int* array)
{
	ifstream fin("input.txt");
	string str1, str2;
	int maxSchool = 0, maxCount = 0;
	int school;

	fin >> str1 >> str2 >> school;
	maxSchool = school;
	maxCount++;

	while (fin.eof())
	{

	}
}

int main()
{
	int* array;

	ofstream fout("output.txt");



}