#include <iostream>
#include <fstream>

using namespace std;

/**
 * Переносит все ненулевые элементы массива
 * @param array - массив, в котором осуществляется перенос
 * @param N - число элементов в массиве
 */
void compress(int* array, int N)
{
	int index = N;

	for (size_t i = 0; i < N; i++)
	{
		if (array[i] == 0 && index == N)
		{
			index = i;
		}
		if (array[i] != 0 && index != N)
		{
			array[index] = array[i];
			array[i] = 0;
			index++;
		}

	}
}

int main()
{
	ifstream fin("input.txt");
	int N;
	fin >> N;
	int* array = new int[N];
	for (int i = 0; i < N; ++i)
		fin >> array[i];
	fin.close();

	compress(array, N);

	ofstream fout("output.txt");
	for (int i = 0; i < N; ++i)
		fout << array[i] << " ";
	fout.close();
	delete[] array;
	return 0;
}