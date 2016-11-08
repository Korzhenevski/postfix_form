#include"Header.h"

int main()
{
	HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (hCon != INVALID_HANDLE_VALUE) {
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = 14;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = 400;
		wcscpy_s(cfi.FaceName, L"Lucida Console");
		SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
	}
	setlocale(LC_ALL, "ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Дана програма обраховує значення введеного виразу.\nВведіть вираз: ";
	string exp;
	int num = 0;
	cin >> exp;
	exp = postfix(exp, num);
	string letters = "";
	if (exp != "")
	{

		for (int i = 0; i < exp.length(); i++)
		{
			if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z')
				letters += tolower(exp[i]);
		}
		cout << "Введіть значення параметрів:\n";
		float* arr = new float[num];
		for (int i = 0; i < num; i++)
		{
			switch (letters[i])
			{
			case 'a': cout << "A="; break;
			case 'b': cout << "B="; break;
			case 'c': cout << "C="; break;
			case 'd': cout << "D="; break;
			case 'e': cout << "E="; break;
			case 'f': cout << "F="; break;
			case 'g': cout << "G="; break;
			case 'h': cout << "H="; break;
			case 'i': cout << "I="; break;
			case 'j': cout << "J="; break;
			case 'k': cout << "K="; break;
			case 'l': cout << "L="; break;
			case 'm': cout << "M="; break;
			case 'n': cout << "N="; break;
			case 'o': cout << "O="; break;
			case 'p': cout << "P="; break;
			case 'q': cout << "Q="; break;
			case 'r': cout << "R="; break;
			case 's': cout << "S="; break;
			case 't': cout << "T="; break;
			case 'u': cout << "U="; break;
			case 'v': cout << "V="; break;
			case 'w': cout << "W="; break;
			case 'x': cout << "X="; break;
			case 'y': cout << "Y="; break;
			case 'z': cout << "Z="; break;
			default: break;
			}
			cin >> arr[i];
		}
		cout << "Постфіксна форма виразу: " << exp << endl;
		postfix_count(exp, arr, letters);
		delete[] arr;
	}
	cout << "Сеанс завершено. Для виходу натисніть ENTER.\n";
	cin.sync();
	cin.get();
	return 0;
}