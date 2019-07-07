/*
Учебная практика 2019 "Основы C++", первая неделя
Курылев Александр Дмитриевич
Программа реализована в среде разработки Microsoft Visual Studio 2019
Ниже перечислены реализованные и нереализованные функции сортировки
*/


#include <fstream>
#include <cstdlib>

using namespace std;

//сделано
void bubbleSort(int* array, int N);
void bubbleSortIverson1(int* array, int N);
void bubbleSortIverson2(int* array, int N);
void simpleInsertSort(int* array, int N);
void binaryInsertSort(int* array, int N);

//не сделано
//Сортировка подсчетом, цифровая сортировка

//переменная количесва операций за сортировку
int operationsCount = 0;

int main()
{
#pragma region Инициализация_массивов
	srand(1337);

	int** array = new int* [4];

	for (size_t i = 0; i < 4; i++)
		array[i] = new int[8000];

	for (size_t i = 0; i < 8000; i++)
		array[0][i] = rand() % 10;

	for (size_t i = 0; i < 8000; i++)
		array[1][i] = rand() % 10001;

	for (size_t i = 0; i < 8000; i++)
	{
		array[2][i] = i;
		array[3][i] = i;
	}

	for (size_t i = 0; i < 9; i++)
		swap(array[2][rand() % 8000], array[2][rand() % 8000]);

	reverse(&array[3][0], &array[3][7999]);
#pragma endregion
	
	//массив ссылок на методы сортировки
	void (*functions[5])(int* a, int n) = { bubbleSort, bubbleSortIverson1, bubbleSortIverson2, simpleInsertSort, binaryInsertSort };
	
	//открытие потока на запись в файл
	ofstream fout("output.csv");

	//ручное формирование первой строки конечной таблицы файла
	fout << "Количество элементов;Пузырек 0-9;Пузырек 0-10к;Пузырек сортированный;Пузырек обратно сортированный;Айверсон 1 0-9;Айверсон 1 0-10к;Айверсон 1 сортированный;Айверсон 1 обратно сортированный;Айверсон 2 0-9;Айверсон 2 0-10к;Айверсон 2 сортированный;Айверсон 2 обратно сортированный;Вставки 0-9;Вставки 0-10к;Вставки сортированный;Вставки обратно сортированный;Бинарные вставки 0-9;Бинарные вставки 0-10к;Бинарные вставки сортированный;Бинарные вставки обратно сортированный;" << "\n";

	//сортируемый массив, обновляемый каждую итерацию цикла for
	int* temp;

	//формирование файла с результатами измерения количества операций
	for (size_t i = 1; i <= 8; i++)
	{
		fout << i << "000 элементов в массиве;";
		for (size_t j = 0; j < 5; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				int n = i * 1000;

				temp = new int[n];//создание массива нужной длины

				for (size_t l = 0; l < n; l++)
				{
					temp[l] = array[k][l];//заполнение массива числами исходного, чтобы не сортировать главный масиив
				}

				functions[j](temp, n);//вызов функцций сортировки

				fout << operationsCount << ";";//вывод в файл результатов
			}
		}
		fout << "\n";
	}

	fout.close();

	//строки с очистками памяти закомментированы, потому что лично у меня в Visual Studio 2019 они вызывают исключение
	/*delete[] array;
	delete[] functions;
	delete[] temp;*/

	return 0;
}

#pragma region Функции_сортировок

void bubbleSort(int* array, int N)
{
	operationsCount = 3;//1 инициализация i, 2 в условии for

	for (size_t i = 0; i < N - 1; i++)
	{
		operationsCount += 6;//2 в условии for, 1 инициализация j, 3 в условии следующего for
		for (size_t j = 0; j < N - 1 - i; j++)
		{
			operationsCount += 7;// 3 в условии for, 4 в if
			if (array[j] > array[j + 1])
			{
				int a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
				operationsCount += 9;//все по выполнении условия
			}
			operationsCount += 2;//j++
		}
		operationsCount += 2;//i++
	}
}

void bubbleSortIverson1(int* array, int N)
{
	bool flag = false;
	operationsCount = 5;//1 инициализация i, 4 в условии for

	for (size_t i = 0; i < N - 1 && !flag; i++)
	{
		operationsCount += 9;//4 в условии for, 1 инициализация flag, 1 инициализация j, 3 в условии следующего for
		flag = true;
		for (size_t j = 0; j < N - 1 - i; j++)
		{
			operationsCount += 7;//3 в условии for, 4 в if
			if (array[j] > array[j + 1])
			{
				int a = array[j];
				array[j] = array[j + 1];
				array[j + 1] = a;
				flag = false;
				operationsCount += 10;//все по выполнении условия
			}
			operationsCount += 2;//j++
		}
		operationsCount += 2;//i++
	}
}

void bubbleSortIverson2(int* array, int N) 
{
	operationsCount = 2;//1 инициализация, 1 условие while 
	int t = N;
	while (t != 0)
	{
		operationsCount += 5;//1 условие while, 3 инициализации, 1 условие for

		int bound = t;
		t = 0;
		for (int i = 1; i < bound; ++i) {
			operationsCount += 5;//1 условие for, 4 условие if
			if (array[i] < array[i - 1]) {
				int a = array[i];
				array[i] = array[i + 1];
				array[i + 1] = a;
				t = i;
				operationsCount += 10;//все по выполнении условия
			}
			operationsCount += 2;//i++
		}
	}
}

void simpleInsertSort(int* array, int N)
{
	operationsCount = 2;//1 инициализация i, 1 в условии for

	for (size_t i = 1; i < N; i++)
	{
		operationsCount += 9;//1 в условии for, 4 в инициализациях, 4 в условии while

		int b = array[i];
		int j = i - 1;
		
		while (b < array[j] && j >= 0)
		{
			array[j + 1] = array[j];
			j = j - 1;
			operationsCount += 10;//4 в условии while, 6 в теле while
		}

		array[j + 1] = b;

		operationsCount += 5;//3 в инициализации, 2 i++
	}
}

void binaryInsertSort(int* array, int N)
{
	operationsCount = 2;//1 в инициализации, 1 в условии for

	for (size_t i = 1; i < N; i++)
	{
		operationsCount += 8;//1 в условии for, 6 при инициализации, 1 в условии while

		int lf = 0, rg = i - 1;
		int c = (lf + rg) / 2;

		while (lf != c) 
		{
			operationsCount += 4;//1 в условии while, 3 в условии if

			if (array[c] > array[i])
			{
				rg = c - 1;
				operationsCount += 2;//все по выполнении условия
			}
			else
			{
				lf = c;
				operationsCount += 1;//если условие не выполняется
			}
			c = (lf + rg) / 2;
			operationsCount += 2;//все при инициализации
		}

		operationsCount += 3;//все в условии if

		if (array[lf] < array[i])
		{
			operationsCount += 3;//все в условии if

			if (array[i] > array[rg])
			{
				lf = rg + 1;
				operationsCount += 2;//все по выполнении условия
			}
			else
			{
				lf = rg;
				operationsCount += 1;//если условие не выполняется
			}
		}
		int k = i;
		int p = array[i];

		operationsCount += 4;//3 при инициализации, 1 в условии while

		while (k > lf)
		{
			array[k] = array[k - 1];
			k = k - 1;

			operationsCount += 7;//1 в условии while, 6 при инициализации
		}

		array[lf] = p;

		operationsCount += 4;//2 при инициализации, 2 i++
	}
}
#pragma endregion