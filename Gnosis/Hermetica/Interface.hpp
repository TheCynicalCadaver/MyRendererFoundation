#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "ResourceSack.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class INTERFACE{

SDL_Window* Window;
SDL_Renderer* Renderer;

SDL_WindowFlags win_flags	 = 	 SDL_WINDOW_OPENGL |
				      SDL_WINDOW_RESIZABLE |
				      SDL_WINDOW_HIGH_PIXEL_DENSITY;
			    
bool Running = false;

const bool *keyboard_handle = nullptr;

int Logical_W, Logical_H;
int Window_W, Window_H;

ResourceSack MagicBag; // temp location

	public:
INTERFACE(int Width, int Height); // Replace with Glint

void Init(void);

void Inputs(void);

void RunProg(void);

void EndProg(void);

~INTERFACE(void);

		   };
#endif
