#include <iostream>
#include <fstream>


int count_unique(const int* arr, const int length)
{
	int res = 1;

	for (size_t i = 1; i < length; i++)
	{
		if (arr[i] != arr[i - 1])
			res++;
	}

	return res;
}


int main()
{
	int length;
	int* array;

	std::ifstream fin("input.txt");
	fin >> length;

	array = new int[length];
	for (int i = 0; i < length; ++i)
		fin >> array[i];

	int unique = count_unique(array, length);

	std::ofstream fout("output.txt");
	fout << unique;
	fout.close();

	delete[] array;
	return 0;
}