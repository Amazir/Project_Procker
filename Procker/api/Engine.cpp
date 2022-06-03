#include "Engine.h"

Engine::Engine() {
	// Getting into process
	Alert(0, "Loading into CS:GO");
	mem = new ProcMem(); 
	mem->Process("csgo.exe");

	// Getting modules
	Alert(0, "Getting modules");
	mem->Module("client.dll");

	// Starting threads
	Threads();
}

void Engine::Alert(int type, string msg) {
	/*
		This function is printing out informations from
		every module of this cheat.
	*/
	switch (type) {
	case 0:
		cout << "[CORE] " << msg << endl;
		break;
	}
}

void Engine::Threads() {
	// Creating thread for miscellaneous cheats
	thread miscThread(&Engine::Thread_Misc, this);
	miscThread.detach();
	assert(!miscThread.joinable());
}

void Engine::Thread_Misc() {
	while (1) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			DWORD dwLocalPlayer = 
				mem->Read<DWORD>(mem->dwClientAddress + Offsets::dwLocalPlayer);

			if (mem->Read<int>(dwLocalPlayer + Offsets::m_fFlags) == 257) {
				mem->Write(mem->dwClientAddress + Offsets::dwForceJump, 6);
				Sleep(30);
			}
		}
		Sleep(1);
	}
}