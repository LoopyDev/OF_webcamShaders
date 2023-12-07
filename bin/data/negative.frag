
// fragment shader
#version 330 core

// this is how we receive the texture
uniform sampler2DRect tex0;
in vec2 varyingtexcoord;
in vec2 v_texRes;
out vec4 outputColor;

uniform vec2 texRes;


void main()
{
    	vec2 tc = varyingtexcoord;
    tc.y = tc.y *-1 + texRes.y;

    vec3 negetiveCol = vec3(1.0,1.0,1.0) - texture(tex0, tc).rgb;
    if(tc.x > 0 && tc.x < texRes.x/5){
        outputColor = vec4(vec3(2.0, 0.6, 1.5) -  negetiveCol*1.5, 1.0);
    }
        else if(tc.x > texRes.x/5 && tc.x < 2*texRes.x/5){
            outputColor = vec4(vec3(1.5, 1.2627, 2.5157) - negetiveCol*1.5, 1.0);
    }
        else if(tc.x > 2*texRes.x/5 && tc.x < 3*texRes.x/5){
            outputColor = vec4(vec3(2.5, 1.6, 0.0) - negetiveCol*1.5, 1.0);
    }
        else if(tc.x > 3*texRes.x/5 && tc.x < 4*texRes.x/5){
            outputColor = vec4(vec3(1,1.5,0) - negetiveCol*1.2, 1.0);
    }
            if(tc.x > 4*texRes.x/5 && tc.x < 5*texRes.x/5){
            outputColor = vec4(vec3(2,1,1) - negetiveCol*1, 1.0);
    }
}