#include "libs/ProcMem.h"

class Entity {
public:
	Entity(ProcMem*, DWORD);
	~Entity();

	int getTeam(), getHealth(), getGlowIndex(), getFlags();
	bool isDormant(), isAlive(), isPlayer();

protected:
	ProcMem * mem;
	DWORD address, withClient;
};