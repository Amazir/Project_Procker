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
	thread visualsThread(&Engine::Thread_Visuals, this);
	visualsThread.detach();
	assert(!visualsThread.joinable());
}

void Engine::Thread_Visuals() {
	/*
		********************************************************
		************************ VISUALS ***********************
		********************************************************
	*/
	while (1) {
		// TODO:: MORE FUNCTIONS ENABLE CHECK!!
		if (!conf->GE_Enabled && (conf->GE_Button || !(GetAsyncKeyState(conf->GE_Button) & 0x8000)))
			continue;
			
		// Get local player's object
		LocalPlayer* lp = new LocalPlayer(mem, Offsets::dwLocalPlayer);
		// Get glow base
		int glowBase = lp->getGlowBase();

		// Loop for all entities in the game
		for (int i = 0; i <= 64; i++) {
			// Get object of analised entity
			Entity* enm = new Entity(mem, Offsets::dwEntityList + ((i - 1) * 0x10));

			// Check is entity alive
			if (!enm->isAlive()) {
				delete(enm);
				continue;
			}

			// If allie glowing is disabled, exit loop
			if (!conf->GE_Allies)
				if (!lp->isGoodTarget(enm)) {
					delete(enm);
					continue;
				}
				
			if (conf->RA_Enabled)
				enm->setSpotted();

			// If glow disabled exit loop
			if (!conf->GE_Enabled) {
				delete(enm);
				continue;
			}

			// Get glow index and base adress of glow struct
			int glowIndex = enm->getGlowIndex();
			DWORD glow_addr = (glowBase + glowIndex * 0x38) + 0x4;

			// Create glow struct object and fill it with data from config file
			glow_t glowt;
			glowt = mem->Read<glow_t>(glow_addr);
			glowt.r = lp->getTeam() == enm->getTeam() ? conf->GE_CAllies.r : conf->GE_CEnemies.r;
			glowt.g = lp->getTeam() == enm->getTeam() ? conf->GE_CAllies.g : conf->GE_CEnemies.g;
			glowt.b = lp->getTeam() == enm->getTeam() ? conf->GE_CAllies.b : conf->GE_CEnemies.b;
			glowt.a = lp->getTeam() == enm->getTeam() ? conf->GE_CAllies.a : conf->GE_CEnemies.a;
			glowt.m_bRenderWhenOccluded = true;
			glowt.m_bRenderWhenUnoccluded = false;

			// Rewrite glow_t object into game process
			mem->Write<glow_t>(glow_addr, glowt);

			delete(enm);
		}
		delete (lp);
		this_thread::sleep_for(chrono::milliseconds((int)5));
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

			delete(lp);
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

		if (!en) {
			delete(lp);
			delete(en);
			continue;
		}

		if (!lp->isGoodTarget(en)) {
			delete(lp);
			delete(en);
			continue;
		}

		lp->shoot();

		delete(lp);
		delete(en);

		this_thread::sleep_for(chrono::milliseconds((int)10));
	}
}