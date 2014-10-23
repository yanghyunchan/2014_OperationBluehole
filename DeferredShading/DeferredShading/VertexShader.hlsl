


//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register(b0)
{
	matrix World;
	matrix View;
	matrix Projection;
};

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------

struct VS_INPUT
{
	float4 Pos : POSITION;
	float3 Norm : NORMAL;
	float2 Tex : TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 Pos : SV_POSITION;
	float3 Norm : TEXCOORD0;
	float2 Tex : TEXCOORD1;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT main( VS_INPUT Input )
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	output.Pos = mul(Input.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Norm = mul(Input.Norm, (float3x3)World);
	output.Tex = Input.Tex;
	return output;
}