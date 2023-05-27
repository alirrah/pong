#pragma once
#include "Cord.h"

namespace mjf
{
	class Rect
	{
	public:
		Rect();
		Rect(Cord origin, float width, float height);
		~Rect();
		Rect(Rect& rect);
		Rect& operator = (const Rect& rect);

	public:
		void create(Cord origin, float width, float height);
		const float* getArray() const;
		float getWidth() const;
		float getHeight() const;
		Cord getOrigin() const;

	private:
		void updateArray();

	private:
		float _width;
		float _height;
		float* _array = nullptr;
		Cord _origin;
	};

	Rect::Rect() = default;

	Rect::Rect(Cord origin, float width, float height)
	{
		create(origin, width, height);
	}

	Rect::~Rect()
	{
		delete[] _array;
	}

	Rect::Rect(Rect& rect)
	{
		_origin = rect._origin;
		_width = rect._width;
		_height = rect._height;

		create(_origin, _width, _height);
	}

	Rect& Rect::operator =(const Rect& rect)
	{
		_origin = rect._origin;
		_width = rect._width;
		_height = rect._height;

		create(_origin, _width, _height);

		return *this;
	}

	void Rect::create(Cord origin, float width, float height)
	{
		_width = width;
		_height = height;
		_origin = origin;

		delete[] _array;
		_array = new float[12];

		updateArray();
	}

	void Rect::updateArray()
	{
		_array[0] = _origin.x;
		_array[1] = _origin.y;
		_array[2] = 0.0f;
		_array[3] = _origin.x;
		_array[4] = _origin.y - _height;
		_array[5] = 0.0f;
		_array[6] = _origin.x + _width;
		_array[7] = _origin.y;
		_array[8] = 0.0f;
		_array[9] = _origin.x + _width;
		_array[10] = _origin.y - _height;
		_array[11] = 0.0f;
	}

	const float* Rect::getArray() const
	{
		return _array;
	}

	inline float Rect::getWidth() const
	{
		return _width;
	}

	inline float Rect::getHeight() const
	{
		return _height;
	}

	inline Cord Rect::getOrigin() const
	{
		return _origin;
	}
}