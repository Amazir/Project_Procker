#include "libs/ProcMem.h"
#include "Config.h"
#include <assert.h>
#include <thread>
#include <iostream>

using namespace std;

/*
	Early engine of whole cheat
	Version: 0.0.1 Early Alpha
*/

class Engine {
public:
	Engine();
	~Engine();

	void Alert(int, string);
	void Threads();
	void Thread_Misc();
private:
	ProcMem* mem;
	Config* conf;
};