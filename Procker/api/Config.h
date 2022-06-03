#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

/*
	Config loader system
	Version: 0.0.1 Early Alpha
*/

class Config {
public:
	Config(string);
	~Config();

	// AutoBH variables
	bool BHop_Enabled;
	DWORD BHop_Button;
	int BHop_Interval;

};