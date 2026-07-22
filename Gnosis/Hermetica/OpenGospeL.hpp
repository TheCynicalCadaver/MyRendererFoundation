#ifndef OPEN_GOSPEL_HPP
#define OPEN_GOSPEL_HPP
//OpenGL Abstractions (Gave a themed name cause thats how I roll)

#include "TextureSeer.hpp"



struct Shader{

GLuint GL_ID;


Shader(void);

void Compile(const char* VertShader, const char* FragShader);

Shader& Use(void);

void setInt(const char* name, GLint value, bool useShader = false);

	    };


struct Vertex{
glm::vec3 Position;
glm::vec4 Color;
glm::vec2 TextureCords;
GLfloat TextureID;
GLfloat mixRatio;
	     };


struct Quad{

std::array<Vertex, 4> Verts;

Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLfloat TexID, GLfloat MixRatio);
Quad(glm::vec3 XYZ, glm::vec3 Col, GLfloat size, GLfloat TexID);

Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat W, GLfloat H, GLfloat TexID, GLfloat MixRatio);
	   };	


class GL_Renderer{

std::vector<GLfloat> Vertices;

GLuint VAO;
GLuint IBO;
GLuint VBO;

GLuint offset = 0;

static const size_t MaxQuads = 1000;
static const size_t MaxVerts = MaxQuads * 4;
static const size_t MaxIndices = MaxQuads * 6;

GLuint IndicesCount = 0;

	public:

GLuint Tex0, Tex1;

void Init(void);

void Push_Quad(Quad& Q);

void Render(void);

		 };

#endif

