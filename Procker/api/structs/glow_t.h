#pragma once

struct glow_t
{
	float    flUnk1;
	float            r;
	float			 g;
	float			 b;
	float            a;

	char            unknown[4];
	float            flUnk2;
	float            m_flBloomAmount;
	float            localplayeriszeropoint3;


	bool            m_bRenderWhenOccluded;
	bool            m_bRenderWhenUnoccluded;
	bool            m_bFullBloomRender;
};