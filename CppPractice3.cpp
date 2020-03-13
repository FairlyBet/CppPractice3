#include <iostream>
#include <ctype.h>
//#include <windows.h>

void LowLevelTask()
{
	using namespace std;
	char SymArr[16] = {}, AddArr[50] = {};
	unsigned short AmountOfVowels = 0;

	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(SymArr, 16);

	//CharToOemA(SymArr, AddArr);

	_strlwr_s(SymArr);

	for (size_t i = 0; i < 16; i++)
	{
		switch (SymArr[i])
		{
			case 'у':
			case 'е':
			case 'э':
			case 'о':
			case 'а':
			case 'ы':
			case 'я':
			case 'и':
			case 'ю':
			{
				AmountOfVowels++;
				break; 
			}
		}
	}
	system("cls");
	cout << "Text: "<< SymArr << endl << "Amount of russian vowels is " << AmountOfVowels << endl << endl;
}

void MediumLevelTask()
{
	using namespace std;
	char Text[21] = {};
	unsigned short StartPoint = 0, LetterCounter = 1;

	cout << "Put there some text, ending with a dot" << endl;

	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Text, 21, '.');

	system("cls");
	cout << "Text: " << Text << endl;
	cout << "Three-letter words:" << endl;

	for (size_t i = 0; i < 21; i++)
	{
		if (isalpha(Text[i]))
		{
			StartPoint = i;

			while (isalpha(Text[++i]) && LetterCounter++);

			if (LetterCounter == 3)
			{
				for (size_t j = StartPoint; j < i; j++)
				{
					cout << Text[j];
				}
				cout << endl;
			}
			LetterCounter = 1;
		}
	}
	cout << endl;
}

void HighLevelTask()
{
	using namespace std;
	char Text[21] = {};
	unsigned short counter = 0, ComparisonNumber = 0;

	cout << "Put there some text" << endl;

	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(Text, 21);

	system("cls");
	cout << "Text: " << Text << endl;
	cout << "Words with same first and last letter" << endl;

	for (size_t i = 0; i < 21; i++)
	{		
		if (isalpha(Text[i]))
		{
			ComparisonNumber = i;

			counter = 1;

			while (isalpha(Text[++i]) && counter++);
				
			if (counter > 1)
			{
				if (Text[i - 1] == Text[ComparisonNumber])
				{
					for (size_t j = ComparisonNumber; j < i; j++)
					{
						cout << Text[j];
					}
					cout << endl;
				}
			}
		}
	}
	cout << endl;
}

int main()
{
	using namespace std;
	unsigned short choice = 0;

	while (true)
	{
		cout << "Choose the task: 1)low level(doesn't work) 2)medium level 3)high level 0)Close program" << endl;

		while (!(cin >> choice))
		{
			cout << "Wrong input!" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		switch (choice)
		{
		case 1:
			LowLevelTask();
			break;
		case 2:
			MediumLevelTask();
			break;
		case 3:
			HighLevelTask();
			break;
		case 0:
			return 0;
		}
	}
}