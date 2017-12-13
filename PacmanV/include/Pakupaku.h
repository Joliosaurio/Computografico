#pragma once
#include <iostream>
#include "Object3D.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include "Fanstasma.h"
class Pakupaku
{
public:
	Pakupaku();
	~Pakupaku();

	void gAte(int mapa[31][28]);
	
	void pakuDer(int mapa[31][28]);
	void pakuUp(int mapa[31][28]);
	void pakuDown(int mapa[31][28]);
	void pakuLeft(int mapa[31][28]);
	void searchPaku(int mapa[31][28]);
	glm::vec2 pos;


	void searchtpLeft(int mapa[31][28]);
	void searchtpRight(int mapa[31][28]);
	void makeTP();

	glm::vec2 postplft;
	glm::vec2 postprght;

	void searchG(int mapa[31][28]);
	glm::vec2 gPos;

private:
	bool superP = false;

};

