#pragma once

// FORWARD BEGIN
class RenderDevice;
// FORWARD END

class R_RenderBuffer
{
	static const uint32 MaxColorAttachmentCount = 4;

public:
	R_RenderBuffer(RenderDevice* _RenderDevice);
	virtual ~R_RenderBuffer();

	//

	void createRenderBuffer(uint32 _width, uint32 _height, R_TextureFormats::List _format, bool _depth, uint32 _numColBufs, uint32 _samples);
	SharedTexturePtr getRenderBufferTex(uint32 bufIndex);
	void setRenderBuffer();
	void resetRenderBuffer();
	bool getRenderBufferData(int _bufIndex, int* _width, int* _height, int* _compCount, void* _dataBuffer, int _bufferSize);
	void getRenderBufferDimensions(int* width, int* _height);

private:
	void resolveRenderBuffer();

public:
	uint32				m_FBGLObj, m_FBMultiSampledGLObj;
	uint32				m_Width, m_Height;
	uint32				m_Samples;

	SharedTexturePtr	m_DepthTexture;
	SharedTexturePtr	m_ColorsTextures[MaxColorAttachmentCount];
	uint32				m_DepthBufferGLObj;
	uint32				m_ColorsBuffersGLObj[MaxColorAttachmentCount];  // Used for multisampling

protected:
	RenderDevice*		m_RenderDevice;
};