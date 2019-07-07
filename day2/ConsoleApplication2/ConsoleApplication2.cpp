#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Циклически сдвиньте элементы массива вправо на заданное количество позиций s.
 * (A[0] переходит на место A[s-1], A[1] на место A[s], ..., последний элемент переходит на место A[s-2]).
 * Используйте минимально возможное количество операций присваивания. Не используйте дополнительный массив
 * @param arr
 * @param length
 * @param shift
 * @return
 */
void shift_array(int* arr, const int length, const int shift)
{
	if (shift >= 0)
	{
		reverse(&arr[0], &arr[shift]);
		reverse(&arr[0], &arr[length]);
		reverse(&arr[0], &arr[length - shift]);
	}
	else
	{
		reverse(&arr[0], &arr[length - abs(shift)]);
		reverse(&arr[0], &arr[length]);
		reverse(&arr[0], &arr[abs(shift)]);
	}
}


int main()
{
	int length, shift;
	int* array;

	std::ifstream file("input.txt");
	file >> length >> shift;

	array = new int[length];
	for (int i = 0; i < length; ++i)
		file >> array[i];

	shift = fmod(shift, length);

	shift_array(array, length, shift);

	std::ofstream output("output.txt");
	if (output.is_open())
	{
		for (int i = 0; i < length; ++i)
			output << array[i] << ' ';
	}

	delete[] array;

	return 0;
}