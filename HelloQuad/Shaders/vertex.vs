#version 430 core

	layout (location = 0) in vec4 vPosition;
	//"layout (location = 1) in vec4 vColor;

	void main()
	{
	   gl_Position = vPosition;
	}

