#include "structs/vector3.h"
#include <math.h>

#define RAD2DEG( x  )  ( (float)(x) * (float)(180.f / M_PI) )
#define M_PI   3.14159265358979323846f

namespace Maths {
	extern void Normalize(vector3& angle);
	extern void ClampAngles(vector3& angles);
	extern bool Clamp(vector3& angles);
	extern void AngleVectors(const vector3& angles, vector3* forward);
	extern float GetFov(const vector3& viewAngle, const vector3& aimAngle);
	extern vector3 CalcAngle(vector3 src, vector3 dst);
}