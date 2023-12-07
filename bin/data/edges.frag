
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
    vec3 negetiveCol = vec3(1.0,1.0,1.0) - texture(tex0, varyingtexcoord).rgb;
    if(varyingtexcoord.x > 0 && varyingtexcoord.x < texRes.x/5){
        outputColor = vec4(vec3(2.0, 0.6, 1.5) -  negetiveCol*1.5, 1.0);
    }
        else if(varyingtexcoord.x > texRes.x/5 && varyingtexcoord.x < 2*texRes.x/5){
            outputColor = vec4(vec3(1.5, 1.2627, 2.5157) - negetiveCol*1.5, 1.0);
    }
        else if(varyingtexcoord.x > 2*texRes.x/5 && varyingtexcoord.x < 3*texRes.x/5){
            outputColor = vec4(vec3(2.5, 1.6, 0.0) - negetiveCol*1.5, 1.0);
    }
        else if(varyingtexcoord.x > 3*texRes.x/5 && varyingtexcoord.x < 4*texRes.x/5){
            outputColor = vec4(vec3(1,1.5,0) - negetiveCol*1.2, 1.0);
    }
            if(varyingtexcoord.x > 4*texRes.x/5 && varyingtexcoord.x < 5*texRes.x/5){
            outputColor = vec4(vec3(2,1,1) - negetiveCol*1, 1.0);
    }
}