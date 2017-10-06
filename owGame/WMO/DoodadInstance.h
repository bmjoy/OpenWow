#pragma once

#include "../MDX/MDX.h"

struct DoodadPlacementInfo
{
	struct
	{
		uint32 nameIndex : 24;          // reference offset into MODN
		uint32 flag_AcceptProjTex : 1;
		uint32 flag_0x2 : 1;            // MapStaticEntity::field_34 |= 1 (if set, MapStaticEntity::AdjustLighting is _not_ called)
		uint32 flag_0x4 : 1;
		uint32 flag_0x8 : 1;
		 uint32 : 4;                     // unused as of 7.0.1.20994
	} flags;

	vec3 position;               // (X,Z,-Y)
	C4ImQuaternion orientation;        // (X, Y, Z, W)
	float scale;                      // scale factor
	CImVector color;                 // (B,G,R,A) diffuse lighting color, used in place of global diffuse from DBCs

	//
	static const uint32 __size = 40;
};

#include "../SceneNode.h"

class DoodadInstance : protected SceneNode
{
public:
	DoodadInstance(File& f);
	~DoodadInstance();

	void SetModel(MDX* m);
	MDX* GetMDX() { return modelObject; }

	void Draw();

private:
	void CalculateMatrix();

public:
	MDX* modelObject;
	DoodadPlacementInfo* placementInfo;

	int light;
	vec3 ldir;
	vec4 lcol;
};