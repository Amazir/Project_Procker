#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "structs/glow_t.h"

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

	// GlowESP
	bool GE_Enabled;
	DWORD GE_Button;
	bool GE_Allies;
	glow_t GE_CAllies;
	glow_t GE_CEnemies;

};