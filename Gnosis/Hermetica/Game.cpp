#include "Game.hpp"

void Game::Init(GL_Renderer& glr){

Image Gubram("Crux/Gubram.png", true);
Image bobram("Crux/test.png", true);

glr.Tex0 = Gubram.GL_ID;
glr.Tex1 = bobram.GL_ID;

glr.Init();

				}

Game::Game(GL_Renderer& glr){

	this->Init(glr);

			    }
