
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#include "ShaderFuncs.h"

std::vector<GLfloat> vertexPositions = {

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
	1.0f, 0.5f, 0.2f, 0.5f,
	1.0f, 0.5f, 0.2f, 0.5f,
	1.0f, 0.5f, 0.2f, 0.5f,

	1.0f, 0.5f, 0.2f, 0.5f,
	1.0f, 0.5f, 0.2f, 0.5f,
	1.0f, 0.5f, 0.2f, 0.5f,

};

int map[31][28] =
{
	
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 2, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 ,0 ,0 ,1, 1, 0, 0, 0, 0, 0, 2, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	
};


Application::Application() : eye(18.0f, -66.0f, 12.0f), 
							target (16.0f, 0.0f, 12.0f),
							transform(glm::mat4(1.0f))
						
{}

Application::~Application() 
{}

void Application::update()
{
	++angles.x;
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
	
}

void Application::keyboard(int key, int scancode, int actions, int mods)
{
	Application app;
	if (actions == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;
		case GLFW_KEY_Y:
			++angles.y;
			break;
		case GLFW_KEY_D:
			paku.pakuUp(map);
			break;
		case GLFW_KEY_W:
			paku.pakuLeft(map);
			break;
		case GLFW_KEY_S:
			paku.pakuDer(map);
			break;
		case GLFW_KEY_A: 
			paku.pakuDown(map);
			break;
		case GLFW_KEY_J:
			fPS = !fPS;
			break;
		case GLFW_KEY_E:
			editor = !editor;
			break;

		}
	}
}

//GG ISI xO2stras pedrin <3 Gracias amigo, ya pasé la materia :v jajaja ojala todos pasemos vaquero, ahuevo prro, listo amigo, te debo 10 lumen :v
//SOIL_loadimage("Puta_Que_Oferton.png"); e we, el piso :v, como le hiciste? isi boi

void Application::setup()
{

	objeto.Shaders("Shaders\\vertex.vs", "Shaders\\fragment.fs");
	objeto.setup(vertexPositions, NULL);
	
	paku.searchPaku(map);
	paku.searchtpLeft(map);
	paku.searchtpRight(map);
	paku.searchG(map);
	fPS = true;
	editor = false;
	
}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//objeto.draw(transform, glm::vec4(1.0, 0.0, 0.0, 1.0));

	//objeto.draw(glm::translate(transform, glm::vec3(2.0, 0.0, 0.0)), glm::vec4(0.0, 1.0, 1.0, 1.0));
	if (fPS)
	{

		for(int i = 0; i < 31; i++) //Generacion de objs via mapa
		{
			for(int j = 0; j< 28; ++j)
			{
				transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, j));
				transform = glm::perspective(45.0f, 1024.0f / 768.0f, 0.5f, 100.0f) *
					camera * transform;

				eye = glm::vec3(paku.pos.x, 0.0, paku.pos.y); 
				target = eye;
				target.z -= 1;

					objeto.draw(glm::translate(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)),glm::vec3(0.0f,-2.0f,0.0f)), glm::vec4(0.0, 0.5, 1.0, 0.0));
			
				if(map[i][j] == 1)
				{
					objeto.draw(glm::scale(transform,glm::vec3(0.5f,0.5f,0.5f)), glm::vec4(0.0, 0.0, 1.0, 0.0));
				}
				if(map[i][j] == 0)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.1f, 0.1f, 0.1f)), glm::vec4(1.0, 1.0, 1.0, 1.0));
				}
				if(map[i][j] == 2)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.3f, 0.3f, 0.3f)), glm::vec4(1.0, 5.0, 1.0, 1.0));
				}
				if(map[i][j] == 3)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 1.0, 0.0, 1.0));
				}
				if(map[i][j] == 4)
				{
					//objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 1.0, 1.0, 1.0));
				}
				if(map[i][j] == 5 && map[i][j] == 6)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(0.0, 0.0, 0.0, 0.0));
				}
				if(map[i][j] == 7)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 0.0, 0.0, 0.0));
				}
			}
		} 
	}
	else
	{
		for (int i = 0; i < 31; i++) //Generacion de objs via mapa
		{
			for (int j = 0; j< 28; ++j)
			{
				transform = glm::translate(glm::mat4(1.0f), glm::vec3(i, 0.0f, j));
				transform = glm::perspective(100.0f, 1024.0f / 768.0f, .1f, 100.0f) *
					camera * transform;
				eye = glm::vec3(18.0f, -66.0f, 12.0f);
				target = glm::vec3(16.0f, 0.0f, 12.0f);

				objeto.draw(glm::translate(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec3(0.0f, 2.0f, 0.0f)), glm::vec4(0.0, 0.5, 1.0, 0.0));
				if (map[i][j] == 1) //Pared
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.5f, 0.5f, 0.5f)), glm::vec4(0.0, 0.0, 1.0, 0.0));
				}
				if (map[i][j] == 0) //Pildoras
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.1f, 0.1f, 0.1f)), glm::vec4(1.0, 1.0, 1.0, 1.0));
				}
				if (map[i][j] == 2) //Pildoras bergas
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.3f, 0.3f, 0.3f)), glm::vec4(1.0, 5.0, 1.0, 1.0));
				}
				if (map[i][j] == 3) //erue 
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 1.0, 0.0, 1.0));
				}
				if (map[i][j] == 4)//cubos vacios 
				{
					//objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 1.0, 1.0, 1.0));
				}
				if (map[i][j] == 5 && map[i][j] == 6) //Teleports
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(0.0, 0.0, 0.0, 0.0));
				}
				if (map[i][j] == 7)
				{
					objeto.draw(glm::scale(transform, glm::vec3(0.4f, 0.4f, 0.4f)), glm::vec4(1.0, 0.0, 0.0, 0.0));
				}
			}
		}
		if (editor)
		{
			int x, y;
			std::cout << "Ingresa la posicion que quieres cambiar";
			std::cin >> x >> y;

			if (map[x][y] == 1)
			{
				map[x][y] = 0;
			}
			else if (map[x][y] == 0 || map[x][y] == 4)
			{
				map[x][y] = 1;
			}
			editor = false;
		}
	}
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

