#include "Engine.h"


Engine::Engine() {
	// Getting into process
	Alert(0, "Loading into CS:GO");
	mem = new ProcMem(); 
	mem->Process("csgo.exe");

	// Getting modules
	Alert(0, "Getting modules");
	mem->Module("client.dll");

	// Create config's object
	conf = new Config("data/configs/main.cfg");

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
		/*
			********************************************************
			************************** BHOP ************************
			********************************************************
		
			Check if button is pressed
		*/
		if (conf->BHop_Enabled) {
			if (!(GetAsyncKeyState(conf->BHop_Button) & 0x8000))
				continue;
			// Get local player object
			DWORD dwLocalPlayer =
				mem->Read<DWORD>(mem->dwClientAddress + Offsets::dwLocalPlayer);

			// Check is player on the floor
			if (mem->Read<int>(dwLocalPlayer + Offsets::m_fFlags) == 257) {
				// If player is grounded then force jump
				mem->Write(mem->dwClientAddress + Offsets::dwForceJump, 6);
				// Sleep for optimization
				this_thread::sleep_for(1ms);
			}
		}

		// Sleep for optimization
		this_thread::sleep_for(1ms);
	}
}