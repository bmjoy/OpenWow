#pragma once

#include "Liquid.h"

class Liquid_Instance : public SceneNode
{
public:
	Liquid_Instance(std::weak_ptr<SceneNode> _parent, Liquid* _liquidObject, vec3 _position);
	virtual ~Liquid_Instance() {};

private:
	CGroupQuality&		m_QualitySettings;
};