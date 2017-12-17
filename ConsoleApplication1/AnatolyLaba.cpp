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

	vector<int> A;  //������
	char switch_on;
	bool flag = true;
	int n;

	string F[6] = { "+ - ����� ��������� �������",
				   "* - ������������ ��������� �������",
				   "m - ����� ������������ � ������������� �������� �������",
				   "d - �������� �������� � ������� M �� �������",
				   "s - �������������� ��������� ������� ������� ��������",
				   "q - ����� �� ���������" }; //������ ��� �������� ������ ��������� ��������

	printf("���������� �������\n"); //���������� �������
	for (int i = 0; i < 5; i++)
	{
		printf("����� ������� %i\n", (i + 1));
		cin >> n;
		A.push_back(n);
	}

	cout << '\n';

	while (flag == true)
	{
		printf("������ �������� �� ������ ����:\n");
		for (int i = 0; i < 6; i++)
		{
			cout << F[i] << '\n';
		}
		printf("\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case '+': //��������
		{
			int summ = 0;
			for (int i = 0; i < A.size(); i++)
			{
				summ += A[i];
			}
			printf("�����: %i\n\n", summ);
			break;
		}
		case '*': //���������
		{
			int comp = 1;
			for (int i = 0; i < A.size(); i++)
			{
				comp *= A[i];
			}
			printf("������������: %i\n\n", comp);
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
			printf("����������� �������: %i. ������������ �������: %i\n\n", min, max);
			break;
		}
		case 'd': //��������
		{
			printf("����� ����� �������� M ��� ��������\n");
			cin >> n;
			A.erase(A.begin() + n - 1);
			printf("���������� ������:\n");
			for (int i = 0; i < A.size(); i++)
			{
				printf("������� %i: %i\n", (i + 1), A[i]);
			}
			cout << '\n';
			break;
		}
		case 's': //����������
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
			printf("��������������� ������:\n");
			for (int i = 0; i < A.size(); i++)
			{
				printf("������� %i: %i\n", (i + 1), A[i]);
			}
			cout << '\n';
			break;
		}
		case 'q': //�����
		{
			return 0;
		}
		default:
			printf("�������� ����!\n\n");
		}
	}
	return 0;
}