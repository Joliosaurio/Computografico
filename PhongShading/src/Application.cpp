
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ShaderFuncs.h"

Application::Application():oPlane() {
	eye = glm::vec3(0.0f, 50.0f, 100.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	time = 0;
	myLightPosition = glm::vec3(0.0f, 50.0f, -100.0f);
	la = glm::vec3(0.5f);
	ld = glm::vec3(1.0f);
	ls= glm::vec3(1.0f);
	ma = glm::vec3(0.5f);
	md = glm::vec3(1.0f);
	ms = glm::vec3(0.5f);
}

Application::~Application() {}

void Application::update(){
	time += 5.0;
}

void Application::setup(){
	oPlane.createPlane(10);


	std::string strVertexShader = loadTextFile("Shaders/PhongShading.v");
	std::string strFragmentShader = loadTextFile("Shaders/PhongShading.f");
	InitializeProgram(oPlane.shader, strVertexShader, strFragmentShader);

	mTransformID = glGetUniformLocation(oPlane.shader, "mTransform");
	cameraID = glGetUniformLocation(oPlane.shader, "camera");
	perspectiveID = glGetUniformLocation(oPlane.shader, "perspective");

	fTimeID = glGetUniformLocation(oPlane.shader, "fTime");
	eyeID = glGetUniformLocation(oPlane.shader, "vEye");
	myLightPositionID = glGetUniformLocation(oPlane.shader, "myLightPosition");

	laID = glGetUniformLocation(oPlane.shader, "LA");
	lsID = glGetUniformLocation(oPlane.shader, "LS");
	ldID = glGetUniformLocation(oPlane.shader, "LD");
	maID = glGetUniformLocation(oPlane.shader, "MA");
	mdID = glGetUniformLocation(oPlane.shader, "MD");
	msID = glGetUniformLocation(oPlane.shader, "MS");

	glGenVertexArrays(1, &oPlane.vao);
	glBindVertexArray(oPlane.vao);
	glGenBuffers(1, &oPlane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, oPlane.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes() + oPlane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, oPlane.getVertexSizeInBytes(), oPlane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes(), oPlane.getTextureCoordsSizeInBytes(), oPlane.textureCoords);
	oPlane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(oPlane.getVertexSizeInBytes-

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnable(GL_DEPTH_TEST);
}

void Application::display() {
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//Seleccionamos los shaders a usar
	glUseProgram(oPlane.shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(oPlane.vao);
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(45.0f, 640.0f / 480.0f, 0.1f, 200.0f);
	transform = glm::mat4(1.0f);

	//transformaciones del modelo
	glUniformMatrix4fv(mTransformID, 1, false, glm::value_ptr(transform));

	//transformacion de camara
	glUniformMatrix4fv(cameraID, 1, false, glm::value_ptr(lookAt));

	//transformacion de proyeccion
	glUniformMatrix4fv(perspectiveID, 1, false, glm::value_ptr(perspective));

	//parametro de fase para shaders
	glUniform1f(fTimeID, glm::radians(time));
	glUniform3fv(eyeID, 1, glm::value_ptr(eye));
	glm::vec3 newLight = myLightPosition;
	newLight.z = myLightPosition.z * cos(glm::radians(time));
	glUniform3fv(myLightPositionID, 1, glm::value_ptr(newLight));

	glUniform3fv(laID, 1, glm::value_ptr(la));
	glUniform3fv(ldID, 1, glm::value_ptr(ld));
	glUniform3fv(lsID, 1, glm::value_ptr(ls));
	glUniform3fv(maID, 1, glm::value_ptr(ma));
	glUniform3fv(mdID, 1, glm::value_ptr(md));
	glUniform3fv(msID, 1, glm::value_ptr(ms));

	//glUniform3fv(oPlane.uEye, 1, glm::value_ptr(eye));
	glDrawArrays(GL_TRIANGLES, 0, oPlane.getNumVertex());
}

void Application::reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::keyboard(int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		exit(0);
	}
	else if(key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		ls += glm::vec3(1.0);
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		ld += glm::vec3(1.0);
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		la += glm::vec3(1.0);
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		ma += glm::vec3(1.0);
	}
	else if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{
		md += glm::vec3(1.0);
	}
	else if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		ls += glm::vec3(1.0);
	}
	else if(key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		la = glm::vec3(0.2, 0.2, 0.2);
		ls = glm::vec3(1.0, 1.0, 1.0);
		ld = glm::vec3(0.4, 0.4, 0.4);
		ma = glm::vec3(1.0, 0.5, 0.0);
		md = glm::vec3(1.0, 1.0, 1.0);
		ms = glm::vec3(1.0, 0.5, 0.0);
	}

	if (action == GLFW_RELEASE) {
		return;
	}
}
