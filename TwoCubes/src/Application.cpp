
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {

	//Quad 1
	1.0f,1.0f,-1.0f,1.0f, // g
	-1.0f,-1.0f,-1.0f,1.0f, //m
	1.0f,-1.0f,-1.0f,1.0f, // n

	1.0f,1.0f,-1.0f,1.0f, // g
	-1.0f,1.0f,-1.0f,1.0f,// h
	-1.0f,-1.0f,-1.0f,1.0f, //m

	//Quad 2
	1.0f,1.0f,1.0f,1.0f, // c
	-1.0f,1.0f,-1.0f,1.0f,// h
	1.0f,1.0f,-1.0f,1.0f, // g

	1.0f,1.0f,1.0f,1.0f, // c
	-1.0f,1.0f,-1.0f,1.0f,// h
	-1.0f,1.0f,1.0f,1.0f, // d

	//Quad 3
	1.0f,-1.0f,1.0f,1.0f, //b
	-1.0f,-1.0f,1.0f,1.0f, // a
	-1.0f,1.0f,1.0f,1.0f, // d

	1.0f,-1.0f,1.0f,1.0f, //b
	-1.0f,1.0f,1.0f,1.0f, // d
	1.0f,1.0f,1.0f,1.0f, // c

	//Quad 4

	1.0f,-1.0f,-1.0f,1.0f, // j
	1.0f,1.0f,1.0f,1.0f, // c
	1.0f,1.0f,-1.0f,1.0f, // i

	1.0f,-1.0f,-1.0f,1.0f, // j
	1.0f,1.0f,1.0f,1.0f, // c
	1.0f,-1.0f,1.0f,1.0f, //b
	//Quad 5
	-1.0f,-1.0f,1.0f,1.0f, // a
	-1.0f,1.0f,-1.0f,1.0f,// k
	-1.0f,1.0f,1.0f,1.0f, // d

	-1.0f,-1.0f,1.0f,1.0f, // a
	-1.0f,-1.0f,-1.0f,1.0f, //l
	-1.0f,1.0f,-1.0f,1.0f,// k

	//Quad 6
	1.0f,-1.0f,-1.0f,1.0f, // f
	-1.0f,-1.0f,1.0f,1.0f, // a
	1.0f,-1.0f,1.0f,1.0f, //b

	1.0f,-1.0f,-1.0f,1.0f, // f
	-1.0f,-1.0f,1.0f,1.0f, // a
	-1.0f,-1.0f,-1.0f,1.0f, //e
};


GLfloat vertexColors[] = {
	//Color Quad 1 Blanco
	1.0f, 1.0f, 1.0f, 0.5f,
	1.0f, 1.0f, 1.0f, 0.5f,
	1.0f, 1.0f, 1.0f, 0.5f,	

	1.0f, 1.0f, 1.0f, 0.5f,
	1.0f, 1.0f, 1.0f, 0.5f,
	1.0f, 1.0f, 1.0f, 0.5f,

	//Color Quad 2 Azul
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,

	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	0.0f, 0.0f, 1.0f, 0.5f,
	//Color Quad 3 //Amarillo
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,

	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	1.0f, 1.0f, 0.0f, 0.5f,
	//Color Quad 4 // Rojo
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,

	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,
	1.0f, 0.0f, 0.0f, 0.5f,

	//Color Quad 5  //Verde
	//R   G     B
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,

	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,
	0.0f, 1.0f, 0.0f, 0.5f,

	//Quad 6
	1.0f, 0.35f, 0.0f,0.0f,
	1.0f, 0.5f, 0.0f, 0.0f,
	1.0f, 0.5f, 0.0f, 0.0f,

	1.0f, 0.35f, 0.0f,0.0f,
	1.0f, 0.5f, 0.0f, 0.0f,
	1.0f, 0.5f, 0.0f, 0.0f,

};


Application::Application() : eye(0.0f, 0.0f, 7.0f), 
							target (0.0f, 0.0f, 0.0f),
							transform(glm::mat4(1.0f)), 
							angles(1.0f, 0.0f, 0.0f)
{}

Application::~Application() 
{}

void Application::update()
{
	++angles.x;
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(glm::mat4(2.0f), glm::radians(angles.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, glm::radians(angles.x), glm::vec3(1.0f, 1.0f, 0.0f));
	transform = glm::perspective(45.0f, 1024.0f/758.0f, 0.1f, 10.0f) * 
				camera * transform;
	scndTransform = transform;
	scndTransform = glm::translate(scndTransform, glm::vec3(-3.0f, -1.0f, 0.1f));
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;
		case GLFW_KEY_Y:
			++angles.y; 
			break;
		}
	}
}

void Application::setup()
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");

	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	idTransform = glGetUniformLocation(triangle.shader, "transform");

	triangle.numVertex = 36;
	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);
	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(transform));

	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);

	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(scndTransform));
	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
