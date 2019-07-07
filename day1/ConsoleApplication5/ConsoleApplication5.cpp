#include <iostream>
#include <fstream>

using namespace std;

/**
 * Подсчитывает число забастовок в году с учетом выходных дней и совпадающих забастовок
 * @param daysNumber - число дней в году
 * @param partiesNumber - число партий
 * @param strikeDay - массив начальных дней забастовок каждой партии (нумерация дней забастовок с 1)
 * @param daysToNextStrike - массив, хранящий число дней, через которые происходит новая забастовка
 * strikeDay[i] и daysToNextStrike[i] представляют собой a и b для i-ой (партии нумеруются с 0)
 * партии соответственно (см. условие задачи)
 * @return - общее число забастовок в году
 */
int countStrikes(int daysNumber, int partiesNumber, int* strikeDay, int* daysToNextStrike)
{
	int res = 0;
	bool* flag = new bool[daysNumber + 1];

	for (size_t i = 0; i < daysNumber+1; i++)
	{
		flag[i] = false;
	}

	for (size_t i = 0; i < partiesNumber; i++)
	{
		for (size_t j = strikeDay[i]; j < daysNumber+1; j+=daysToNextStrike[i])
		{
			if (j % 7 != 0 && j % 7 != 6 && !flag[j]) {
				res++;
				flag[j] = true;
			}
		}
	}

	delete[] flag;
	return res;
}

int main()
{
	ifstream fin("input.txt");
	int daysNumber;
	int partiesNumber;
	fin >> daysNumber >> partiesNumber;
	int* strikeDay = new int[partiesNumber];
	int* daysToNextStrike = new int[partiesNumber];
	for (int i = 0; i < partiesNumber; ++i)
		fin >> strikeDay[i] >> daysToNextStrike[i];
	fin.close();

	int strikeDaysCount = countStrikes(daysNumber, partiesNumber, strikeDay, daysToNextStrike);

	ofstream fout("output.txt");
	fout << strikeDaysCount;
	fout.close();

	delete[] strikeDay;
	delete[] daysToNextStrike;

	return 0;
}