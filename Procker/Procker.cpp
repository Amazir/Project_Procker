#include <iostream>
#include "api/Engine.h"

using namespace std;

/*
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%%%%%% P R O C K E R | Professional Counter-Strike: Global Offensive cheats %%%%%%%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Version: 0.0.3 (Early Alpha build)
	Author: AmaziR
	Date of update: 18.12.2022
*/

int main(int argc, char** argv)
{
    Engine * engine = new Engine();

    while (1) {
       // DWORD dwLocalPlayer = mem->dwClientAddress;
       // if(mem->Read(mem->dwClientAddress + 0x0) == 257)
		this_thread::sleep_for(10ms);
    }

    return EXIT_SUCCESS;
}
