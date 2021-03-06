#include "stdafx.h"

// General
#include "Object.h"

// Additoonal
#include <boost/uuid/uuid_generators.hpp>

Object::Object()
	: m_UUID(boost::uuids::random_generator()())
{}

Object::Object(ConstructorType type)
{}

Object::~Object()
{}

bool Object::operator==(const Object& rhs) const
{
	return m_UUID == rhs.m_UUID;
}

boost::uuids::uuid Object::GetUUID() const
{
	return m_UUID;
}
