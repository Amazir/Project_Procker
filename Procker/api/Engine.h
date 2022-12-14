#include "LocalPlayer.h"
#include "Config.h"
#include <assert.h>
#include <thread>
#include <iostream>

using namespace std;

class Engine {
public:
	Engine();
	~Engine();

	void Alert(int, string);
	void Threads();
	void Thread_Misc();
	void Thread_Trigger();
	void Thread_Visuals();
private:
	ProcMem* mem;
	Config* conf;
};