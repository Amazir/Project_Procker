#include "Entity.h"

Entity::Entity(ProcMem* m, DWORD adr) {
	mem = m;
	address = adr;
	withClient = mem->Read<DWORD>(mem->dwClientAddress + adr);
}

Entity::~Entity() {}

int Entity::getTeam() {
	return mem->Read<int>(withClient + Offsets::m_iTeamNum);
}

int Entity::getHealth() {
	return mem->Read<int>(withClient + Offsets::m_iHealth);
}

int Entity::getGlowIndex() {
	return mem->Read<int>(withClient + Offsets::m_iGlowIndex);
}

int Entity::getFlags() {
	return mem->Read<int>(withClient + Offsets::m_fFlags);
}

bool Entity::isDormant() {
	return mem->Read<bool>(withClient + Offsets::m_bDormant);
}

bool Entity::isPlayer() {
	if (!isDormant())
		return true;
	return false;
}

bool Entity::isAlive() {
	if (isPlayer() && getHealth() > 0)
		return true;
	return false;
}

void Entity::setSpotted() {
	mem->Write<bool>(withClient + Offsets::m_bSpotted, true);
}