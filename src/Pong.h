#pragma once
#include "Rect.h"

namespace mjf
{
	class Pong
	{
	public:
		Pong();
		Pong(const Rect& leftPaddle, const Rect& rightPaddle, const Rect& ball);
		void create(const Rect& leftPaddle, const Rect& rightPaddle, const Rect& ball);
		void moveRightPaddle(float value);
		void moveLeftPaddle(float value);
		void moveBall(float x, float y);
		void respawnBall();
		void tick();

	public:
		const float* getRightPaddleArr() const;
		const float* getLeftPaddleArr() const;
		const float* getBallArr() const;
		const float* getAllObejctsArr() const;

	public:
		const Rect& getRightPaddle() const;
		const Rect& getLeftPaddle() const;
		const Rect& getBall() const;
		int getRightScore() const;
		int getLeftScore() const;

	public:
		bool ballHasCollisionWithLeftPaddle() const;
		bool ballHasCollisionWithRightPaddle() const;
		bool isBallOutsideTheWindow();

	public:
		float _paddleRightSpeed;
		float _paddleLeftSpeed;

	private:
		Rect _rightPaddle;
		Rect _leftPaddle;
		Rect _ball;
		int _rightScore;
		int _leftScore;
	};

	Pong::Pong() = default;

	Pong::Pong(const Rect& leftPaddle, const Rect& rightPaddle, const Rect& ball)
	{
		create(leftPaddle, rightPaddle, ball);
	}

	void Pong::create(const Rect& leftPaddle, const Rect& rightPaddle, const Rect& ball)
	{
		_leftPaddle = leftPaddle;
		_rightPaddle = rightPaddle;
		_ball = ball;
	}

	inline const float* Pong::getRightPaddleArr() const
	{
		return _rightPaddle.getArray();
	}

	inline const float* Pong::getLeftPaddleArr() const
	{
		return _leftPaddle.getArray();
	}

	inline const float* Pong::getBallArr() const
	{
		return _ball.getArray();
	}

	inline const float* Pong::getAllObejctsArr() const
	{
		float* objects = new float[2 * 12];

		for (int i{}; i < 12; ++i)
		{
			objects[i] = (_leftPaddle.getArray())[i];
		}

		for (int i{ 12 }; i < 24; ++i)
		{
			objects[i] = (_rightPaddle.getArray())[i - 12];
		}

		return objects;
	}

	inline const Rect& Pong::getRightPaddle() const
	{
		return _rightPaddle;
	}

	inline const Rect& Pong::getLeftPaddle() const
	{
		return _leftPaddle;
	}

	inline const Rect& Pong::getBall() const
	{
		return _ball;
	}

	inline int Pong::getRightScore() const
	{
		return _rightScore;
	}

	inline int Pong::getLeftScore() const
	{
		return _leftScore;
	}

	inline bool Pong::ballHasCollisionWithLeftPaddle() const
	{
		float ballX = _ball.getOrigin().x;
		float ballY = _ball.getOrigin().y;
		float leftPaddleX = _leftPaddle.getOrigin().x;
		float leftPaddleY = _leftPaddle.getOrigin().y;

		if (ballX + _ball.getWidth() < leftPaddleX)
		{
			return false;
		}

		if (leftPaddleX + _rightPaddle.getWidth() < ballX)
		{
			return false;
		}

		if (ballY - _ball.getHeight() > leftPaddleY)
		{
			return false;
		}

		if (leftPaddleY - _rightPaddle.getHeight() > ballY)
		{
			return false;
		}

		return true;
	}

	inline bool Pong::ballHasCollisionWithRightPaddle() const
	{
		float ballX{ _ball.getOrigin().x };
		float ballY{ _ball.getOrigin().y };
		float rightPaddleX{ _rightPaddle.getOrigin().x };
		float rightPaddleY{ _rightPaddle.getOrigin().y };

		if (ballX + _ball.getWidth() < rightPaddleX)
		{
			return false;
		}

		if (rightPaddleX + _rightPaddle.getWidth() < ballX)
		{
			return false;
		}

		if (ballY - _ball.getHeight() > rightPaddleY)
		{
			return false;
		}

		if (rightPaddleY - _rightPaddle.getHeight() > ballY)
		{
			return false;
		}

		return true;
	}

	inline bool Pong::isBallOutsideTheWindow()
	{
		if (_ball.getOrigin().x < -1.0f)
		{
			++_rightScore;
			return true;
		}

		if (_ball.getOrigin().x > 1.0f)
		{
			++_leftScore;
			return true;
		}

		return false;
	}

	void Pong::moveLeftPaddle(float value)
	{
		Cord origin{ _leftPaddle.getOrigin() };
		origin.y += value;

		_leftPaddle.create(origin, _leftPaddle.getWidth(), _leftPaddle.getHeight());
	}

	void Pong::moveRightPaddle(float value)
	{
		Cord origin{ _rightPaddle.getOrigin() };
		origin.y += value;

		_rightPaddle.create(origin, _rightPaddle.getWidth(), _rightPaddle.getHeight());
	}

	void Pong::moveBall(float x, float y)
	{
		Cord origin{ _ball.getOrigin() };
		origin.x += x;
		origin.y += y;

		_ball.create(origin, _ball.getWidth(), _ball.getHeight());
	}

	void Pong::respawnBall()
	{
		_ball.create({ 0.0f, 0.0f }, _ball.getWidth(), _ball.getHeight());
	}

	void Pong::tick()
	{

	}

}