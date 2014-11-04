#include "stdafx.h"
#include "Contents.h"
#include "LightManager.h"
#include "InputDispatcher.h"
#include "Camera.h"
#include "ProcessManager.h"
#include "PostProcessor.h"
#include "Renderer.h"

Contents::Contents()
{
}

Contents::~Contents()
{
}

void Contents::Init()
{
	ID3D11Device* device = Renderer::GetInstance()->GetDevice();

	InputDispatch(VK_ESCAPE, [](){ ProcessManager::GetInstance()->Stop(); });
	InputDispatch('Z', [](){ PostProcessor::GetInstance()->ChangeKernelRadius(0.05f); });
	InputDispatch('X', [](){ PostProcessor::GetInstance()->ChangeKernelRadius(-0.05f); });
	
	InputDispatch(VK_UP, [](){ Camera::GetInstance()->Walk(30); });
	InputDispatch(VK_DOWN, [](){ Camera::GetInstance()->Walk(-30); });
	InputDispatch(VK_RIGHT, [](){ Camera::GetInstance()->Strafe(30); });
	InputDispatch(VK_LEFT, [](){ Camera::GetInstance()->Strafe(-30); });
	InputDispatch('S', [](){ Camera::GetInstance()->Pitch(1); });
	InputDispatch('W', [](){ Camera::GetInstance()->Pitch(-1); });
	InputDispatch('D', [](){ Camera::GetInstance()->RotateY(1); });
	InputDispatch('A', [](){ Camera::GetInstance()->RotateY(-1); });






	//InputDispatch(VK_DOWN, [](){ PostProcessor::GetInstance()->ChangeKernelRadius(-0.05f); });

	LightManager::GetInstance()->CreatePointLights(MAX_LIGHT);

	//todo : �� ��ġ ����
	LightManager::GetInstance()->mPLightList[1]->mPos = D3DXVECTOR4(-50.f, 0.f, -50.f, 1.0f);
	LightManager::GetInstance()->mPLightList[1]->mColor = D3DXVECTOR4(1, 1, 1, 1);

}

void Contents::Render()
{

}


