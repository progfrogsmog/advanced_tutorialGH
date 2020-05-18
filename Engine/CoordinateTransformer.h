#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx)
		:
		gfx(gfx)
	{}
	void DrawClosedPolyline(std::vector<Vec2>& verts, Color color)
	{
		Vec2 offset = { (float)gfx.ScreenWidth / 2, (float)gfx.ScreenHeight / 2 };
		for (auto& i : verts)
		{
			i.y *= -1;
			i += offset;
		}
		gfx.DrawClosedPolyline(verts, color);
	}
private:
	Graphics& gfx;
};