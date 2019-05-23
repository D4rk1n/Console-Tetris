#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
	steady_clock::time_point s = steady_clock::now();
	for (size_t i = 0; i < 20; i++) {
		steady_clock::time_point t1 = steady_clock::now();
		steady_clock::time_point t2 = steady_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		if (i <= 18) {
			int j = 0;
			for (j; j < i; j++) {
				cout << "|| .. .. .. .. .. .. .. ||\n";
			}
			cout << "|| .. .. .. [] .. .. .. ||\n|| .. .. [] [] [] .. .. ||\n";

			for (size_t z = 18 - i; z > 0; z--) {
				cout << "|| .. .. .. .. .. .. .. ||\n";
			}
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^\n==== S C O R E : 0000 ====\n^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			while (time_span.count() < .5) {
				t2 = steady_clock::now();
				time_span = duration_cast<duration<double>>(t2 - t1);
			}
			if (i < 18) system("cls");
		}

	}
	steady_clock::time_point e = steady_clock::now();
	duration<double>  final = duration_cast<duration<double>>(e - s);




	return 0;
}
