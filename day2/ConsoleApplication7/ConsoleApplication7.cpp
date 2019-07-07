#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int* array, int N)
{
	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = 0; j < N - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
			}
		}
	}
}

int main()
{
	ifstream fin("input.txt");
	int N;
	fin >> N;
	int* array = new int[N];
	for (size_t i = 0; i < N; i++)
	{
		fin >> array[i];
	}
	fin.close();

	bubbleSort(array, N);

	ofstream fout("output.txt");
	for (size_t i = 0; i < N; i++)
	{
		fout << array[i] << " ";
	}
	fout.close();

	delete[] array;
	return 0;
}