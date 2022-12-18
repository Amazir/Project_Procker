#include "Entity.h"

class LocalPlayer : public Entity {
public:
	LocalPlayer(ProcMem* mem, DWORD addr) : Entity(mem, addr) {}
	~LocalPlayer();
	int getGlowBase();
	void jump(), shoot();
	bool isGoodTarget(Entity*);
	Entity* inCrosshair();
};