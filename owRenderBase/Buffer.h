#pragma once

#include "Shader.h"
#include "ShaderParameter.h"

// A buffer is an index buffer or vertex buffer to geometry that should be stored on the GPU.
class Buffer : public Object
{
public:
	typedef Object base;

	enum BufferType
	{
		Unknown = 0,
		VertexBuffer,
		IndexBuffer,
		StructuredBuffer,
		ConstantBuffer
	};

	// Bind the buffer for rendering.
	virtual bool Bind(uint32 id, std::weak_ptr<Shader> shader, ShaderParameter::Type parameterType) = 0;
	// Unbind the buffer for rendering.
	virtual void UnBind(uint32 id, std::weak_ptr<Shader> shader, ShaderParameter::Type parameterType) = 0;

	// Copy the contents of another buffer to this one.
	// Buffers must be the same size in bytes.
	virtual void Copy(std::shared_ptr<Buffer> other) = 0;

	// Is this an index buffer or an attribute/vertex buffer?
	virtual BufferType GetType() const = 0;
	// How many elements does this buffer contain?
	virtual uint32 GetElementCount() const = 0;
	// Elements stride
	virtual uint32 GetElementStride() const = 0;
};

typedef std::shared_ptr<Buffer> SharedBufferPtr;
