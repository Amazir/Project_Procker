#include <iostream>
#include "api/Engine.h"
#include "api/libs/HttpClient.h"

using namespace std;

/*
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%%%%%% P R O C K E R | Professional Counter-Strike: Global Offensive cheats %%%%%%%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Version: 0.2 (Early Alpha build)
	Author: AmaziR
	Date of update: 07.01.2023
*/

bool dev_mode = false;

void error(int code) {
	if (!dev_mode) {
		switch (code) {
		case 0:
			cout << "[LICENSE] You have error with your license. Check if it is expired." << endl;
			break;
		case 1:
			cout << "[LICENSE] You must launch Procker by launcher." << endl;
			break;
		}
		Sleep(5000);
	}
}

bool auth(string hwid) {
	httpRequest r;
	r.setHost("164.92.137.22");
	r.setUri("/verify.php/?t=1&h=" + hwid);
	r.addHeader("Connection: close");
	r.buildRequest();
	httpClient* cl = new httpClient();
	cl->sendRequest(r);
	if (cl->getResponse().at(166) == 'y')
		return true;
	error(0);
	return false;
}

int main(int argc, char** argv)
{
	if (!(argc > 1) && !dev_mode) {
		error(1);
		return EXIT_SUCCESS;
	}

	if (auth(argv[1]) || dev_mode) {
		string config;
		if (dev_mode)
			config = "main.cfg";
		else
			config = argv[2];

		Engine* engine = new Engine(config);

		while (1) {
			this_thread::sleep_for(1000ms);
		}
	}

    return EXIT_SUCCESS;
}
