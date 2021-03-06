#pragma once

class ShaderDX11 : public Shader, public std::enable_shared_from_this<ShaderDX11>
{
public:
	ShaderDX11(ID3D11Device2* pDevice);
	virtual ~ShaderDX11();

	// Shader loading
	virtual bool LoadShaderFromString(ShaderType type, cstring sourceFileName, cstring source, const ShaderMacros& shaderMacros, cstring entryPoint, cstring profile);
	virtual bool LoadShaderFromFile(ShaderType type, cstring fileName, const ShaderMacros& shaderMacros, cstring entryPoint, cstring profile);

	// Query for the latest supported shader profile
	virtual std::string GetLatestProfile(ShaderType type);

	virtual void Bind();
	virtual void UnBind();

	virtual void Dispatch(const glm::uvec3& numGroups);

protected:

	// Destroy the contents of this shader (in case we are loading a new shader).
	virtual void Destroy();

private:
	ATL::CComPtr<ID3D11Device2> m_pDevice;
	ATL::CComPtr<ID3D11DeviceContext2> m_pDeviceContext;

	ATL::CComPtr<ID3D11VertexShader> m_pVertexShader;
	ATL::CComPtr<ID3D11HullShader> m_pHullShader;
	ATL::CComPtr<ID3D11DomainShader> m_pDomainShader;
	ATL::CComPtr<ID3D11GeometryShader> m_pGeometryShader;
	ATL::CComPtr<ID3D11PixelShader> m_pPixelShader;
	ATL::CComPtr<ID3D11ComputeShader> m_pComputeShader;

	ATL::CComPtr<ID3DBlob> m_pShaderBlob;

	ATL::CComPtr<ID3D11InputLayout> m_pInputLayout;

	// Parameters necessary to reload the shader at runtime if it is modified on disc.
	ShaderMacros m_ShaderMacros;
	std::string m_EntryPoint;
	std::string m_Profile;
	std::string m_ShaderFileName;

	typedef std::unique_lock<std::recursive_mutex> MutexLock;
	std::recursive_mutex m_Mutex;

};
