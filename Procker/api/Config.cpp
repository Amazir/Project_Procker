#include "Config.h"
#include <vector>

// Function for splitting text by a char
vector<string> split(string str, string sep) {
	char* cstr = const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}

void log(string m) {
	cout << "[CONFIG LOADER] " << m << endl;
}

Config::Config(string filePath) {
	ifstream cfgFile(filePath);
	if (cfgFile.good()) {
		string full_line;
		int i = 1;
		while (getline(cfgFile, full_line)) {
			vector<string> line = split(full_line, ":");
			switch (i) {
					/*
						********************************************************
						********************* BHOP CONFIG **********************
						********************************************************
					*/
				case 2:
					// Checking if BHop is enabled in config file
					BHop_Enabled = stoi(line[1]);
					if (BHop_Enabled)
						log("AutoBH is enabled");
					else
						log("AutoBH is disabled");
					break;
				case 3:
					// Checking key
					BHop_Button = strtol(line[1].c_str(), 0, 0);
					// TODO
					log("AutoBH key set for: ");
					break;
				case 4:
					// Checking interval
					BHop_Interval = stoi(line[1]);
					//string s = ""+BHop_Interval;
					// TODO
					//log("AutoBH interval set for: " + s);
					break;

					/*
						********************************************************
						******************* TRIGGERBOT CONFIG ******************
						********************************************************
					*/
				case 7:
					TB_Enabled = stoi(line[1]);
					if (TB_Enabled)
						log("TriggerBot is enabled");
					else
						log("TriggerBot is disabled");
					break;
				case 8:
					// Checking key
					TB_Button = strtol(line[1].c_str(), 0, 0);
					// TODO
					log("TB_Button key set for: ");
					break;
				case 9:
					// Checking interval
					TB_Interval = stoi(line[1]);
					break;
			}
			i++;
		}
	}
}