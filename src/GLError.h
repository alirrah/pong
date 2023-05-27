#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) glClearError();\
	x;\
	ASSERT(glCheckError(#x, __FILE__, __LINE__))

static void glClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool glCheckError(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		cout << "[OpenGL Error] (" << error << ")" << function
			<< " " << file << ":" << line << endl;
		return false;
	}

	return true;
}