#include "LocalPlayer.h"

LocalPlayer::~LocalPlayer() {
}

int LocalPlayer::getGlowBase() {
	return mem->Read<int>(mem->dwClientAddress + Offsets::dwGlowObjectManager);
}

int LocalPlayer::getShotsFired() {
	return mem->Read<int>(withClient + Offsets::m_iShotsFired);
}

void LocalPlayer::jump() {
	mem->Write<int>(mem->dwClientAddress + Offsets::dwForceJump, 6);
}

void LocalPlayer::shoot() {
	mem->Write<int>(mem->dwClientAddress + Offsets::dwForceAttack, 6);
}

bool LocalPlayer::isGoodTarget(Entity*en) {
	if (getTeam() != en->getTeam() && en->isPlayer())
		return true;
	return false;
}

Entity* LocalPlayer::inCrosshair() {
	// Get object of entity in local player's crosshair
	Entity* n = new Entity(mem, Offsets::dwEntityList + ((mem->Read<int>(withClient + Offsets::m_iCrosshairId) - 1) * 0x10));
	// Check if this enemy alive
	if (n->isAlive())
		// If yes return object of it
		return n;
	// Else return NULL as an empty object
	return NULL;
}

void LocalPlayer::setViewAngles(vector3 angles) {
	DWORD clientState = mem->Read<DWORD>(mem->dwEngineAddress + Offsets::dwClientState);
	mem->Write<vector3>(clientState + Offsets::dwClientState_ViewAngles, angles);
}

void LocalPlayer::aimAt(Entity* enm, float smooth) {
	vector3 enemyBonePosition = enm->getBonePosition(8);
	vector3 angle = Maths::CalcAngle(getEyePosition(), enemyBonePosition);

	if (!angle.IsEmpty()) {
		//std::cout << "b:"<< angle.x << std::endl;
		Maths::Clamp(angle);
		//std::cout << "a:"<< angle.x << std::endl;
		vector3 delta = getViewAngles() - angle;
		Maths::Clamp(delta);
		vector3 newViewAngles = getViewAngles() - delta / smooth;
		if (Maths::Clamp(newViewAngles))
			setViewAngles(newViewAngles);
	}
}

Entity* LocalPlayer::getClosestEnemy(int bone, float fov) {
	bestEnemy = new Entity(mem, 0);
	float bestFov = 90.0f;

	for (int i = 0; i <= 64; i++) {
		enemy = new Entity(mem, Offsets::dwEntityList + ((i - 1) * 0x10));

		if (!enemy->isAlive()) {
			delete enemy;
			continue;
		}

		if (enemy->getTeam() == getTeam()) {
			delete enemy;
			continue;
		}

		if (enemy->isDormant()) {
			delete enemy;
			continue;
		}

		if (address == enemy->getAddress()) {
			delete enemy;
			continue;
		}

		vector3 enemyHeadPosition = enemy->getBonePosition(bone);

		if (enemyHeadPosition.IsEmpty()) {
			delete enemy;
			continue;
		}

		vector3 aimAngle = Maths::CalcAngle(getEyePosition(), enemyHeadPosition);
		float fov = Maths::GetFov(getViewAngles(), aimAngle);

		if (fov < bestFov) {
			bestEnemy = enemy;
			bestFov = fov;
		}
		
		//free(enemy);
	}
	//delete enemy;
	return bestEnemy;
}

vector3 LocalPlayer::getEyePosition() {
	vector3 origin = mem->Read<vector3>(withClient + Offsets::m_vecOrigin);
	vector3 target = origin + mem->Read<vector3>(withClient + Offsets::m_vecViewOffset);
	return target;
}

vector3 LocalPlayer::getViewAngles() {
	DWORD clientState = mem->Read<DWORD>(mem->dwEngineAddress + Offsets::dwClientState);
	return mem->Read<vector3>(clientState + Offsets::dwClientState_ViewAngles);
}

vector3 LocalPlayer::getPunchAngle() {
	return mem->Read<vector3>(withClient + Offsets::m_aimPunchAngle);
}