#pragma once


struct vector3
{
	float x, y, z;

	vector3() : x(0), y(0), z(0) {};

	vector3(float _x, float _y)
		: x(_x), y(_y), z(0) {};
	vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(z) {};
};


struct Transform
{
	vector3 Position;
	vector3 Rotation;
	vector3 Scale;
};