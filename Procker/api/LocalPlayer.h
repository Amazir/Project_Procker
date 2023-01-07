#include "Entity.h"

class LocalPlayer : public Entity {
public:
	LocalPlayer(ProcMem* mem, DWORD addr) : Entity(mem, addr) {}
	~LocalPlayer();
	int getGlowBase(), getShotsFired();
	void jump(), shoot(), aimAt(Entity*, float), 
		setViewAngles(vector3);
	bool isGoodTarget(Entity*);
	vector3 getViewAngles(), getEyePosition(), getPunchAngle();
	Entity* getClosestEnemy(int, float);
	Entity* inCrosshair();
private:
	Entity* bestEnemy;
	Entity* enemy;
};