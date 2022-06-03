#include "libs/ProcMem.h"
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
private:
	ProcMem* mem;
};