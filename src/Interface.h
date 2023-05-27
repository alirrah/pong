#pragma once
#include "Pong.h"
#include "freeglut.h"

bool g_is_w_pressed = false;
bool g_is_s_pressed = false;
bool g_is_i_pressed = false;
bool g_is_k_pressed = false;

void updateLeftPaddle(mjf::Pong* pong)
{
	if (g_is_w_pressed)
		pong->_paddleLeftSpeed = 0.001f;
	else if (g_is_s_pressed)
		pong->_paddleLeftSpeed = -0.001f;
	else
		pong->_paddleLeftSpeed = 0.0f;
	pong->moveLeftPaddle(pong->_paddleLeftSpeed);
}

void updateRightPaddle(mjf::Pong* pong)
{
	if (g_is_i_pressed)
		pong->_paddleRightSpeed = 0.001f;
	else if (g_is_k_pressed)
		pong->_paddleRightSpeed = -0.001f;
	else
		pong->_paddleRightSpeed = 0.0f;
	pong->moveRightPaddle(pong->_paddleRightSpeed);
}


void keyboardHandler(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'q':
	case 'Q': g_is_w_pressed = !g_is_w_pressed;
		break;
	case 'a':
	case 'A':
		g_is_s_pressed = !g_is_s_pressed;
		break;
	case 'p':
	case 'P':
		g_is_i_pressed = !g_is_i_pressed;
		break;
	case 'l':
	case 'L':
		g_is_k_pressed = !g_is_k_pressed;
		break;
	}

}

void keyboardUpHandler(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'q':
	case 'Q':
		g_is_w_pressed = false;
		break;
	case 'a':
	case 'A':
		g_is_s_pressed = false;
		break;
	case 'p':
	case 'P':
		g_is_i_pressed = false;
		break;
	case 'l':
	case 'L':
		g_is_k_pressed = false;
		break;
	}
}

void updateBall(mjf::Pong* pong)
{
	static float xSpeed = 0.0005f;
	static float ySpeed = 0.0f;

	pong->moveBall(xSpeed, ySpeed);

	if (pong->ballHasCollisionWithLeftPaddle())
	{
		xSpeed = 0.0005f;
		ySpeed = pong->_paddleLeftSpeed;
	}

	if (pong->ballHasCollisionWithRightPaddle())
	{
		xSpeed = -0.0005f;
		ySpeed = pong->_paddleRightSpeed;
	}

	if (pong->getBall().getOrigin().y > 0.8f || pong->getBall().getOrigin().y < -0.8f)
	{
		ySpeed = -ySpeed;
	}
}
