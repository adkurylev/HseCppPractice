// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void countSort(int* a, int n);

int main()
{
	srand(1337);

	int* array = new int[100];

	for (size_t i = 0; i < 100; i++)
	{
		array[i] = rand() % 1000;
		cout << array[i] << " ";
	}

	countSort(array, 100);

	cout << "\n\n";

	for (size_t i = 0; i < 100; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n\n";

	system("pause");
}

int getMax(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max; //the max element from the array 
}

void countSort(int* array, int size) {
	int* output = new int [size];
	int max = getMax(array, size);
	int* count = new int [max]; //create count array (max+1 number of elements) 
	for (int i = 0; i < max; i++)
		count[i] = 0; //initialize count array to all zero 
	for (int i = 0; i < max; i++)
		count[array[i]]++; //increase number count in count array. 
	for (int i = 0; i < max; i++)
		count[i] += count[i - 1]; //find cumulative frequency 
	for (int i = size - 1; i > -1; i--) {
		output[count[array[i]]] = array[i];
		count[array[i]]--; //decrease count for same numbers 
	}
	for (int i = 0; i < size; i++) {
		array[i] = output[i]; //store output array to main array 
	}
}