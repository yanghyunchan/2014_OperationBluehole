#include "stdafx.h"
#include "Camera.h"
#include "App.h"








void Camera::Update()
{
	RECT rc;
	GetClientRect(App::GetInstance()->GetHandleMainWindow(), &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	D3DXMatrixLookAtLH(&mMatView, &mEye, &mAt,&mUp );
	D3DXMatrixPerspectiveFovLH(&mMatProj, D3DX_PI / 4, width / (FLOAT)height, mNear, mFar);
}
