
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

void setup()
{
	app.setup();
}

//Se ejecuta siempre que se necesite actualizar la imagen
void display()
{
	app.display();
}

//Se ejecuta cuando la ventana cambia de tama�o. Par�metros en pixeles.
//(ojo: En otros programas se debe ejecutar glViewport)
void reshape(int w, int h)
{
	app.reshape(w, h);
}

void keyboard(GLFWwindow* window, int key, int scancode, int actions, int mods)
{
	app.keyboard(key, scancode, actions, mods);
}

int main(int argc, char *argv[])
{	

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	//glfwWindowHint(GLFW_ALPHA_BITS, GLFW_TRUE);
	/* Create a windowed mode window and its OpenGL context */
	app.window = glfwCreateWindow(800, 600, "Hello Triangle", NULL, NULL);
	if (!app.window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(app.window);

	glewExperimental = GL_TRUE; 
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString (GL_RENDERER); 
	const GLubyte* version = glGetString (GL_VERSION); 
	printf (" Renderer: %s\n", renderer); 
	printf (" OpenGL version supported %s\n", version); 
	
	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glViewport(0, 0, (GLsizei)800, (GLsizei)600);

	glfwSetKeyCallback(app.window, keyboard);

	while (!glfwWindowShouldClose(app.window))
	{
		/* update other events like input handling */
		glfwPollEvents();

		app.update();

		/* put the stuff we've been drawing onto the display */
		app.display();
		
		glfwSwapBuffers(app.window);
	}
	
	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}
