





//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register(b0)
{
	float4 vEye;
	float4 vLightDir[2];
	float4 vLightColor[2];
};

//--------------------------------------------------------------------------------------
// Textures and Samplers
//--------------------------------------------------------------------------------------

Texture2D txNormal : register(t0);
Texture2D txDiffuse : register(t1);
Texture2D txSpecular : register(t2);
Texture2D txDepth : register(t3);
SamplerState samLinear : register(s0);

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float2 Tex : TEXCOORD0;
};


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------

float4 main(PS_INPUT Input) : SV_TARGET
{
	float4 normal = txNormal.Sample(samLinear, Input.Tex);
	float4 diffuse = txDiffuse.Sample(samLinear, Input.Tex);
	float4 specular = txSpecular.Sample(samLinear, Input.Tex);
	float4 depth = txDepth.Sample(samLinear, Input.Tex);

	specular = dot(vLightDir[0], normal) * vLightColor[0] * specular * 0.4;
	diffuse = diffuse * 0.8;

	normal = (normal - 0.5) * 2;

	float4 finalColor = saturate(specular + diffuse);
	//float4 finalColor = float4(depth.x, depth.x, depth.x, 1);
	finalColor.a = 1;

	return finalColor;
}

