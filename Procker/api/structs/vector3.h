#pragma once

struct vector3
{
	float x;
	float y;
	float z;

	vector3(float x = 0, float y = 0, float z = 0)
		: x(x), y(y), z(z) {}

	vector3 operator+(const vector3& other) {
		float resX = x + other.x, resY = y + other.y, resZ = z + other.z;
		return vector3(resX, resY, resZ);
	}

	vector3 operator-(const vector3& other) {
		float resX = x - other.x, resY = y - other.y, resZ = z - other.z;
		return vector3(resX, resY, resZ);
	}

	vector3 operator/(const float& factor) {
		if (factor == 0)
			return vector3(x, y, z);
		float resX = x / factor, resY = y / factor, resZ = z / factor;
		return vector3(resX, resY, resZ);
	}

	float vector3::Dot(const vector3& b) const {
		return (x * b.x + y * b.y + z * b.z);
	}

	float LengthSqr(void) const {
		return (x * x + y * y + z * z);
	}

	bool IsEmpty() {
		return x == 0 && y == 0 && z == 0;
	}
};