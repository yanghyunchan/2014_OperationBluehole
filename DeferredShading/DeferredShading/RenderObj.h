#pragma once

static const WCHAR* VS_PATH = L"VertexShader.hlsl";
static const LPCSTR	VS_MAIN = "main";

static const WCHAR* PS_PATH = L"PixelShader.hlsl";
static const LPCSTR	PS_MAIN = "main";

static const int MAX_LIGHT = 2;

struct VSConstantBuffer
{
	D3DXMATRIX mWorld;
	D3DXMATRIX mView;
	D3DXMATRIX mProjection;
};

struct PSConstantBuffer
{
	D3DXVECTOR4 vLightDir[2];
	D3DXVECTOR4 vLightColor[2];
};

struct CubeVertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 Normal;
};

//IA - Input Assembler Stage
//1. 입력버퍼 생성
//2. layout 생성(vertex 정의)
//3. IASetinputlayout, IASetbuffer를 통해서 IA단계에 생성 정보들을 전달
//4. IASetPrimitiveTopology를 통해 설정
//5. dpcall

// todo : 상속받아서 쓸 수 있도록
// todo : 다수의 오브젝트를 모아서 찍도록
class RenderObj
{
public:
	RenderObj();
	virtual ~RenderObj();

	D3DXMATRIX	GetMatWorld(){ return mWorld; }

	BOOL Init();
	void Release();
	BOOL CompileShader();
	BOOL CreateBuffer();

	void Render();

private:

	HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	BOOL	CompileVertexShader();
	BOOL	CompilePixelShader();

	// draw cube
	BOOL	CreateVertexBuff();
	BOOL	CreateIndexBuff();
	BOOL	CreateConstBuff();

	ID3D11VertexShader*     mVertexShader = NULL;
	ID3D11PixelShader*      mPixelShader = NULL;

	ID3D11InputLayout*      mVertexLayout11 = NULL;

	ID3D11Buffer*           mVertexBuffer = NULL;
	ID3D11Buffer*           mIndexBuffer = NULL;
	ID3D11Buffer*           mVSConstBuffer = NULL;
	ID3D11Buffer*			mPSConstBuffer = NULL;

	D3DXMATRIX				mWorld;

	// get to Renderer
	ID3D11Device*           mD3DDevice = NULL;
	ID3D11DeviceContext*    mD3DDeviceContext = NULL;

	// get last error
	HRESULT hr = S_OK;
};


