#include <bits/stdc.h>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
using namespace std;
using namespace std::chrono;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define width 26
#define height 24
void MenuTetris()
{
	_setmode(_fileno(stdout),_O_U16TEXT);
	wprintf(L"\n ▀▀█▀▀ ▒█▀▀▀ ▀▀█▀▀ ▒█▀▀█ ▀█▀ ▒█▀▀▀█\n ░▒█░░ ▒█▀▀▀ ░▒█░░ ▒█▄▄▀ ▒█░ ░▀▀▀▄▄\n ░▒█░░ ▒█▄▄▄ ░▒█░░ ▒█░▒█ ▄█▄ ▒█▄▄▄█\n\n ");

	_setmode(_fileno(stdout), _O_TEXT);
}
int main()
{

	int c = 0;
	int choice = 0;
	bool exit = false;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	while (!exit)
	{
		
		steady_clock::time_point t1 = steady_clock::now();
		steady_clock::time_point t2 = steady_clock::now();
		duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
		MenuTetris();
		if (choice)
		{
			cout << setw(12) << "  " << "S T A R T" << "  " << endl;
			cout << setw(13) << "<<" << "E X I T" << ">>" << endl;
		}
		if (!choice)
		{
			cout << setw(12) << "<<" << "S T A R T" << ">>" << endl;
			cout << setw(13) << "  " << "E X I T" << "  " << endl;
		}
		while (time_span.count() < .5) {
			t2 = steady_clock::now();
			time_span = duration_cast<duration<double> >(t2 - t1);
			if (_kbhit())
			{
				c = _getch();
				if (c == UP || c == DOWN)
				{
					choice = (choice + 1) % 2;
					SetConsoleCursorPosition(console, { 0, 0 });
					MenuTetris();
					if (choice)
					{
						cout << setw(12) << "  " << "S T A R T" << "  " << endl;
						cout << setw(13) << "<<" << "E X I T" << ">>" << endl;
					}
					if (!choice)
					{
						cout << setw(12) << "<<" << "S T A R T" << ">>" << endl;
						cout << setw(13) << "  " << "E X I T" << "  " << endl;
					}
				}
				if (GetKeyState(VK_SPACE) & 0x8000)
				{
					exit = true;
					break;
				}
			}
		}
		SetConsoleCursorPosition(console, { 0, 0 });
		MenuTetris();
		cout << setw(12) << "  " << "S T A R T" << "  " << endl;
		cout << setw(13) << "  " << "E X I T" << "  " << endl;
		t1 = steady_clock::now();
		t2 = steady_clock::now();
		time_span = duration_cast<duration<double> >(t2 - t1);
		while (time_span.count() < .5) {
			t2 = steady_clock::now();
			time_span = duration_cast<duration<double> >(t2 - t1);
			if (GetKeyState(VK_UP) & 0x8000 || GetKeyState(VK_DOWN) & 0x8000)
			{
				break;
			}
			if (GetKeyState(VK_SPACE) & 0x8000)
			{
				exit = true;
				break;
			}
	

		}
		SetConsoleCursorPosition(console, { 0, 0 });
	}
	if (!choice)
	{
		system("cls");
		steady_clock::time_point s = steady_clock::now();
		for (size_t i = 0; i < 20; i++) {
			steady_clock::time_point t1 = steady_clock::now();
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
			if (i <= 18) {
				int j = 0;
				for (j; j < i; j++) {
					cout << "|| .. .. .. .. .. .. .. ||\n";
				}
				cout << "|| .. .. .. [] .. .. .. ||\n|| .. .. [] [] [] .. .. ||\n";

				for (size_t z = 18 - i; z > 0; z--) {
					cout << "|| .. .. .. .. .. .. .. ||\n";
				}
				cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^\n==== S C O R E :" << setw(5) << "0";
				cout << " ====\n^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
				while (time_span.count() < .5) {
					t2 = steady_clock::now();
					time_span = duration_cast<duration<double> >(t2 - t1);
				}
				if (i < 18) SetConsoleCursorPosition(console, { 0, 0 });
			}

		}
		steady_clock::time_point e = steady_clock::now();
		duration<double>  final = duration_cast<duration<double> >(e - s);

	}
	


	return 0;
}
