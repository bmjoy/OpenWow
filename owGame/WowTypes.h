#pragma once

#include __PACK_BEGIN

struct C4Plane
{
	vec3 normal;
	float distance;
};

struct C4ImQuaternion
{
	float w;
	float x;
	float y;
	float z;
};

struct CRange
{
	float min;
	float max;
};

struct CAaBox
{
	vec3 min;
	vec3 max;
};

struct CAaSphere
{
	vec3 position;
	float radius;
};

struct CArgb
{
	CArgb() : r(0), g(0), b(0), a(0) {}
	CArgb(uint8 _r, uint8 _g, uint8 _b, uint8 _a) : r(_r), g(_g), b(_b), a(_a) {}

	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
};

struct CBgra
{
	CBgra() : b(0), g(0), r(0), a(0) {}
	CBgra(uint8 _b, uint8 _g, uint8 _r, uint8 _a) : b(_b), g(_g), r(_r), a(_a) {}

	uint8 b;
	uint8 g;
	uint8 r;
	uint8 a;
};

struct C3sVector
{
	int16 x;
	int16 y;
	int16 z;
};

struct C4Vec
{
	uint8 x;
	uint8 y;
	uint8 z;
	uint8 w;
};

struct C3Segment
{
	vec3 start;
	vec3 end;
};

struct CFacet
{
	C4Plane plane;
	vec3 vertices[3];
};

struct C3Ray
{
	vec3 origin;
	vec3 dir;
};

#include __PACK_END
