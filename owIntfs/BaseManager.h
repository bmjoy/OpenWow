#pragma once

// Forward
class R_Texture;
class Font;
class WMO;
class M2;

struct 
	__declspec(uuid("BDC2768B-055D-42EA-ABE3-CF17CD21178D"))
	IManager
{
	virtual ~IManager() = 0 {};
};

template<class T>
struct IRefManager : public IManager
{	
	virtual ~IRefManager() {};

	virtual shared_ptr<T> Add(cstring name) = 0;
	virtual bool Exists(cstring name) const = 0;
	virtual void Delete(cstring name) = 0;
	virtual void Delete(shared_ptr<T> item) = 0;
};


struct
	__declspec(uuid("5C02C392-FD7A-4013-AAB7-43C8E81602AB"))
	ITexturesManager : public IRefManager<R_Texture>
{
	virtual ~ITexturesManager() {};
};


struct
	__declspec(uuid("1427E242-CCB8-4AEC-ABC8-17DE58A96B05"))
	IFontsManager : public IRefManager<Font>
{
	virtual ~IFontsManager() {};

	virtual shared_ptr<Font> GetMainFont() const = 0;
};


struct 
	__declspec(uuid("42D47100-B825-47F1-BE2F-6F7C78443884"))
	IWMOManager : public IRefManager<WMO>
{
	virtual ~IWMOManager() {};
};

struct
	__declspec(uuid("B14D922C-BE9E-44CA-9448-5400E3CB573A"))
	IM2Manager : public IRefManager<M2>
{
	virtual ~IM2Manager() {};
};

//--

enum SBaseManagerPhases : uint8
{
	Phase_Input = 0,
	Phase_Update,
	Phase_Pre3D,
	Phase_3D,
	Phase_Post3D,
	Phase_UI,
	Phase_NONE
};

__interface 
	__declspec(uuid("BB9FD479-C7AD-4F57-837B-E299A04AF171"))
	IBaseManager
{
	void RegisterManager(GUID _type, IManager* _manager);
	void UnregisterManager(GUID _type);

	IManager* GetManager(GUID _type);

	void SetPhase(SBaseManagerPhases _phase);
	SBaseManagerPhases GetPhase();
};