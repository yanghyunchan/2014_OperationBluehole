#include "stdafx.h"
#include "RenderTarget.h"
#include "Renderer.h"



RenderTarget::RenderTarget()
{
}


RenderTarget::~RenderTarget()
{
	SafeRelease(mRenderTargetView);
}


BOOL RenderTarget::Init(UINT width, UINT height, DXGI_FORMAT format)
{
	ID3D11Texture2D* pTexture = NULL;

	mD3DDevice = Renderer::GetInstance()->GetDevice();
	mWidth = width;
	mHeight = height;

	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = mWidth;
	desc.Height = mHeight;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = format;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	hr = mD3DDevice->CreateTexture2D(&desc, NULL, &pTexture);
	if (FAILED(hr))
		return FALSE;

	hr = mD3DDevice->CreateRenderTargetView(pTexture, NULL, &mRenderTargetView);
	if (FAILED(hr))
		return FALSE;

	hr = mD3DDevice->CreateShaderResourceView(pTexture, NULL, &mTextureRV);
	pTexture->Release();

	return TRUE;
}