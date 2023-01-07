#include "LocalPlayer.h"
#include "Config.h"
#include <assert.h>
#include <thread>
#include <iostream>

using namespace std;

class Engine {
public:
	Engine(string);
	~Engine();

	void Alert(int, string);
	void Threads();
	void Thread_Misc();
	void Thread_Trigger();
	void Thread_Visuals();
	void Thread_Aimbot();
	
private:
	ProcMem* mem;
	Config* conf;
};