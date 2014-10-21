#pragma once
#include "Singleton.h"



struct QuadVertex
{
	D3DXVECTOR4 Pos;
	D3DXVECTOR2 Tex;
};

struct PostProcessorConstantBuffer
{
	D3DXVECTOR4 vEye;
	D3DXVECTOR4 vLightDir[2];
	D3DXVECTOR4 vLightColor[2];
};

class PostProcessor : public Singleton<PostProcessor>
{
public:
	PostProcessor();
	~PostProcessor();

	BOOL Init();

	void Render();


private:

	BOOL					CompilePixelShader();
	BOOL					CreateConstBuffer();
	BOOL					CreateSamplerLinear();
	BOOL					CreateQuad();

	HRESULT					CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

	ID3D11PixelShader*		mPixelShader = NULL;
	ID3D11Buffer*			mPSConstBuffer = NULL;

	WCHAR*					mPixelShaderPath = L"PostProcess.hlsl";
	LPCSTR					mPixelShaderMain = "main";
	LPCSTR					mPixelShaderModel = "ps_4_0_level_9_1";

	ID3D11SamplerState*		mSamplerLinear = NULL;

	// draw quad
	ID3D11Buffer*           mVertexBuffer = NULL;
	ID3D11Buffer*           mIndexBuffer = NULL;

	// get from renderer
	ID3D11Device*           mD3DDevice = NULL;
	ID3D11DeviceContext*    mD3DDeviceContext = NULL;
	ID3D11RenderTargetView* mRenderTargetView = NULL;

	// get last error
	HRESULT hr = S_OK;
};

