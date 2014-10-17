



//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register(b0)
{
	float4 vLightDir[2];
	float4 vLightColor[2];
};

//--------------------------------------------------------------------------------------
// Textures and Samplers
//--------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Color : COLOR0;
};

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 main(PS_INPUT Input) : SV_TARGET
{
	return Input.Color;
}

