#include "stdafx.h"


// General
#include "owRenderDX11.h"


// Additional
#include "RenderDeviceDX11.h"
#include "RenderWindowDX11.h"


// Statics
CBaseManager* _BaseManager = nullptr;


// Functions
RenderDevice* CreateRenderDeviceDX11(CBaseManager* _baseManager)
{
	_BaseManager = _baseManager;
	return new RenderDeviceDX11();
}

RenderWindow* CreateRenderWindowDX11(HWND hWnd, RenderDevice* device, cstring windowName, int windowWidth, int windowHeight, bool vSync)
{
	RenderDeviceDX11* pDevice = dynamic_cast<RenderDeviceDX11*>(device);
	_ASSERT(pDevice != NULL);

	return new RenderWindowDX11(hWnd, pDevice, windowName, windowWidth, windowHeight, vSync);
}