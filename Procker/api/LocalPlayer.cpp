#include "LocalPlayer.h"

LocalPlayer::~LocalPlayer() {}

int LocalPlayer::getGlowBase() {
	return mem->Read<int>(mem->dwClientAddress + Offsets::dwGlowObjectManager);
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