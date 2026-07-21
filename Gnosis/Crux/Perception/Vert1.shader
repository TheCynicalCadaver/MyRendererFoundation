#version 430 core

layout (location = 0) in vec3 s_Pos;
layout (location = 1) in vec4 s_Color;
layout (location = 2) in vec3 TexCords; 

out vec4 PointColor;
out vec2 FragTexCords;
out float FragTexIndex;
void main(){

gl_Position = vec4(s_Pos, 1.0);

PointColor = s_Color;
FragTexCords = TexCords.xy;
FragTexIndex = TexCords.z;
	   }
