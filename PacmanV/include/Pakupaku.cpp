#include "Pakupaku.h"



Pakupaku::Pakupaku()
{
}


Pakupaku::~Pakupaku()
{
}

void Pakupaku::gAte(int mapa[31][28])
{

	int posgx = gPos.x , posgy = gPos.y, pospcx = pos.x, pospcy = pos.y;

	mapa[posgx][posgy] = 3;
	mapa[pospcx][pospcy] = 4;
	pos.x = posgx;
	pos.y = posgy;
	
}

void Pakupaku::pakuDown(int mapa[31][28])
{
	int posx, posy;
	posx = pos.x + 1;
	posy = pos.y;
	int posxAC = pos.x;
	int posyAc = pos.y;
	if (mapa[posx][posy] == 0)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if (mapa[posx][posy] == 4)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}

	else if (mapa[posx][posy] == 2)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
		superP = true;
	}
	else if (mapa[posx][posy] == 7 && superP == true)
	{
		gAte(mapa);

	}
}


void Pakupaku::pakuUp(int mapa[31][28])
{
	int posx, posy;
	posx = pos.x - 1;
	posy = pos.y;
	int posxAC = pos.x;
	int posyAc = pos.y;
	if (mapa[posx][posy] == 0)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if (mapa[posx][posy] == 4)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if (mapa[posx][posy] == 2)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
		superP = true;
	}
	else if (mapa[posx][posy] == 7 && superP == true)
	{
		gAte(mapa);

	}

}

void Pakupaku::pakuDer(int mapa[31][28])
{
	int tptoLx, tptoLy, postpRx, postpRy;
	
	tptoLx = postplft.x;
	tptoLy = postplft.y +1 ;


	//Variables de pos de paku en x y 
	int posx, posy, posyn;
	posx = pos.x;
	posy = pos.y + 1;
	posyn = pos.y;
	int posxAC = pos.x;
	int posyAc = pos.y;
	if(mapa[posx][posy] == 0)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;

	}
	if (mapa[posx][posy] == 4)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	
	if(mapa[posx][posy] == 6)
	{
		mapa[tptoLx][tptoLy] = 3;
		mapa[posx][posyn] = 4;
		pos.x = tptoLx;
		pos.y = tptoLy;
	}
	if (mapa[posx][posy] == 2)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
		superP = true;

	}

	else if (mapa[posx][posy] == 7 && superP == true)
	{
		gAte(mapa);
	}


}

void Pakupaku::pakuLeft(int mapa[31][28])
{
	int tptoRx, tptoRy;
	//Posicion del tp izq

	//Posicion del tp destino (derecho)
	tptoRx = postprght.x;
	tptoRy = postprght.y -1;

	int posx, posy;
	posx = pos.x; //pos x de paku
	posy = pos.y - 1; //lugar a la izq de paku
	int posyn = pos.y; //Posicion normal del paku

	//PosFantasma

	int posxAC = pos.x;
	int posyAc = pos.y;
	if (mapa[posx][posy] == 0)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if(mapa[posx][posy] == 4)
	{
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if (mapa[posx][posy] == 5)
	{
		mapa[tptoRx][tptoRy] = 3;
		mapa[posx][posyn] = 4;
		pos.x = tptoRx;
		pos.y = tptoRy;
		
	}
	else if (mapa[posx][posy] == 2)
	{
		superP = true;
		mapa[posx][posy] = 3;
		mapa[posxAC][posyAc] = 4;
		pos.x = posx;
		pos.y = posy;
	}
	else if(mapa[posx][posy] == 7 && superP == true)
	{
		gAte(mapa);
	}



	//mapa[postplftx][postplfty]
}



void Pakupaku::searchPaku(int mapa[31][28])
{
	for(int i = 0; i < 31; ++i)
		for(int j = 0; j < 28; ++j)
		{
			if(mapa[i][j] == 3)
			{
				pos.x = i;
				pos.y = j;
			}
		}
}

void Pakupaku::searchtpLeft(int mapa[31][28])
{
	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 28; ++j)
		{
			if (mapa[i][j] == 5)
			{
				postplft.x = i;
				postplft.y = j;
			}
		}

}

void Pakupaku::searchtpRight(int mapa[31][28])
{
	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 28; ++j)
		{
			if (mapa[i][j] == 6)
			{
				postprght.x = i;
				postprght.y = j;
			}
		}
}

void Pakupaku::makeTP()
{
	

}

void Pakupaku::searchG(int mapa[31][28])
{

	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 28; ++j)
		{
			if (mapa[i][j] == 7)
			{
				gPos.x = i;
				gPos.y = j;
			}
		}
}

	
