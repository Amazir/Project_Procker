#include "maths.h"

namespace Maths {
	void Normalize(vector3& angle) {
		while (angle.x > 89.0f) {
			angle.x -= 180.f;
		}
		while (angle.x < -89.0f) {
			angle.x += 180.f;
		}
		while (angle.y > 180.f) {
			angle.y -= 360.f;
		}
		while (angle.y < -180.f) {
			angle.y += 360.f;
		}
	}
	void ClampAngles(vector3& angles) {
		if (angles.y > 180.0f)
			angles.y = 180.0f;
		else if (angles.y < -180.0f)
			angles.y = -180.0f;

		if (angles.x > 89.0f)
			angles.x = 89.0f;
		else if (angles.x < -89.0f)
			angles.x = -89.0f;

		angles.z = 0;
	}
	bool Clamp(vector3& angles) {
		vector3 a = angles;
		Normalize(a);
		ClampAngles(a);

		if (isnan(a.x) || isinf(a.x) ||
			isnan(a.y) || isinf(a.y) ||
			isnan(a.z) || isinf(a.z)) {
			return false;
		}
		else {
			angles = a;
			return true;
		}
	}
	void AngleVectors(const vector3& angles, vector3* forward) {
		float    sp, sy, cp, cy;
		sy = sin(angles.y * 4.0 * atan(1.0) / 180.0);
		cy = cos(angles.y * 4.0 * atan(1.0) / 180.0);
		sp = sin(angles.x * 4.0 * atan(1.0) / 180.0);
		cp = cos(angles.x * 4.0 * atan(1.0) / 180.0);
		forward->x = cp * cy;
		forward->y = cp * sy;
		forward->z = -sp;
	}
	float GetFov(const vector3& viewAngle, const vector3& aimAngle) {
		vector3 ang, aim;
		AngleVectors(viewAngle, &aim);
		AngleVectors(aimAngle, &ang);
		return RAD2DEG(acos(aim.Dot(ang) / aim.LengthSqr()));
	}
	vector3 CalcAngle(vector3 src, vector3 dst) {
		double delta[3] = { (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
		double hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
		vector3 angles;
		angles.x = (float)(asinf(delta[2] / hyp) * 57.295779513082f);
		angles.y = (float)(atanf(delta[1] / delta[0]) * 57.295779513082f);
		angles.z = 0.0f;
		if (delta[0] >= 0.0) { angles.y += 180.0f; }
		return angles;
	}
}