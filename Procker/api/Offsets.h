#pragma once
#include "Windows.h"
//#include "../engine/maths.h"

namespace Offsets {
	extern DWORD dwLocalPlayer;
	extern DWORD dwForceJump;
	extern DWORD dwForceAttack;
	extern DWORD dwEntityList;
	extern DWORD dwGlowObjectManager;
	extern DWORD m_iTeamNum;
	extern DWORD m_iHealth;
	extern DWORD m_iCrosshairId;
	extern DWORD m_iGlowIndex;
	extern DWORD m_fFlags;
	extern DWORD m_bDormant;
	extern DWORD m_bSpotted;
	// AimBot
	extern DWORD m_vecOrigin;
	extern DWORD m_vecViewOffset;
	extern DWORD m_dwBoneMatrix;
	extern DWORD dwClientState;
	extern DWORD dwClientState_ViewAngles;
	// RCS
	extern DWORD m_iShotsFired;
	extern DWORD m_aimPunchAngle;
}