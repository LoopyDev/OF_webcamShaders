
// fragment shader
#version 330 core
in vec4 vColor;

// UNIFORMS
//
// texture
uniform sampler2DRect tex0;
// texture size
uniform vec2 texRes;
in vec2 varyingtexcoord;
out vec4 fragColor;

uniform float time;
uniform vec2 dir;

void main()
{   
	//Texture coordinates flipped to mirror webcam
	vec2 tc = vec2(varyingtexcoord.x, varyingtexcoord.y * -1 + texRes.y);

    vec3 almostFragColor = texture(tex0,tc).xyz;
	vec3 threstholdCol = vec3(0.5,0.5,0.5);


    if(almostFragColor.x > 0.4) 
	// &&
	// almostFragColor.y > 0.5 &&
	// almostFragColor.z > 0.5)
	{
        // fragColor = vec4(1.0,1.0,1.0,0.2);
		    // fragColor = texture(tex0,tc)*2;
					fragColor = vec4(0.0,0.0,0.0,0.0);


    }
	else
		fragColor = texture(tex0,tc);

    // else{

    // }
}