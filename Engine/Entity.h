#pragma once
#include "Vec2.h"
#include <vector>
#include "Drawable.h"

class Entity
{
public:
	Entity(std::vector<Vec2> model, const Vec2& pos = { 0.0f, 0.0f }, Color color = Colors::Yellow)
		:
		pos(pos),
		model(std::move(model)),
		color(color)
	{}
	const Vec2& GetPos() const
	{
		return pos;
	}
	void SetPos(const Vec2& pos_in)
	{
		pos = pos_in;
	}
	const float GetScale() const
	{
		return scale;
	}
	void SetScale(float newScale)
	{
		scale = newScale;
	}
	void TranslateBy(const Vec2& offset)
	{
		pos += offset;
	}
	Drawable GetDrawable() const
	{
		Drawable d(model, color);
		d.Scale(scale);
		d.Translate(pos);
		return d;
	}
private:
	Color color;
	float scale = 1.0f;
	Vec2 pos = { 0.0f, 0.0f };
	std::vector<Vec2> model;
};