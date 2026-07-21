//OpenGL Abstractions (Gave a themed name cause thats how I roll)
#include "OpenGospeL.hpp"

Shader::Shader(){}

Shader& Shader::Use(void){
glUseProgram(GL_ID);

return *this;

}

void Shader::Compile(const char* VertShader, const char* FragShader){

	GLuint Vertex, Frag;

	Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Vertex, 1, &VertShader, NULL);
	glCompileShader(Vertex);

	Frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(Frag, 1, &FragShader, NULL);
	glCompileShader(Frag);

	GL_ID = glCreateProgram();

	glAttachShader(GL_ID, Vertex);
	glAttachShader(GL_ID, Frag);

	glLinkProgram(GL_ID);

	glDeleteShader(Vertex);
	glDeleteShader(Frag);
	
	std::cout << FragShader << std::endl;
}


Quad::Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLfloat TexID){

Verts[0].Position = {x, y, z};
Verts[0].Color = {1.0f, 1.0f, 1.0f, 1.0f};
Verts[0].TextureCords = {0.0f, 0.0f };
Verts[0].TextureID = TexID;

Verts[1].Position = {x + size, y, z};
Verts[1].Color = {0.0f, 0.0f, 0.4f , 1.0f };
Verts[1].TextureCords = {1.0f, 0.0f };
Verts[1].TextureID = TexID;

Verts[2].Position = {x + size, y + size, z};
Verts[2].Color = {0.0f, 0.4f, 0.0f , 1.0f };
Verts[2].TextureCords = { 1.0f, 1.0f};
Verts[2].TextureID = TexID;

Verts[3].Position = {x, y + size, z};
Verts[3].Color = {0.4f, 0.0f, 0.0f, 1.0f};
Verts[3].TextureCords = { 0.0f, 1.0f};
Verts[3].TextureID = TexID;
}

Quad::Quad(glm::vec3 XYZ, glm::vec3 Col, GLfloat size, GLfloat TexID){

}

void Shader::setInt(const char* name, GLint value, bool useShader){
if(useShader){ this->Use(); }
glUniform1i(glGetUniformLocation(GL_ID, name), value);
						  }

void GL_Renderer::Init(void){


glGenVertexArrays(1, &VAO);

glGenBuffers(1, &VBO);

glBindVertexArray(VAO);

glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * MaxVerts, nullptr, GL_DYNAMIC_DRAW);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (void*)0);
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (void*)(4 * sizeof(GLfloat)));
glEnableVertexAttribArray(1);

glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(GLfloat), (void*)(7 * sizeof(GLfloat))); //TexCords & ID
glEnableVertexAttribArray(2);


 GLuint Indices[MaxIndices];

for(size_t i = 0; i < MaxIndices; i += 6){

	Indices[i + 0] = 0 + offset;
	Indices[i + 1] = 1 + offset;
	Indices[i + 2] = 2 + offset;

	Indices[i + 3] = 2 + offset;
	Indices[i + 4] = 3 + offset;
	Indices[i + 5] = 0 + offset;

	offset += 4;
					 }
glCreateBuffers(1, &IBO);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

}


void GL_Renderer::Push_Quad(Quad& Q){

	for(int i = 0; i < Q.Verts.size(); i++){
	Vertices.push_back(Q.Verts[i].Position.x);
	Vertices.push_back(Q.Verts[i].Position.y);
	Vertices.push_back(Q.Verts[i].Position.z);

	Vertices.push_back(Q.Verts[i].Color.x);
	Vertices.push_back(Q.Verts[i].Color.y);
	Vertices.push_back(Q.Verts[i].Color.z);
	Vertices.push_back(Q.Verts[i].Color.w);

	Vertices.push_back(Q.Verts[i].TextureCords.x);
	Vertices.push_back(Q.Verts[i].TextureCords.y);

	Vertices.push_back(Q.Verts[i].TextureID);

					      }
	IndicesCount += 6;
}


void GL_Renderer::Render(void){

glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferSubData(GL_ARRAY_BUFFER, 0, Vertices.size() * sizeof(GLfloat), Vertices.data());

glBindTextureUnit(0, Tex0);
glBindTextureUnit(1, Tex1);

glBindVertexArray(VAO);
glDrawElements(GL_TRIANGLES, IndicesCount, GL_UNSIGNED_INT, (void*)0);	

IndicesCount = 0;
Vertices.clear();
			      }
