#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

class Config {
public:
	Config(string);
	~Config();

	// AutoBH variables
	bool BHop_Enabled;
	DWORD BHop_Button;
	int BHop_Interval;

	// Triggerbot variables
	bool TB_Enabled;
	DWORD TB_Button;
	int TB_Interval;

};