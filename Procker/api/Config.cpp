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
	vector<string> colors;
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

					/*
						********************************************************
						******************* GLOW_ESP CONFIG ********************
						********************************************************
					*/
				case 12:
					GE_Enabled = stoi(line[1]);
					if (GE_Enabled)
						log("GlowESP is enabled");
					else
						log("GlowESP is disabled");
					break;
				case 13:
					// Checking key
					GE_Button = strtol(line[1].c_str(), 0, 0);
					if(!GE_Button)
						log("GlowESP key is disabled");
					else
						log("GlowESP key set for: ");
					// TODO
		
					break;
				case 14:
					GE_Allies = stoi(line[1]);
					if (GE_Allies)
						log("GlowESP on allies is enabled");
					else
						log("GlowESP on allies is disabled");
					break;
				/*
					COLOR:
					0 - red
					1 - green
					2 - blue
					3 - alpha
				*/
				case 15:
					// allies color
					colors = split(line[1], " ");
					GE_CAllies.r = stoi(colors[0]);
					GE_CAllies.g = stoi(colors[1]);
					GE_CAllies.b = stoi(colors[2]);
					GE_CAllies.a = stoi(colors[3]);
					log("GlowESP allies color is set: rgba(red=" + colors[0] +
						", green="+colors[1]+
						", blue="+colors[2]+
						", alpha="+colors[3]+")");
					break;

				case 16:
					// enemies color
					colors = split(line[1], " ");
					GE_CEnemies.r = stoi(colors[0]);
					GE_CEnemies.g = stoi(colors[1]);
					GE_CEnemies.b = stoi(colors[2]);
					GE_CEnemies.a = stoi(colors[3]);
					log("GlowESP enemies color is set: rgba(red=" + colors[0] +
						", green=" + colors[1] +
						", blue=" + colors[2] +
						", alpha=" + colors[3] + ")");
					break;
					/*
						********************************************************
						******************** RADAR CONFIG **********************
						********************************************************
					*/
				case 19:
					RA_Enabled = stoi(line[1]);
					if (RA_Enabled)
						log("Radar is enabled");
					else
						log("Radar is disabled");
					break;
				case 20:
					// Checking key
					RA_Button = strtol(line[1].c_str(), 0, 0);
					if (!RA_Button)
						log("Radar key is disabled");
					else
						log("Radar key set for: ");
					// TODO
					break;
			}
			i++;
		}
	}
}