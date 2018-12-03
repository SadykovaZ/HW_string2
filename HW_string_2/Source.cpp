#include<string>
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>
#include<iterator>
#include<algorithm>
#include <sstream>
#include<iomanip>
using namespace std;

bool isNeededChar(char c) {
	switch (c) {
	case '.':
	case '!':
	case '?':
		return true;
	default:
		return false;
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int ch = 0;
	while (ch != 3)
	{
		cout << "Enter number of the task: (3 - exit) ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "������� ��������� ���� � ���������� ���������� �� ������: " << endl;
			cout << "- ���������� �����������\n- ���������� ����\n- ������� ����� �����\n- ������� ���������� ���� � �����������\n";
			cout << endl;

			ifstream file;
			file.open("new.txt");
			string line;
			int sentenceCounter = 0;
			int wordCnt = 0, letterSum=0;		

			while (getline(file, line))
			{
				cout << line << endl;
				for (int i = 0; i < line.length(); i++)
				{
					if (isNeededChar(line.at(i)))
					{
						if (!isNeededChar(line.at(i - 1))) {
							sentenceCounter++;
						}
					}
				}

				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ' ')
					{
						++wordCnt;
						
						do
							++i;

						while (i < line.length() && line[i] == ' ');

					}
				}
				if (line[line.length() - 1] != ' ')
				{
					++wordCnt;
				}

				int numofChars = line.length();
				for (unsigned int n = 0; n < line.length(); n++)
				{
					if (line.at(n) == ' ')
					{
						numofChars--;
					}
					if (isNeededChar(line.at(n)))
					{
						if (!isNeededChar(line.at(n - 1))) {
							numofChars--;
						}
					}
				}
				letterSum = numofChars + letterSum;				
			}
			
			cout << "���������� �����������: " << sentenceCounter << endl;
			cout << "���������� ����: " << wordCnt << endl;
			cout << "���������� ����: " << letterSum << endl;
			cout << "C������ ����� ����� " << (double)letterSum/wordCnt << endl;
			cout << "C������ ���������� ���� � ����������� " << (double)wordCnt / sentenceCounter << endl;
			cout << "-----------------------------------------------\n";			
			file.close();					
		}
		break;
		case 2:
		{
			cout << "������� ��������� ��������� ����, ������� ��� ���������� �� �����.  ��������� � ������������ ����� ����� �� ����� ��������, ����� ����� ������������ � �������� ������.��������� ������ �� ����� ������ � ������� ��������� �� �����. " << endl;
			ifstream file;
			file.open("new.txt");
			string line;
			string wordToReplace;
			string wordToReplaceWith;


			while (getline(file, line))
			{
				cout << line << endl;
				cout << "Enter word to replace: ";
				cin >> wordToReplace;
				cout << "Enter word to replace with: ";
				cin >> wordToReplaceWith;
				size_t len = wordToReplace.length();
				size_t pos = line.find(wordToReplace);
				if (pos != string::npos)
					line.replace(pos, len, wordToReplaceWith);
				else
					break;
				cout << line << '\n';
			}
			file.close();
		}
		break;
		default:
			
			break;
		}

	}
	system("pause");
}