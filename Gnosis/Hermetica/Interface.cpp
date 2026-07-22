#include "Interface.hpp"

float x = -0.8f;

INTERFACE::INTERFACE(int Width, int Height) :
Window_W(Width), Window_H(Height),Logical_W(Width), Logical_H(Height){

	Init();
}

INTERFACE::~INTERFACE(void){}


void INTERFACE::Init(void){

if(!SDL_Init(SDL_INIT_VIDEO)){
	std::cout << "SDL_INIT_VIDEO FAILURE";
			     }

SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


SDL_CreateWindowAndRenderer(
		"Gnosis", Window_W, Window_H,
		win_flags, &Window, &Renderer
			   );

SDL_GLContext glContext = SDL_GL_CreateContext(Window);

int GL_Version = gladLoadGL((GLADloadfunc) SDL_GL_GetProcAddress);

SDL_SetRenderLogicalPresentation(Renderer, Logical_W, Logical_H,
				SDL_LOGICAL_PRESENTATION_LETTERBOX);

RunProg();
	       }

void INTERFACE::RunProg(void){

SDL_ShowWindow(Window);

Running = true;

SDL_SetRenderVSync(Renderer, 1);


keyboard_handle = SDL_GetKeyboardState(nullptr);


MagicBag.MakeShader("Crux/Perception/Vert1.shader",
		    "Crux/Perception/Frag1.shader",
		    			  "Shader1").Use();


GL_Renderer GLR;

Image Gubram("Crux/Perception/Gubram.png", true);
Image bobram("Crux/test.png", true);

GLR.Tex0 = Gubram.GL_ID;
GLR.Tex1 = bobram.GL_ID;

GLR.Init();


glUseProgram(MagicBag.FindShader("Shader1").GL_ID);
auto loc = glGetUniformLocation(MagicBag.FindShader("Shader1").GL_ID, "uniTexture");
int sampler[2] = {0, 1};
glUniform1iv(loc, 2, sampler);


Quad BestQuad(0.5f, -0.5f, 0.3f, 1.0f, 1.0f);

	glViewport(0, 0, Logical_W, Logical_H);	

while(Running){

Quad testQuad(x, -0.5f, 0.3f, 1.0f, 0.0f);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



	glClear(GL_COLOR_BUFFER_BIT);

	GLR.Push_Quad(testQuad);
//	GLR.Push_Quad(BestQuad);

//	MagicBag.FindShader("Shader1").setInt("uniTexture", 0);

	GLR.Render();

	SDL_GL_SwapWindow(Window);

	Inputs();

	      }
				 }

void INTERFACE::EndProg(void){
	Running = false;	
}

void INTERFACE::Inputs(void){

SDL_Event event{0};

while(SDL_PollEvent(&event)){

	switch(event.type){

	
	case SDL_EVENT_QUIT:{
	EndProg();
	break;
			    }

	case SDL_EVENT_WINDOW_RESIZED:{

	Logical_W = event.window.data1;
	Logical_H = event.window.data2;
	
	glViewport(0, 0, Logical_W, Logical_H);	

	break;
				      }	

	case SDL_EVENT_KEY_DOWN:{
	
	if(keyboard_handle[SDL_SCANCODE_A]){
	x -= 0.1f;
					   }
	if(keyboard_handle[SDL_SCANCODE_D]){
	x += 0.1f;
					   }
	break;
				}

			   }//event.type	

 }//whilePoll
  
}//Inputs
