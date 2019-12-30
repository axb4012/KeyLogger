#pragma once

class Saver {
public:

	Saver(const char* filename);
	~Saver();
	int Save(int& _key);


private:

	const char* BKSP = "BKSP";
	const char* ENTR = "\n";
	const char* SHFT = "SHFT";
	const char* ESCP = "ESCP";

	FILE* file;

	bool write_to_file(char* str);


};