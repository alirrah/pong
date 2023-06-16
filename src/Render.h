#pragma once
#include "Pong.h"
#include "GL/glew.h"
#include "freeglut.h"

mjf::Pong pong{ {{-0.9f, 0.3f}, 0.1f, 0.3f}, {{0.8f, 0.3f}, 0.1f, 0.3f}, {{0.0f, 0.0f}, 0.05f, 0.05f} };

void renderTexts()
{
	glDisable(GL_SCISSOR_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	string leftScore = to_string(pong.getLeftScore());
	string rightScore = to_string(pong.getRightScore());
	string time = to_string(pong.getTime());

	// Render left score
	glRasterPos2f(-0.2, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)leftScore.c_str());

	glRasterPos2f(0.0, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)time.c_str());

	// Render right score
	glRasterPos2f(0.2, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)rightScore.c_str());

	glPopAttrib();

	glutSwapBuffers();

	glClear(GL_COLOR_BUFFER_BIT);

	// Render left score
	glRasterPos2f(-0.2, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)leftScore.c_str());

	glRasterPos2f(0.0, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)time.c_str());

	// Render right score
	glRasterPos2f(0.2, 0.85);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)rightScore.c_str());
}

void display()
{
	if (pong.getTime() != 0) {

		static int leftScore = 0;
		static int rightScore = 0;

		if (pong.getLeftScore() != leftScore || pong.getRightScore() != rightScore)
		{
			leftScore = pong.getLeftScore();
			rightScore = pong.getRightScore();
			renderTexts();
		}

		glEnable(GL_SCISSOR_TEST);
		glScissor(0, 35, 500, 420);

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		updateLeftPaddle(&pong);
		updateRightPaddle(&pong);
		updateBall(&pong);

		if (pong.isBallOutsideTheWindow())
			pong.respawnBall();

		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, pong.getLeftPaddleArr(), GL_DYNAMIC_COPY));

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, pong.getRightPaddleArr(), GL_DYNAMIC_COPY));

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, pong.getBallArr(), GL_DYNAMIC_COPY));

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glutSwapBuffers();
	}
}