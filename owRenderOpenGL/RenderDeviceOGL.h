#pragma once

class Material;

class RenderDeviceOGL : public RenderDevice
{
public:
	typedef RenderDevice base;

	RenderDeviceOGL();
	virtual ~RenderDeviceOGL();

	virtual cstring GetDeviceName() const;

	// Inherited from RenderDevice
	virtual std::shared_ptr<Buffer> CreateFloatVertexBuffer(const float* data, uint32 count, uint32 stride);
	virtual std::shared_ptr<Buffer> CreateDoubleVertexBuffer(const double* data, uint32 count, uint32 stride);
	virtual std::shared_ptr<Buffer> CreateUInt16IndexBuffer(const uint16* data, uint32 count);
	virtual std::shared_ptr<Buffer> CreateUInt32IndexBuffer(const uint32* data, uint32 count);
	virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(const void* data, size_t size);
	virtual std::shared_ptr<StructuredBuffer> CreateStructuredBuffer(void* data, uint32 count, uint32 stride, CPUAccess cpuAccess = CPUAccess::None, bool gpuWrite = false);

	virtual void DestroyBuffer(std::shared_ptr<Buffer> buffer);
	virtual void DestroyVertexBuffer(std::shared_ptr<Buffer> buffer);
	virtual void DestroyIndexBuffer(std::shared_ptr<Buffer> buffer);
	virtual void DestroyConstantBuffer(std::shared_ptr<ConstantBuffer> buffer);
	virtual void DestroyStructuredBuffer(std::shared_ptr<StructuredBuffer> buffer);

	virtual std::shared_ptr<Shader> CreateShader();
	virtual void DestroyShader(std::shared_ptr<Shader> shader);
	
	virtual std::shared_ptr<Mesh> CreateMesh();
	virtual void DestroyMesh(std::shared_ptr<Mesh> mesh);

	virtual std::shared_ptr<Texture> CreateTexture2D(cstring fileName);
	virtual std::shared_ptr<Texture> CreateTextureCube(cstring fileName);

	virtual std::shared_ptr<Texture> CreateTexture2D(uint16_t width, uint16_t height, uint16_t slices = 1, const Texture::TextureFormat& format = Texture::TextureFormat(), CPUAccess cpuAccess = CPUAccess::None, bool gpuWrite = false);
	virtual std::shared_ptr<Texture> CreateTextureCube(uint16_t size, uint16_t numCubes = 1, const Texture::TextureFormat& format = Texture::TextureFormat(), CPUAccess cpuAccess = CPUAccess::None, bool gpuWrite = false);
	virtual std::shared_ptr<Texture> CreateTexture();
	virtual std::shared_ptr<Texture> GetDefaultTexture() const;

	virtual void DestroyTexture(std::shared_ptr<Texture> texture);

	virtual std::shared_ptr<Query> CreateQuery(Query::QueryType queryType = Query::QueryType::Timer, uint8_t numBuffers = 3);
	virtual void DestoryQuery(std::shared_ptr<Query> query);

	virtual std::shared_ptr<RenderTarget> CreateRenderTarget();
	virtual void DestroyRenderTarget(std::shared_ptr<RenderTarget> renderTarget);

	virtual std::shared_ptr<SamplerState> CreateSamplerState();
	virtual void DestroySampler(std::shared_ptr<SamplerState> sampler);

	virtual std::shared_ptr<Material> CreateMaterial();
	virtual void DestroyMaterial(std::shared_ptr<Material> Material);
	virtual std::shared_ptr<Material> GetDefaultMaterial() const;

	virtual std::shared_ptr<PipelineState> CreatePipelineState();
	virtual void DestoryPipelineState(std::shared_ptr<PipelineState> pipeline);
	virtual std::shared_ptr<PipelineState> GetDefaultPipeline() const;

public:
	bool IsDoubleBuffered();
	uint32 GetDefaultRB();
	void SetDefaultRB(uint32 _obj);


public:
	void CreateDevice(HDC _hdc);
	void LoadDefaultResources();

private:
	// The name of the graphics device used for rendering.
	std::string m_DeviceName;

	typedef std::vector< std::shared_ptr<Scene> > SceneList;
	SceneList m_Scenes;

	typedef std::vector< std::shared_ptr<Buffer> > BufferList;
	BufferList m_Buffers;

	typedef std::vector< std::shared_ptr<Mesh> > MeshList;
	MeshList m_Meshes;

	typedef std::vector< std::shared_ptr<Shader> > ShaderList;
	ShaderList m_Shaders;

	typedef std::vector< std::shared_ptr<Texture> > TextureList;
	TextureList m_Textures;
	typedef std::map< std::string, std::shared_ptr<Texture> > TextureMap;
	TextureMap m_TexturesByName;
	std::shared_ptr<Texture> m_pDefaultTexture;

	typedef std::vector< std::shared_ptr<RenderTarget> > RenderTargetList;
	RenderTargetList m_RenderTargets;

	typedef std::vector< std::shared_ptr<SamplerState> > SamplerList;
	SamplerList m_Samplers;

	typedef std::vector< std::shared_ptr<Material> > MaterialList;
	MaterialList m_Materials;
	std::shared_ptr<Material> m_pDefaultMaterial;

	typedef std::vector< std::shared_ptr<PipelineState> > PipelineList;
	PipelineList m_Pipelines;

	typedef std::vector< std::shared_ptr<Query> > QueryList;
	QueryList m_Queries;

	std::shared_ptr<PipelineState> m_pDefaultPipeline;

	

private:
	uint32						m_DepthFormat;
	bool						_doubleBuffered;
	uint16						_maxComputeBufferAttachments;
	bool                        m_IsDefaultFBOMultisampled;
	int							m_RBDefault;

	//------------------------------------------------------------------------------------
	// Settings
	CGroupRenderCaps&			m_DeviceCapsSettings;
	CGroupOpenGL&				m_OpenGLSettings;
};