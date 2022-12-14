#include "Engine.h"

Engine::Engine() {
	// Getting into process
	Alert(0, "Loading into CS:GO");
	mem = new ProcMem(); 
	mem->Process("csgo.exe");

	// Getting modules
	Alert(0, "Getting modules");
	mem->Module("client.dll");
	mem->Module("engine.dll");

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

	// Creating thread for triggerbot
	thread triggerThread(&Engine::Thread_Trigger, this);
	triggerThread.detach();
	assert(!triggerThread.joinable());

	// Creating thread for visuals
}

void Engine::Thread_Visuals() {
	while (1) {
		/*
			********************************************************
			************************** BHOP ************************
			********************************************************
		*/
	}
}

void Engine::Thread_Misc() {
	while (1) {
		/*
			********************************************************
			************************** BHOP ************************
			********************************************************
		*/
		// Check if AutoBH is enabled
		if (conf->BHop_Enabled) {
			// Check is button pressed
			if (!(GetAsyncKeyState(conf->BHop_Button) & 0x8000))
				continue;

			// Get local player's object
			LocalPlayer * lp = new LocalPlayer(mem, Offsets::dwLocalPlayer);

			// Check flags, if it's 257 then player is grounded
			if (lp->getFlags() == 257) {
				// Jump
				lp->jump();
				// Sleep for optimization
				this_thread::sleep_for(chrono::milliseconds((int)conf->BHop_Interval));
			}
		}
		// Sleep for optimization
		this_thread::sleep_for(1ms);
	}
}

void Engine::Thread_Trigger() {
	while (1) {
		/*
			********************************************************
			********************* TRIGGERBOT ***********************
			********************************************************
		*/
		
		this_thread::sleep_for(1ms);

		LocalPlayer* lp = new LocalPlayer(mem, Offsets::dwLocalPlayer);
		Entity* en = lp->inCrosshair();

		if (!en)
			continue;

		if (!lp->isGoodTarget(en))
			continue;

		lp->shoot();

		this_thread::sleep_for(chrono::milliseconds((int)10));
	}
}