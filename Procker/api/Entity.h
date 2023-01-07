#include "libs/ProcMem.h"

class Entity {
public:
	Entity(ProcMem*, DWORD);
	~Entity();

	DWORD getAddress();
	vector3 getBonePosition(int boneID);
	int getTeam(), getHealth(), getGlowIndex(), getFlags();
	bool isDormant(), isAlive(), isPlayer();
	void setSpotted();

protected:
	ProcMem * mem;
	DWORD address, withClient;
};