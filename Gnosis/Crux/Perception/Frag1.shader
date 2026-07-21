#version 430 core
out vec4 FragColor;

in vec4 PointColor;
in vec2 FragTexCords;

in float FragTexIndex;

uniform sampler2D uniTexture[2];

void main(){

int index = int(FragTexIndex);

FragColor = texture(uniTexture[index], FragTexCords);
	   }
