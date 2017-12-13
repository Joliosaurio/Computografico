#pragma once

#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ShaderFuncs.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#pragma comment(lib, "glu32")


class Object3D {
public:
	GLuint	vao, //Vertex Array Object
		vbo; //Vertex Buffer Object

	GLuint transformID, colorID;

	int numVertex; //numero de vertices para este objeto

	GLuint shader; //referencia a los shaders

	void setup(std::vector<GLfloat> vertex, std::vector<GLint> * index);
	void draw(glm::mat4 transform, glm::vec4 color);
	void Shaders(std::string vS, std::string fS);

	//Object3D();

};

