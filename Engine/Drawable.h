#pragma once
#include "Vec2.h"
#include <vector>
#include "Graphics.h"

class Drawable
{
public:
	Drawable(std::vector<Vec2> model, Color c)
		:
		model(std::move(model)),
		color(c)
	{}
	void Scale(float scale_in)
	{
		scale_x *= scale_in;
		scale_y *= scale_in;
		translation *= scale_in;
	}
	void ScaleIndependent(float scale_in_x, float scale_in_y)
	{
		scale_x *= scale_in_x;
		scale_y *= scale_in_y;
		translation.x *= scale_in_x;
		translation.y *= scale_in_y;
	}
	void Translate(const Vec2& translation_in)
	{
		translation += translation_in;
	}
	void Render(Graphics& gfx)
	{
		for (auto& v : model)
		{
			v.x *= scale_x;
			v.y *= scale_y;
			v += translation;
		}
		gfx.DrawClosedPolyline(model, color);
	}
private:
	Color color;
	std::vector<Vec2> model;
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	Vec2 translation = { 0.0f, 0.0f };
};