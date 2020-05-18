#pragma once
#include "Vec2.h"
#include <vector>

class Entity
{
public:
	Entity(std::vector<Vec2> model)
		:
		model(std::move(model))
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
	std::vector<Vec2> GetPolyline() const
	{
		auto poly = model;
		for (auto& v : poly)
		{
			v *= scale;
			v += pos;
		}
		return poly;
	}
private:
	float scale = 1.0f;
	Vec2 pos = { 0.0f, 0.0f };
	std::vector<Vec2> model;
};