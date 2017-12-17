#include "stdafx.h"
#include <iostream>
#include "string.h"
#include <locale>
#include <Windows.h>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(866);

	vector<int> A;  //массив
	char switch_on;
	bool flag = true;
	int n;

	string F[6] = { "+ - сумма элементов массива",
				   "* - произведение элементов массива",
				   "m - поиск минимального и максимального элемента массива",
				   "d - удаление элемента с номером M из массива",
				   "s - Упорядочивание элементов массива методом пузырька",
				   "q - выйти из программы" }; //массив для удобного вывода вариантов действий

	printf("Заполнение массива\n"); //заполнение массива
	for (int i = 0; i < 5; i++)
	{
		printf("Введи элемент %i\n", (i + 1));
		cin >> n;
		A.push_back(n);
	}

	cout << '\n';

	while (flag == true)
	{
		printf("Выбери действие из списка ниже:\n");
		for (int i = 0; i < 6; i++)
		{
			cout << F[i] << '\n';
		}
		printf("\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case '+': //сложение
		{
			int summ = 0;
			for (int i = 0; i < A.size(); i++)
			{
				summ += A[i];
			}
			printf("Сумма: %i\n\n", summ);
			break;
		}
		case '*': //умножение
		{
			int comp = 1;
			for (int i = 0; i < A.size(); i++)
			{
				comp *= A[i];
			}
			printf("Произведение: %i\n\n", comp);
			break;
		}
		case 'm': //min/max
		{
			int min = A[0];
			int max = A[0];
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i] < min)
				{
					min = A[i];
				}
				if (A[i] > max)
				{
					max = A[i];
				}
			}
			printf("Минимальный элемент: %i. Максимальный элемент: %i\n\n", min, max);
			break;
		}
		case 'd': //удаление
		{
			printf("Введи номер элемента M для удаления\n");
			cin >> n;
			A.erase(A.begin() + n - 1);
			printf("Измененный массив:\n");
			for (int i = 0; i < A.size(); i++)
			{
				printf("Элемент %i: %i\n", (i + 1), A[i]);
			}
			cout << '\n';
			break;
		}
		case 's': //сортировка
		{
			bool exit = false;
			while (exit == false)
			{
				exit = true;
				for (int i = 0; i < A.size() - 1; i++)
				{
					if (A[i] > A[i + 1])
					{
						n = A[i];
						A[i] = A[i + 1];
						A[i + 1] = n;
						exit = false;
					}
				}
			}
			printf("Отсортированный массив:\n");
			for (int i = 0; i < A.size(); i++)
			{
				printf("Элемент %i: %i\n", (i + 1), A[i]);
			}
			cout << '\n';
			break;
		}
		case 'q': //выход
		{
			return 0;
		}
		default:
			printf("НЕВЕРНЫЙ ВВОД!\n\n");
		}
	}
	return 0;
}